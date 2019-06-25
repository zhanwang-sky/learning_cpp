#ifndef _UTIL_H
#define _UTIL_H

#include <ostream>

namespace util {

    template<typename T>
    int compare(const T &v1, const T &v2) {
        if (v1 < v2) { return -1; }
        else if (v2 < v1) { return 1; }
        else { return 0; }
    }

    template<typename InputIt, typename T>
    InputIt find(InputIt first, InputIt last, const T &value) {
        for (; first != last; ++first) {
            if (*first == value) {
                break;
            }
        }
        return first;
    }

    template<typename T>
    void print_array1(const T &arr) {
        for (auto i : arr) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    template<typename T, unsigned N>
    void print_array2(const T (&arr)[N]) {
        for (auto i : arr) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    template<typename T, unsigned N>
    void print_array3(const T (*arr)[N]) {
        for (auto i : *arr) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    template<class T, std::size_t N>
    constexpr T* begin(T (&arr)[N]) noexcept { return (T*) &arr; }

    template<class T, std::size_t N>
    constexpr T* end(T (&arr)[N]) noexcept { return ((T*) &arr) + N; }

    template<typename C>
    inline auto get_size(const C &c) -> decltype(c.size()) { return c.size(); }

    template<class T, std::size_t N>
    constexpr std::size_t size_of(const T (&arr)[N]) noexcept { return sizeof(arr); }

}; // namespace util

#endif // _UTIL_H
