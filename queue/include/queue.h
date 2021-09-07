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
    Queue();
    void enqueue(const T &);
    T dequeue();
    void print() const;
    void clear();
    ~Queue();
};

/**
 * Queue constructor
 */
template <class T>
Queue<T>::Queue()
{
    this->front = nullptr;
}

/**
 * Insert node to the back of queue
 * 
 * @param data Data to insert
 */
template <class T>
void Queue<T>::enqueue(const T &data)
{
    if (!this->front)
        this->front = new Node<T>(data);
    else
    {
        Node<T> *current = this->front;
        while (current->next)
            current = current->next;
        current->next = new Node<T>(data);
    }
}

/**
 * Remove node from the front of queue
 * 
 * @return Removed data
 */
template <class T>
T Queue<T>::dequeue()
{
    if (!this->front)
        throw "Queue is empty.";
    Node<T> *temp = this->front;
    T data = temp->data;
    this->front = this->front->next;
    delete temp;
    return data;
}

/**
 * Print all nodes
 */
template <class T>
void Queue<T>::print() const
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
 * Remove all nodes
 */
template <class T>
void Queue<T>::clear()
{
    Node<T> *temp;
    while (this->front)
    {
        temp = this->front;
        this->front = this->front->next;
        delete temp;
    }
}

/**
 * Queue destructor
 */
template <class T>
Queue<T>::~Queue()
{
    this->clear();
}

#endif