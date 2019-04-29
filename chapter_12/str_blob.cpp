#include <stdexcept>
#include "str_blob.h"

using namespace std;

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back() {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
