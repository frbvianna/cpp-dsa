#include "Array.hpp"

template <typename T>
Array<T>::Array(T a[], size_t sz) 
    : arr{new T[sz]}, sz{sz} {
    for (size_t i {0}; i < sz; ++i) {
        arr[i] = a[i];
    }
};

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
void Array<T>::print() {
    std::cout << "=== [ ";
    for (size_t i {0}; i < sz; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << "\n";
}

template <typename T>
size_t Array<T>::size() {
    return sz;
}
