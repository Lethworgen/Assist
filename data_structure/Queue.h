#include "SinglyLinkedList.h"

template<class T>
class Queue : protected SinglyLinkedList<T> {

public:
    Queue() : SinglyLinkedList<T>() {};

    bool enqueue(T data) {
        return Queue::addLast(data);
    };

    bool dequeue() {
        return Queue::removeFirst();
    };

    bool isEmpty() {
        return SinglyLinkedList<T>::isEmpty();
    };

    T peekFront() {
        return Queue::peek(0);
    };

    T peekRear() {
        return Queue::peek(SinglyLinkedList<T>::getNumberOfNodes() - 1);
    }

    void display() {
        SinglyLinkedList<T>::display();
    };

    void clear() {
        SinglyLinkedList<T>::clear();
    }

    int getNumberOfNodes() {
        return SinglyLinkedList<T>::getNumberOfNodes();
    }
};