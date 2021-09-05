/**
 * utils.h
 * Declarations of functions used in main function
 * 
 * @author Onurcan Erşen
 */

#ifndef UTILS_H
#define UTILS_H

#include "queue.h"

void print_actions();
void add(Queue<int> &);
void remove(Queue<int> &);
void clear(Queue<int> &);
void perform_action(char, Queue<int> &);

#endif