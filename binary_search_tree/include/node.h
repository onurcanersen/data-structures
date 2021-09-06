/**
 * node.h
 * Node class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef NODE_H
#define NODE_H

template <class T>
class Tree;

template <class T>
class Node
{
    T data;
    Node<T> *left;
    Node<T> *right;

public:
    Node(const T &);
    friend class Tree<T>;
};

/**
 * Node constructor
 */
template <class T>
Node<T>::Node(const T &data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

#endif