#include "hasptr_shared.h"

HasPtr&
HasPtr::operator=(const HasPtr &rhs) {
    // in case of self assignment
    *rhs._use += 1;
    *_use -= 1;
    if (*_use == 0) {
        delete _ps;
        delete _use;
    }
    _ps = rhs._ps;
    _i = rhs._i;
    _use = rhs._use;
    return *this;
}

HasPtr::~HasPtr() {
    *_use -= 1;
    if (*_use == 0) {
        delete _ps;
        delete _use;
    }
}
