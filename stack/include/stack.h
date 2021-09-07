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

public:
    Stack();
    void push(const T &);
    T pop();
    void print() const;
    void clear();
    ~Stack();
};

/**
 * Stack constructor
 */
template <class T>
Stack<T>::Stack()
{
    this->top = nullptr;
}

/**
 * Insert data to the top of stack
 * 
 * @param data Data to insert
 */
template <class T>
void Stack<T>::push(const T &data)
{
    Node<T> *new_node = new Node<T>(data);
    new_node->next = this->top;
    this->top = new_node;
}

/**
 * Remove data from the top of stack
 * 
 * @return Removed data
 */
template <class T>
T Stack<T>::pop()
{
    if (!this->top)
        throw "Stack is empty.";
    Node<T> *temp = this->top;
    T data = temp->data;
    this->top = this->top->next;
    delete temp;
    return data;
}

/**
 * Print all nodes
 */
template <class T>
void Stack<T>::print() const
{
    Node<T> *current = this->top;
    while (current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

/**
 * Remove all nodes
 */
template <class T>
void Stack<T>::clear()
{
    Node<T> *temp;
    while (this->top)
    {
        temp = this->top;
        this->top = this->top->next;
        delete temp;
    }
}

/**
 * Stack destructor
 */
template <class T>
Stack<T>::~Stack()
{
    this->clear();
}

#endif