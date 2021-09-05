/**
 * queue.h
 * Queue class template declarations and implementations
 * 
 * @author Onurcan Erşen
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "node.h"

using namespace std;

template <class T>
class Queue
{
    Node<T> *front;

public:
    Queue();                               // Constructor
    Queue(const Queue<T> &);               // Copy constructor
    Queue<T> &operator=(const Queue<T> &); // Copy assignment operator
    ~Queue();                              // Destructor
    void enqueue(const T &);
    T dequeue();
    void clear();
    void echo() const;
    bool empty() const;
    Node<T> *getFront() const;      // Getters
    void setFront(const Node<T> *); // Setters
};

/**
 * Queue class template constructor
 */
template <class T>
Queue<T>::Queue()
{
    front = NULL;
}

/**
 * Queue copy constructor
 * 
 * @param other Queue to copy from
 */
template <class T>
Queue<T>::Queue(const Queue<T> &other)
{
    this->front = NULL;
    Node<T> *current = other.front;
    while (current)
    {
        this->enqueue(current->data);
        current = current->next;
    }
}

/**
 * Queue copy assignment operator
 * 
 * @param other Queue to assign
 * @return Assigned Queue
 */
template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other)
{
    this->clear();
    Node<T> *current = other.front;
    while (current)
    {
        this->enqueue(current->data);
        current = current->next;
    }
    return *this;
}

/**
 * Queue class template destructor
 */
template <class T>
Queue<T>::~Queue()
{
    this->clear();
}

/**
 * Add node to the back of Queue
 * 
 * @param data Data to add
 */
template <class T>
void Queue<T>::enqueue(const T &data)
{
    if (this->empty())
    {
        this->front = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->front;
        while (current->next)
            current = current->next;
        current->next = new Node<T>(data);
    }
}

/**
 * Remove node from the front of Queue
 * 
 * @return Removed data
 */
template <class T>
T Queue<T>::dequeue()
{
    if (this->empty())
        throw "Queue is empty.";
    T data = this->front->data;
    Node<T> *temp = this->front;
    this->front = temp->next;
    delete temp;
    return data;
}

/**
 * Remove all nodes
 */
template <class T>
void Queue<T>::clear()
{
    Node<T> *current = this->front;
    Node<T> *temp;
    while (current)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    this->front = NULL;
}

/**
 * Print all nodes
 */
template <class T>
void Queue<T>::echo() const
{
    Node<T> *current = this->front;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

/**
 * Return if Queue is empty or not
 * 
 * @return True if empty, false if not empty
 */
template <class T>
bool Queue<T>::empty() const
{
    return !this->front;
}

// Getters
template <class T>
Node<T> *Queue<T>::getFront() const
{
    return this->front;
}

// Setters
template <class T>
void Queue<T>::setFront(const Node<T> *front)
{
    this->front = front;
}

#endif