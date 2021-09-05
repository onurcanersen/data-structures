/**
 * node.h
 * Node class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef NODE_H
#define NODE_H

template <class T> // Forward declaration to make Stack friend class of Node
class Stack;

template <class T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(const T &);   // Constructor
    T getData() const; // Getters
    Node<T> *getNext() const;
    void setData(const T &); // Setters
    void setNext(const Node<T> *);
    friend class Stack<T>;
};

/**
 * Node class template constructor
 * 
 * @param data Node data
 */
template <class T>
Node<T>::Node(const T &data)
{
    this->data = data;
    this->next = NULL;
}

// Getters
template <class T>
T Node<T>::getData() const
{
    return this->data;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
    return this->next;
}

// Setters
template <class T>
void Node<T>::setData(const T &data)
{
    this->data = data;
}

template <class T>
void Node<T>::setNext(const Node<T> *next)
{
    this->next = next;
}

#endif