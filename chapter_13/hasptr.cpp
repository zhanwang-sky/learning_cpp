#include <iostream>
#include <memory>
#include "hasptr.h"

using std::cout;
using std::endl;

HasPtr::HasPtr(const std::string &s):
    ps(new std::string(s)), i(0), use(new std::size_t(1)) {
    cout << "default constructor" << endl;
}

HasPtr::HasPtr(const HasPtr &orig):
    ps(orig.ps), i(orig.i), use(orig.use) {
    cout << "copy constructor" << endl;
    ++*use;
}

HasPtr&
HasPtr::operator=(const HasPtr &rhs) {
    cout << "copy assignment operator" << endl;
    ++*rhs.use;
    if (--*use == 0) {
        cout << "delete old" << endl;
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr() {
    cout << "destructor" << endl;
    if (--*use == 0) {
        cout << "delete" << endl;
        delete ps;
        delete use;
    }
}
