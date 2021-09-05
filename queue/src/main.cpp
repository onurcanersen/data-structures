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
        cout << "Enter a choice: ";
        cin >> choice;
        perform_action(choice, ints);
    } while (choice != 'E' && choice != 'e');
    return EXIT_SUCCESS;
}