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
 * Prints available actions
 */
void print_actions()
{
    cout << "A - Add to queue" << endl;
    cout << "R - Remove from queue" << endl;
    cout << "C - Clear queue" << endl;
    cout << "P - Print queue" << endl;
    cout << "E - Exit" << endl
         << endl
         << endl;
}

/**
 * Add integer to the back of queue
 * 
 * @param queue Queue to add
 */
void add(Queue<int> &queue)
{
    cout << "Enter an integer: ";
    int data;
    cin >> data;
    queue.enqueue(data);
    cout << "New queue: ";
    queue.echo();
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
        queue.echo();
    }
    catch (char const *e)
    {
        cout << e << endl;
    }
}

/**
 * Remove all integers from queue
 * 
 * @param queue Queue to clear
 */
void clear(Queue<int> &queue)
{
    queue.clear();
    cout << "Queue has been cleared." << endl;
    cout << "New queue: ";
    queue.echo();
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
    case 'A':
    case 'a':
        add(queue);
        break;
    case 'R':
    case 'r':
        remove(queue);
        break;
    case 'C':
    case 'c':
        clear(queue);
        break;
    case 'P':
    case 'p':
        cout << "Queue: ";
        queue.echo();
        break;
    case 'E':
    case 'e':
        break;
    default:
        cout << "Enter a valid choice." << endl;
        break;
    }
}