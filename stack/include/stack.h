/**
 * stack.h
 * Stack class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "node.h"

using namespace std;

template <class T>
class Stack
{
    Node<T> *top;
    void add(const T &);

public:
    Stack();                               // Constructor
    Stack(const Stack<T> &);               // Copy constructor
    Stack<T> &operator=(const Stack<T> &); // Copy assignment operator
    ~Stack();                              // Destructor
    void push(const T &);
    T pop();
    void clear();
    void echo() const;
    bool empty() const;
    Node<T> *getTop() const;      // Getters
    void setTop(const Node<T> *); // Setters
};

/**
 * Stack class template constructor
 */
template <class T>
Stack<T>::Stack()
{
    this->top = NULL;
}

/**
 * Add data to the end of top linked-list
 * 
 * Use only in copy constructor and
 * copy assignment operator, thus private
 * 
 * @param data Data to add
 */
template <class T>
void Stack<T>::add(const T &data)
{
    if (this->empty())
    {
        this->top = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->top;
        while (current->next)
            current = current->next;
        current->next = new Node<T>(data);
    }
}

/**
 * Stack copy constructor
 * 
 * @param other Stack to copy from
 */
template <class T>
Stack<T>::Stack(const Stack<T> &other)
{
    this->top = NULL;
    Node<T> *current = other.top;
    while (current)
    {
        this->add(current->data);
        current = current->next;
    }
}

/**
 * Stack copy assignment operator
 * 
 * @param other Stack to assign
 * @return Assigned Stack
 */
template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
    this->clear();
    Node<T> *current = other.top;
    while (current)
    {
        this->add(current->data);
        current = current->next;
    }
    return *this;
}

/**
 * Stack class template destructor
 */
template <class T>
Stack<T>::~Stack()
{
    this->clear();
}

/**
 * Add data to the top of Stack
 * 
 * @param data Data to add
 */
template <class T>
void Stack<T>::push(const T &data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = this->top;
    this->top = newNode;
}

/**
 * Remove data from the top of Stack
 * 
 * @return Removed data
 */
template <class T>
T Stack<T>::pop()
{
    if (this->empty())
        throw "Stack is empty.";
    T data = this->top->data;
    Node<T> *temp = this->top;
    this->top = temp->next;
    delete temp;
    return data;
}

/**
 * Remove all nodes
 */
template <class T>
void Stack<T>::clear()
{
    Node<T> *current = this->top;
    Node<T> *temp;
    while (current)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    this->top = NULL;
}

/**
 * Print all nodes
 */
template <class T>
void Stack<T>::echo() const
{
    Node<T> *current = this->top;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

/**
 * Return if Stack is empty or not
 * 
 * @return True if empty, false if not empty
 */
template <class T>
bool Stack<T>::empty() const
{
    return !this->top;
}

// Getters
template <class T>
Node<T> *Stack<T>::getTop() const
{
    return this->top;
}

// Setters
template <class T>
void Stack<T>::setTop(const Node<T> *top)
{
    this->top = top;
}

#endif