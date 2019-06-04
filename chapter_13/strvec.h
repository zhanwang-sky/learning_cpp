#ifndef _STRVEC_H
#define _STRVEC_H

#include <memory>

class StrVec {
public:
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*>
        alloc_n_copy(std::string*, std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif // _STRVEC_H
