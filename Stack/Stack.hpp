#pragma once

#include <iostream>
#include "../SinglyLinkedList/SinglyLinkedList.hpp"

template <typename T>
class Stack : public SinglyLinkedList<T> {
public:
    Stack() :
    SinglyLinkedList<T>() {};
    ~Stack() = default;

    T* top() {
        return SinglyLinkedList<T>::getEnd()->getData();
    }

    bool isEmpty() {
        return SinglyLinkedList<T>::size() == 0;
    }

    void push(const T &data) {
        SinglyLinkedList<T>::insert(data, SinglyLinkedList<T>::size());
    }

    void pop() {
        if ( !isEmpty() ) {
            SinglyLinkedList<T>::removeLast(); // should be remove(size()-1)
        }
    }
};