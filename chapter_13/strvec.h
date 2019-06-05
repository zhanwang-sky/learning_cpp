#ifndef _STRVEC_H
#define _STRVEC_H

#include <string>
#include <memory>

class StrVec {
public:
    typedef std::size_t size_type;
    StrVec();
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();
    void push_back(const std::string&);
    size_type size() const { return first_free - elements; }
    size_type capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    void reserve(size_type);
    void resize(size_type);
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*>
        alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate(size_type);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif // _STRVEC_H
