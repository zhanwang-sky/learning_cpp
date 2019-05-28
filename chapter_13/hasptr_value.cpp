#include <iostream>
#include "hasptr_value.h"

HasPtr&
HasPtr::operator=(const HasPtr &rhs) {
    auto tmp_ps = new std::string(*rhs._ps);
    delete _ps;
    _ps = tmp_ps;
    _i = rhs._i;
    return *this;
}
