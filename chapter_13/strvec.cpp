#include "strvec.h"

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(std::string *b, std::string *e) {
    auto data = alloc.allocate(e - b);
    return { data, alloc.uninitialized_copy(b, e, data) }; // 指针当迭代器用？
}

void StrVec::chk_n_alloc() {
    if (cap > first_free)
        return;
}
