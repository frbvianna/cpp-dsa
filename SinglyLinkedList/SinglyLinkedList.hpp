#pragma once

#include <iostream>
#include <string>
#include "../SLNode/SLNode.hpp"

template <typename T>
class SinglyLinkedList {
private:
    SLNode<T> *begin_, *end_;
    size_t size_;
public:
    SinglyLinkedList() {
        begin_ = nullptr;
        end_ = nullptr;
        size_ = 0;
    }
    ~SinglyLinkedList() {
        SLNode<T> *node = begin_;
        SLNode<T> *tmpNode = nullptr;
        while ( node != nullptr ) {
            tmpNode = node->getNext();
            delete node;
            node = tmpNode;
        }
    }

    SLNode<T>* getBegin() { return begin_; } 
    SLNode<T>* getEnd() { return end_; }    
    void setBegin(SLNode<T>* begin) { begin_ = begin; } 
    void setEnd(SLNode<T>* end) { end_ = end; }

    size_t size() { return size_; }

    SLNode<T>* getNode(size_t pos) {
        if ( pos < 0 || pos >= size() ) {
            std::string npos {"position invalid"};
            throw npos;
        }

        SLNode<T> *node {begin_};
        for (size_t i {0}; i < pos; ++i) {
            node = node->getNext();
        }

        return node;
    }

    void insert(const T &data, size_t pos) {
        SLNode<T> *node {new SLNode<T>{&data}}, 
                  *tmpNode {nullptr};

        if ( pos == 0 ) {
            if ( size() == 0 ) {
                setBegin(node);
                setEnd(node);
            } else {
                tmpNode = getBegin();
                setBegin(node);
                node->setNext(tmpNode);
            }
        
        } else if ( pos == size() ) {
            getEnd()->setNext(node);
            setEnd(node);
        
        } else {
            try {
                tmpNode = getNode(pos-1);
            }
            catch (const std::string &e) {
                delete node;
                throw e;
            } 

            SLNode<T> *nextNode {tmpNode->getNext()};
            
            tmpNode->setNext(node);
            node->setNext(nextNode);
        }
        size_++;
    }

    void removeLast() {
        delete getEnd();
        SLNode<T> *tmpNode {nullptr};
        tmpNode = getNode(size()-2);
        tmpNode->setNext(nullptr);
        setEnd(tmpNode);
    }

    void print() {
        SLNode<T> *node {begin_};
        size_t i {0};
        while ( node != nullptr ) {
            node->print(++i);
            node = node->getNext();
        }
    }

};