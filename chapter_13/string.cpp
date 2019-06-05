#include <string.h>
#include "string.h"

// test
#include <iostream>
using std::cout;
using std::endl;

#define _BLOCK_SZ (512)

// Public methods
String::String() {
    cout << "String::default constructor" << endl;
}

String::String(const char *pc) {
    cout << "String::constructor(char*)" << endl;
    size_t len = strlen(pc);
    auto newdata = alloc_n_copy(pc, pc + len);
    head = newdata.first;
    curr = head + len;
    tail = newdata.second;
}

String::String(const String &s) {
    cout << "String::copy constructor" << endl;
    auto newdata = alloc_n_copy(s.head, s.curr);
    head = newdata.first;
    curr = head + s.size();
    tail = newdata.second;
}

String::String(String &&s) noexcept:
    head(s.head), curr(s.curr), tail(s.tail) {
    cout << "String::move constructor" << endl;
    s.tail = s.curr = s.head = nullptr;
}

String& String::operator=(const String &rhs) {
    cout << "String::copy assignment operator" << endl;
    if (head != rhs.head) {
        auto newdata = alloc_n_copy(rhs.head, rhs.curr);
        free();
        head = newdata.first;
        curr = head + rhs.size();
        tail = newdata.second;
    }
    return *this;
}

String& String::operator=(String &&rhs) noexcept {
    cout << "String::move assignment operator" << endl;
    if (head != rhs.head) {
        free();
        head = rhs.head;
        curr = rhs.curr;
        tail = rhs.tail;
        rhs.tail = rhs.curr = rhs.head = nullptr;
    }
    return *this;
}

String::~String() {
    cout << "String::destructor" << endl;
    String::free();
}

// Private methods
std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
    size_t len = e - b;
    size_t nr_blocks = (len / _BLOCK_SZ) + 1;
    size_t sz = nr_blocks * _BLOCK_SZ;
    auto newhead = new char[sz]();
    if (len > 0) {
        memcpy(newhead, b, len);
    }
    return { newhead, newhead + sz };
}

void String::chk_n_alloc(size_t n) {
    if (tail <= (curr + n)) {
        reallocate(tail - curr + n);
    }
}

void String::free() {
    if (head) {
        delete []head;
        tail = curr = head = nullptr;
    }
}

void String::reallocate(size_t n) {
    size_t nr_blocks = (n / _BLOCK_SZ) + 1;
    size_t newsz = nr_blocks * _BLOCK_SZ;
    size_t minlen = (curr < (head + n)) ? (curr - head) : n;
    auto newhead = new char[newsz]();
    if (minlen > 0) {
        memcpy(newhead, head, minlen);
    }
    free();
    head = newhead;
    curr = newhead + minlen;
    tail = newhead + newsz;
}
