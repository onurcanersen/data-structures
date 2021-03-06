/**
 * utils.h
 * Declarations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#ifndef UTILS_H
#define UTILS_H

#include "stack.h"

void print_actions();
void insert(Stack<int> &);
void remove(Stack<int> &);
void perform_action(char, Stack<int> &);

#endif