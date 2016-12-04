#pragma once

#include <iostream>
#include "Node.h"

template<class T>
class SinglyLinkedList {
protected:
    Node<T> *head, *last;
    int numberOfNodes;

    Node<T> *getNode(int index) {
        if (index >= numberOfNodes) {
            throw -1;
        }
        Node<T> *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->getNext();
        }
        return tmp;
    }

public:
    SinglyLinkedList() {
        numberOfNodes = 0;
        last = head = nullptr;
    }

    ~SinglyLinkedList() {
        clear();
    }

    virtual bool isEmpty() {
        return (numberOfNodes == 0);
    }

    int getNumberOfNodes() {
        return numberOfNodes;
    }

    T peek(int index) {
        return getNode(index)->getData();
    }

    int findNode(T data) {
        Node<T> *tmp = head;
        int index = 0;
        while (tmp != nullptr) {
            if (tmp->getData() == data) {
                return index;
            }
            tmp = tmp->getNext();
        }
        return -1;
    }

    bool add(T data, int position) {
        if (position < 0) {
            return false;
        }
        if (position == 1) {
            return addFirst(data);
        } else if (position == numberOfNodes + 1) {
            return addLast(data);
        } else {
            // the data should be added into somewhere in the middle of the chain.
            Node<T> *node = new Node<T>(data);
            Node<T> *prev = nullptr;
            // tmp node will be replaced with the new node.
            Node<T> *tmp = head;
            // starts i value from 1 because
            // tmp already points to the first node.
            for (int i = 1; i < position; i++) {
                prev = tmp;
                tmp = tmp->getNext();
            }
            node->setNextPtr(tmp);
            prev->setNextPtr(node);
        }
        numberOfNodes++;
        return true;
    }

    bool addFirst(T data) {
        // instantiates a new node to hold the given data.
        Node<T> *node = new Node<T>(data);
        if (isEmpty()) {
            // assigns the new instantiated node as a head node
            // because this is the first node within the searchedItems.
            last = head = node;
        } else {
            // otherwise, switches the current head node.
            node->setNextPtr(head);
            head = node;
        }
        numberOfNodes++;
        return true;
    }

    bool addLast(T data) {
        // instantiates a new node to hold the given data.
        Node<T> *node = new Node<T>(data);
        if (isEmpty()) {
            // assigns the new instantiated node as a head node
            // because this is the first node in the searchedItems.
            last = head = node;
        } else {
            last->setNextPtr(node);
            last = node;
        }
        numberOfNodes++;
        return true;
    }

    bool removeFirst() {
        if (isEmpty()) {
            throw -1;
        }
        // holds the node which will be removed.
        Node<T> *tmp = head;
        head = head->getNext();
        delete tmp;
        numberOfNodes--;
        return true;
    }

    bool removeLast() {
        if (isEmpty()) {
            throw -1;
        }
        Node<T> *prev = getNode(numberOfNodes - 2);
        Node<T> *tmp = last;
        last = prev;
        delete tmp;
        numberOfNodes--;
        return true;
    }

    /**
     * Removes a node where located at given position.
     * */
    bool remove(int position) {
        if (position < 0 || position > numberOfNodes) {
            return false;
        }
        if (position == 1) {
            return removeFirst();
        } else if (position == numberOfNodes) {
            return removeLast();
        } else {
            Node<T> *prev = nullptr;
            Node<T> *tmp = head;
            for (int i = 1; i < position; i++) {
                prev = tmp;
                tmp = tmp->getNext();
            }
            prev->setNextPtr(tmp->getNext());
            delete tmp;
        }
        numberOfNodes--;
        return true;
    }

    virtual void display() {
        Node<T> *node = head;
        for (int i = 0; i < numberOfNodes; i++) {
            std::cout << node->getData() << (i == numberOfNodes - 1 ? "" : "->");
            node = node->getNext();
        }
        std::cout << std::endl;
    }

    virtual bool displayNode(int index) {
        //Data type of node needs to overload the << operator
        Node<T> *node = getNode(index);
        try {
            std::cout << node->getData();
            return true;
        }
        catch (...) {
            std::cout
                    << "cannot display node. Node's data does not have the << operator overloaded."
                    << std::endl;
            return false;
        }
    }

    void clear() {
        if (isEmpty()) {
            return;
        }
        Node<T> *node = head;
        while (node->getNext() != nullptr) {
            Node<T> *tmp = node;
            node = node->getNext();
            delete tmp;
            numberOfNodes--;
        }
        // finally frees the last node.
        delete node;
        numberOfNodes--;
    }
};