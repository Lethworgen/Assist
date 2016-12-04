#pragma once

#include <iostream>
#include "BSTNode.h"
#include "SinglyLinkedList.h"
#include "Queue.h"

template<class T>
class BST {
private:
    int count;

    BSTNode<T> *root;

    BSTNode<T> *insert(T item, BSTNode<T> *t);

    void postorder(BSTNode<T> *t, Queue<T> *result);

    BSTNode<T> *remove(T item, BSTNode<T> *t);

    BSTNode<T> *findMin(BSTNode<T> *t);

    BSTNode<T> *findMax(BSTNode<T> *t);

public:
    BST();

    ~BST();

    void insert(T item);

    void remove(T item);

    Queue<T> *postorder();

    Queue<T> *breadthfirst();

    int getNumberOfItems();

};

template<class T>
BST<T>::BST() {
    root = nullptr;
    count = 0;
}

template<class T>
void BST<T>::insert(T item) {
    root = insert(item, root);
    count++;
};

template<class T>
BSTNode<T> *BST<T>::insert(T item, BSTNode<T> *t) {
    if (t == nullptr) {
        t = new BSTNode<T>(item);
        t->setLeft(nullptr);
        t->setRight(nullptr);
    } else if (item < t->getData()) {
        t->setLeft(insert(item, t->getLeft()));
    } else if (item > t->getData()) {
        t->setRight(insert(item, t->getRight()));
    }
    return t;
}

template<class T>
void BST<T>::postorder(BSTNode<T> *t, Queue<T> *result) {
    if (t == nullptr) {
        return;
    }
    postorder(t->getLeft(), result);
    postorder(t->getRight(), result);
    result->enqueue(t->getData());
};

template<class T>
BST<T>::~BST() {
}

template<class T>
void BST<T>::remove(T item) {
    root = remove(item, root);
    count--;
}

template<class T>
BSTNode<T> *BST<T>::remove(T item, BSTNode<T> *t) {
    BSTNode<T> *tmp = nullptr;
    if (t == nullptr) {
        return nullptr;
    } else if (item < t->getData()) {
        t->setLeft(remove(item, t->getLeft()));
    } else if (item > t->getData()) {
        t->setRight(remove(item, t->getRight()));
    } else if (t->getLeft() && t->getRight()) {
        tmp = findMax(t->getLeft());
        t->setData(tmp->getData());
        t->setLeft(remove(t->getData(), t->getLeft()));
    } else {
        tmp = t;
        if (t->getLeft() == nullptr) {
            t = t->getRight();
        } else if (t->getRight() == nullptr) {
            t = t->getLeft();
        }
        delete tmp;
    }
    return t;
}

template<class T>
Queue<T> *BST<T>::breadthfirst() {
    Queue<BSTNode<T> *> *queue = new Queue<BSTNode<T> *>();
    Queue<T> *result = new Queue<T>();
    queue->enqueue(root);

    while (!queue->isEmpty()) {
        BSTNode<T> *node = queue->peekFront();
        result->enqueue(node->getData());
        queue->dequeue();

        if (node->getLeft() != nullptr) {
            queue->enqueue(node->getLeft());
        }

        if (node->getRight() != nullptr) {
            queue->enqueue(node->getRight());
        }
    }
    delete queue;

    return result;
}

template<class T>
Queue<T> *BST<T>::postorder() {
    Queue<T> *result = new Queue<T>();
    postorder(root, result);
    return result;
}

template<class T>
BSTNode<T> *BST<T>::findMin(BSTNode<T> *t) {
    if (t == nullptr) {
        return nullptr;
    } else if (t->getLeft() == nullptr) {
        return t;
    }
    return findMin(t->getLeft());
}

template<class T>
BSTNode<T> *BST<T>::findMax(BSTNode<T> *t) {
    if (t == nullptr) {
        return NULL;
    } else if (t->getRight() == nullptr) {
        return t;
    }
    return findMax(t->getRight());
}

template<class T>
int BST<T>::getNumberOfItems() {
    return count;
}



