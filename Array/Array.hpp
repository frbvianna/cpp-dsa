#ifndef __ARRAY__H__
#define __ARRAY__H__

#include <iostream>

template<typename T>
class Array {
protected:
    T *arr;
    size_t sz;
public:
    Array(T a[], size_t sz);
    ~Array();

    void print();
    size_t size();
};

#include "Array.tpp"

#endif  //!__ARRAY__H__