#ifndef _STR_BLOB_H
#define _STR_BLOB_H

#include <string>
#include <vector>
#include <memory>

class StrBlobPtr;

class StrBlob {
friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il):
        data(std::make_shared<std::vector<std::string>>(il)) { }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    StrBlobPtr begin();
    StrBlobPtr end();
    // add/remove element
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    void pop_back() const;
    // access elements
    std::string& at(size_type);
    std::string& at(size_type) const;
    std::string& front();
    std::string& front() const;
    std::string& back();
    std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type, const std::string&) const;
};

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(const StrBlob &b, StrBlob::size_type sz = 0):
        wptr(b.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(StrBlob::size_type, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::size_type curr;
};

#endif // _STR_BLOB_H
