/**
 * utils.cpp
 * Implementations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#include <iostream>

#include "../include/utils.h"
#include "../include/queue.h"

using namespace std;

/**
 * Print available actions
 */
void print_actions()
{
    cout << "I - Insert data" << endl;
    cout << "R - Remove data" << endl;
    cout << "C - Clear queue" << endl;
    cout << "P - Print queue" << endl;
    cout << "E - Exit" << endl
         << endl;
}

/**
 * Insert integer to the back of queue
 * 
 * @param queue Queue to insert to
 */
void insert(Queue<int> &queue)
{
    cout << "Enter an integer: ";
    int data;
    cin >> data;
    queue.enqueue(data);
    cout << "New queue: ";
    queue.print();
}

/**
 * Remove integer from the front of queue
 * 
 * @param queue Queue to remove from
 */
void remove(Queue<int> &queue)
{
    try
    {
        cout << queue.dequeue() << " removed from queue." << endl;
        cout << "New queue: ";
        queue.print();
    }
    catch (char const *e)
    {
        cout << e << endl;
    }
}

/**
 * Perform action with choice
 * 
 * @param choice Action choice
 * @param queue Queue to perform on
 */
void perform_action(char choice, Queue<int> &queue)
{
    switch (choice)
    {
    case 'I':
    case 'i':
        insert(queue);
        break;
    case 'R':
    case 'r':
        remove(queue);
        break;
    case 'C':
    case 'c':
        queue.clear();
        cout << "Queue has been cleared." << endl;
        break;
    case 'P':
    case 'p':
        cout << "Queue: ";
        queue.print();
        break;
    case 'E':
    case 'e':
        cout << "Exiting application." << endl;
        break;
    default:
        cout << "Enter a valid action." << endl;
        break;
    }
}