/**
 * node.h
 * Node class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef NODE_H
#define NODE_H

template <class T>
class Stack;

template <class T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(const T &);
    friend class Stack<T>;
};

/**
 * Node constructor
 * 
 * @param data Node data
 */
template <class T>
Node<T>::Node(const T &data)
{
    this->data = data;
    this->next = nullptr;
}

#endif