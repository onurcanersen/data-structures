/**
 * utils.h
 * Declarations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#ifndef UTILS_H
#define UTILS_H

#include "tree.h"

void print_actions();
void insert(Tree<int> &);
void remove(Tree<int> &);
void perform_action(char, Tree<int> &);

#endif