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
    cout << "A - Add to stack" << endl;
    cout << "R - Remove from stack" << endl;
    cout << "C - Clear stack" << endl;
    cout << "P - Print stack" << endl;
    cout << "E - Exit" << endl
         << endl
         << endl;
}

/**
 * Add integer to the top of stack
 * 
 * @param stack Stack to add
 */
void add(Stack<int> &stack)
{
    cout << "Enter an integer: ";
    int data;
    cin >> data;
    stack.push(data);
    cout << "New stack:" << endl;
    stack.echo();
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
        stack.echo();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
}

/**
 * Remove all integers from the stack
 * 
 * @param stack Stack to clear
 */
void clear(Stack<int> &stack)
{
    stack.clear();
    cout << "Stack has been cleared." << endl;
    cout << "New stack:" << endl;
    stack.echo();
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
    case 'A':
    case 'a':
        add(stack);
        break;
    case 'R':
    case 'r':
        remove(stack);
        break;
    case 'C':
    case 'c':
        clear(stack);
        break;
    case 'P':
    case 'p':
        cout << "Stack:" << endl;
        stack.echo();
        break;
    case 'E':
    case 'e':
        break;
    default:
        cout << "Enter a valid choice." << endl;
        break;
    }
}