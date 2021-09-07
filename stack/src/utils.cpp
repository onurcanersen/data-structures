/**
 * utils.cpp
 * Implementations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#include <iostream>

#include "../include/utils.h"
#include "../include/stack.h"

using namespace std;

/**
 * Print available actions
 */
void print_actions()
{
    cout << "I - Insert data" << endl;
    cout << "R - Remove data" << endl;
    cout << "C - Clear stack" << endl;
    cout << "P - Print stack" << endl;
    cout << "E - Exit" << endl
         << endl;
}

/**
 * Insert integer to the top of stack
 * 
 * @param stack Stack to insert to
 */
void insert(Stack<int> &stack)
{
    cout << "Enter an integer: ";
    int data;
    cin >> data;
    stack.push(data);
    cout << "New stack:" << endl;
    stack.print();
}

/**
 * Remove integer from the top of stack
 * 
 * @param stack Stack to remove from
 */
void remove(Stack<int> &stack)
{
    try
    {
        cout << stack.pop() << " removed from the stack." << endl;
        cout << "New stack:" << endl;
        stack.print();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
}

/**
 * Perform action with choice
 * 
 * @param choice Action choice
 * @param stack Stack to perform on
 */
void perform_action(char choice, Stack<int> &stack)
{
    switch (choice)
    {
    case 'I':
    case 'i':
        insert(stack);
        break;
    case 'R':
    case 'r':
        remove(stack);
        break;
    case 'C':
    case 'c':
        stack.clear();
        cout << "Stack has been cleared." << endl;
        break;
    case 'P':
    case 'p':
        cout << "Stack:" << endl;
        stack.print();
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