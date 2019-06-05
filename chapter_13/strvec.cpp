#include <utility>
#include "strvec.h"

// test
#include <iostream>
using std::cout;
using std::endl;

// static members
std::allocator<std::string> StrVec::alloc;

// Public methods
StrVec::StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {
    cout << "StrVec::default constructor" << endl;
}

StrVec::StrVec(const StrVec &s) {
    cout << "StrVec::copy constructor" << endl;
    auto newdata = alloc_n_copy(s.elements, s.first_free);
    elements = newdata.first;
    cap = first_free = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept:
    elements(s.elements), first_free(s.first_free), cap(s.cap) {
    cout << "StrVec::move constructor" << endl;
    s.cap = s.first_free = s.elements = nullptr;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    cout << "StrVec::copy assignment operator" << endl;
    auto data = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = data.first;
    cap = first_free = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    cout << "StrVec::move assignment operator" << endl;
    if (elements != rhs.elements) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.cap = rhs.first_free = rhs.elements = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    cout << "StrVec::destructor" << endl;
    free();
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_type n) {
    if (cap <= (elements + n)) {
        reallocate(n);
    }
}

void StrVec::resize(size_type n) {
    reallocate(n);
}

// Private methods
inline void StrVec::chk_n_alloc() {
    if (first_free == cap)
        reallocate((cap != elements) ? 2 * (cap - elements) : 1);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto const ele = alloc.allocate(e - b);
    auto ff = ele;
    for (auto p = b; p != e; ++p) {
        alloc.construct(ff++, *p);
    }
    return { ele, ff };
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
        elements = first_free = cap = nullptr;
    }
}

void StrVec::reallocate(size_type n) {
    auto newele = alloc.allocate(n);
    auto src = elements;
    auto dst = newele;
    for (size_type i = 0; i < n && src != first_free; i++) {
        alloc.construct(dst++, std::move(*src++));
    }
    free();
    elements = newele;
    first_free = dst;
    cap = elements + n;
}
