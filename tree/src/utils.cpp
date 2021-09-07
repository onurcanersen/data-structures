/**
 * utils.cpp
 * Implementations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#include <iostream>

#include "../include/utils.h"
#include "../include/tree.h"

using namespace std;

/**
 * Print available actions
 */
void print_actions()
{
    cout << "I - Insert data" << endl;
    cout << "R - Remove data" << endl;
    cout << "P - Print tree" << endl;
    cout << "C - Clear tree" << endl;
    cout << "E - Exit" << endl
         << endl;
}

/**
 * Insert integer to tree
 * 
 * @param tree Tree to insert to
 */
void insert(Tree<int> &tree)
{
    try
    {
        cout << "Enter an integer: ";
        int data;
        cin >> data;
        tree.insert(data);
        cout << "New tree: ";
        tree.print();
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
}

/**
 * Remove integer from tree
 * 
 * @param tree Tree to remove from
 */
void remove(Tree<int> &tree)
{
    try
    {
        cout << "Enter an integer: ";
        int data;
        cin >> data;
        tree.remove(data);
        cout << "New tree: ";
        tree.print();
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
 * @param tree Tree to perform on
 */
void perform_action(char choice, Tree<int> &tree)
{
    switch (choice)
    {
    case 'I':
    case 'i':
        insert(tree);
        break;
    case 'R':
    case 'r':
        remove(tree);
        break;
    case 'P':
    case 'p':
        cout << "Tree: ";
        tree.print();
        break;
    case 'C':
    case 'c':
        tree.clear();
        cout << "Tree has been cleared." << endl;
        break;
    case 'E':
    case 'e':
        cout << "Exiting application." << endl;
        break;
    default:
        cout << "Enter a valid action." << endl;
    }
}