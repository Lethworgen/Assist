#pragma once

template<class T>
class Node {
protected:
    Node<T> *next;
    T data;

public:

    Node(T item) {
        data = item;
        next = nullptr;
    }

    //data and next Getters
    Node<T> *getNext() {
        return next;
    }

    T getData() {
        return data;
    }

    //data and next setters
    void setNextPtr(Node<T> *ptr) {
        next = ptr;
    }

    void setData(T item) {
        data = item;
    }
};

