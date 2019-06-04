#ifndef _HASPTR_H
#define _HASPTR_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string());
    HasPtr(const HasPtr &orig);
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

#endif // _HASPTR_H
