#include <string>
#include <vector>
#include <memory>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il):
        data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add/remove element
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // access elements
    std::string& front();
    std::string& front() const;
    std::string& back();
    std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
