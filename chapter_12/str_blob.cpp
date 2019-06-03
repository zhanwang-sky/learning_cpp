#include <stdexcept>
#include "str_blob.h"

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

void StrBlob::pop_back() {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}


void StrBlob::pop_back() const {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::at(size_type i) {
    check(i, "out of range");
    return (*data)[i];
}

std::string& StrBlob::at(size_type i) const {
    check(i, "out of range");
    return (*data)[i];
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(StrBlob::size_type i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
