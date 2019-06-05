#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <memory>
#include <utility>

class String {
public:
    String();
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    ~String();
    size_t size() const { return curr - head; }
    char* c_str() const { return head; }
private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void chk_n_alloc(size_t);
    void free();
    void reallocate(size_t);
    char *head = nullptr;
    char *curr = nullptr;
    char *tail = nullptr;
};

#endif // _MY_STRING_H
