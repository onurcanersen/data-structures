/**
 * main.cpp
 * Main function
 * 
 * @author Onurcan Erşen
 */

#include <iostream>

#include "../include/utils.h"
#include "../include/queue.h"

using namespace std;

int main()
{
    char choice;
    Queue<int> ints;
    do
    {
        print_actions();
        cout << "Enter an action: ";
        cin >> choice;
        perform_action(choice, ints);
        cout << endl;
    } while (choice != 'E' && choice != 'e');
    return EXIT_SUCCESS;
}