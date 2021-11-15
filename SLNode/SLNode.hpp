#pragma once

template <typename T>
class SLNode {
private:
    T *data_;
    SLNode *next_;
public:
    SLNode()
    : data_{new T}, next_{nullptr} {};

    SLNode(const T *data, SLNode *next = nullptr) {
        data_ = new T;
        *data_ = *data;
        next_ = next;
    }

    ~SLNode() {
        delete data_;
    };

    T* getData() {
        return data_;
    }

    void setNext(SLNode *next) {
        next_ = next;
    }

    SLNode* getNext() {
        return next_;
    }

    void print(size_t num) {
        std::cout << "=== Data " << num << ": " << 
            *data_ << std::endl;
    }
};