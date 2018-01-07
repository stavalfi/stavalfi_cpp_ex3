#ifndef STAVALFI_CPP_EX3_SET_H
#define STAVALFI_CPP_EX3_SET_H

#include <cstdlib>
#include <utility>
#include <cassert>
#include "Node.h"
#include <new>

/**
 * Ordered list
 * @tparam T
 * T must implement operator<=.
 * (to place new elements in order from small to big)
 */
template<typename T>
class Set {
public:
    T &insertSorted(const T &data);

    void remove(const T &data);

    bool isEmpty() const;

    T removeFirst();

    template<typename MapToNumber>
    std::size_t sum(MapToNumber mapToNumber) const {
        std::size_t sum = 0;
        Node<T> *pos = this->head;
        while (pos != nullptr) {
            const T &data = pos->getData();
            sum += mapToNumber(data);
            pos = pos->getNext();
        }
        return sum;
    }

    ~Set();

private:
    Node<T> *head = nullptr;
};

template<typename T>
void Set<T>::remove(const T &data) {
    // check if we need to remove the first node
    if (this->head->getData() <= data && data <= this->head->getData()) {
        Node<T> *temp = this->head;
        this->head = this->head->getNext();
        // call destructor of data
        temp->getData().~T();
        free(temp);
        return;
    }

    // check if we need to remove a node in the middle to the end (including)
    Node<T> *pos = this->head;
    while (pos != nullptr && pos->getNext() != nullptr) {
        if (pos->getNext()->getData() <= data && data <= pos->getNext()->getData()) {
            Node<T> *temp = pos->getNext();
            pos->setNext(pos->getNext()->getNext());
            // call destructor of data
            temp->getData().~T();
            free(temp);
            return;
        }
        pos = pos->getNext();
    }
}

template<typename T>
Set<T>::~Set() {
    Node<T> *pos = this->head;
    while (pos != nullptr) {
        Node<T> *temp = pos->getNext();
        // call destructor of data
        temp->getData().~T();
        free(pos);
        pos = temp;
    }
}

template<typename T>
T &Set<T>::insertSorted(const T &data) {
    // add to head
    if (this->head == nullptr) {
        this->head = static_cast<Node<T> *>(malloc(sizeof(Node<T>)));
        assert(this->head != nullptr);
        this->head = new(this->head) Node<T>(data);
        return this->head->getData();
    } else if (data <= this->head->getData()) {
        // put before head
        Node<T> *newNode = static_cast<Node<T> *>(malloc(sizeof(Node<T>)));
        assert(this->head != nullptr);
        newNode = new(newNode) Node<T>(data);
        newNode->setNext(this->head);
        this->head = newNode;
        return this->head->getData();
    }
    // add to somewhere in the set in a sorted way.
    Node<T> *pos = this->head;
    while (pos != nullptr) {
        if (pos->getData() <= data) {
            if (pos->getNext() != nullptr) {
                if (data <= pos->getNext()->getData()) {
                    // between 2 nodes
                    Node<T> *newNode = static_cast<Node<T> *>(malloc(sizeof(Node<T>)));
                    assert(this->head != nullptr);
                    newNode = new(newNode) Node<T>(data);
                    newNode->setNext(pos->getNext());
                    pos->setNext(newNode);
                    return newNode->getData();
                }
            } else
                // put after the last node
                // with out going to the next node.
                break;
        }
        pos = pos->getNext();
    }
    // if pos == nullptr then the first if
    // inside the while loop was failed
    // at the last iteration and it means
    // that data is the smallest number
    // from all the values in set.
    // then the first if inside this
    // method would be applied.
    // contradiction ;D
    assert(pos != nullptr);
    // put after the last node
    Node<T> *newNode = static_cast<Node<T> *>(malloc(sizeof(Node<T>)));
    assert(newNode != nullptr);
    newNode = new(newNode) Node<T>(data);
    pos->setNext(newNode);
    return newNode->getData();
}

template<typename T>
T Set<T>::removeFirst() {
    assert(!isEmpty());
    Node<T> *temp = this->head;
    this->head = this->head->getNext();
    // call destructor of data
    T data = temp->getData();
    free(temp);
    return data;
}

template<typename T>
bool Set<T>::isEmpty() const {
    return this->head == nullptr;
}


#endif //STAVALFI_CPP_EX3_SET_H
