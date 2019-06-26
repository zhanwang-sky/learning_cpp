#ifndef _BLOB_H
#define _BLOB_H

#include <memory>
#include <vector>

template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob(): data(std::make_shared<std::vector<T>>()) { }
    Blob(const std::initializer_list<T> &il):
        data(std::make_shared<std::vector<T>>(il)) { }
    /*
    Blob(const Blob&);
    Blob(Blob&&);
    Blob& operator=(const Blob&);
    Blob& operator=(Blob&&);
    */
    virtual ~Blob() = default;

    size_type size() const noexcept { return data->size(); }
    bool empty() const noexcept { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back(); // check
    T& front(); // check
    T& front() const; // check
    T& back(); // check
    T& back() const; // check
    T& at(size_type); // check
    T& at(size_type) const; // check
    T& operator[](size_type i) { return (*data)[i]; }
    T& operator[](size_type i) const { return (*data)[i]; }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &errMsg) const {
        if (i >= data->size()) {
            throw std::out_of_range(errMsg);
        }
    }
};

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
T& Blob<T>::front() {
    check(0, "back on empty Blob");
    return data->front();
}

template<typename T>
T& Blob<T>::front() const {
    check(0, "back on empty Blob");
    return data->front();
}

template<typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::at(size_type i) {
    check(i, "index out of range");
    return (*data)[i];
}

template<typename T>
T& Blob<T>::at(size_type i) const {
    check(i, "index out of range");
    return (*data)[i];
}

#endif // _BLOB_H
