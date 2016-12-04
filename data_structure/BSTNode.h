//#include "Node.h"

#include "Node.h"

template<class T>
class BSTNode : protected Node<T> {
private:
    BSTNode<T> *right, *left;
public:
    BSTNode(T item);

    T getData();

    void setData(T item);

    BSTNode<T> *getLeft();

    BSTNode<T> *getRight();

    void setLeft(BSTNode<T> *node);

    void setRight(BSTNode<T> *node);
};

template<class T>
BSTNode<T>::BSTNode(T item) : Node<T>(item) {
    this->setRight(nullptr);
    this->setLeft(nullptr);
}

template<class T>
BSTNode<T> *BSTNode<T>::getLeft() {
    return left;
}

template<class T>
BSTNode<T> *BSTNode<T>::getRight() {
    return right;
}

template<class T>
void BSTNode<T>::setLeft(BSTNode<T> *node) {
    left = node;
}

template<class T>
void BSTNode<T>::setRight(BSTNode<T> *node) {
    right = node;
}

template<class T>
T BSTNode<T>::getData() {
    return Node<T>::getData();
}

template<class T>
void BSTNode<T>::setData(T item) {
    Node<T>::setData(item);
}
