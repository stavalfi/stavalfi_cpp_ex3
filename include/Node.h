#ifndef STAVALFI_CPP_EX3_NODE_H
#define STAVALFI_CPP_EX3_NODE_H

#include <utility>


template<typename T>
class Node {
private:
    T data;
    Node *next;
public:
    Node(const T &data);

    T &getData();

    Node *getNext() const;

    void setNext(Node *next);

    //~Node();
};

template<typename T>
Node<T>::Node(const T &data)
        : data(data), next(nullptr) {}

template<typename T>
T &Node<T>::getData() {
    return this->data;
}

template<typename T>
Node<T> *Node<T>::getNext() const {
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}


#endif //STAVALFI_CPP_EX3_NODE_H
