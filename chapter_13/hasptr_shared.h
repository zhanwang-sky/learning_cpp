#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        _ps(new std::string(s)), _i(0), _use(new std::size_t(1)) { }
    HasPtr(const HasPtr &orig):
        _ps(orig._ps), _i(orig._i) , _use(orig._use)
        { *_use += 1; }
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr();
    const std::string* data() { return _ps; }
private:
    std::string *_ps;
    int _i;
    std::size_t *_use;
};
