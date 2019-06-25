#include <memory>
#include <vector>

template <typename T> class Blob {
public:
    typedef T value_type; // ?
    typedef typename std::vector<T>::size_type size_type;
    Blob(): data(std::make_shared<std::vector<T>>()) { }
    Blob(const std::initializer_list<T> &il):
        data(std::make_shared<std::vector<T>>(il)) { }
    Blob(const Blob &b) = default;
    size_type size() const { return data->size(); }
    bool empty() const { return data-empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back(); // check
    T& back(); // check
    T& operator[](size_type); // check
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type, const std::string&) const;
};
