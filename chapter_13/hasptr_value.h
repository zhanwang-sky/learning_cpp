#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        _ps(new std::string(s)), _i(0) { }
    HasPtr(const HasPtr &orig):
        _ps(new std::string(*orig._ps)), _i(orig._i) { }
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr() { delete _ps; }
    const std::string* data() { return _ps; }
private:
    std::string *_ps;
    int _i;
};
