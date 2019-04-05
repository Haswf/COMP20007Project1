/* * * * * * *
 * Deque module (i.e., double ended queue) for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2019
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Shuyang Fan
 */

//                   WRITE YOUR IMPLEMENTATION HERE
//
// You should fill in the function definitions for
//  - new_deque()
//  - free_deque()
//  - deque_push()
//  - deque_insert()
//  - deque_pop()
//  - deque_remove()
//  - deque_size()
//
// Don't be shy to add any extra functions or types you may need.

#include <stdio.h>
#include <stdlib.h>

#include "deque.h"
// Change data type here

// TODO: Fill in this struct definition, or change the typedef in deque.h
struct deque {
    Dlist *list;
};

// Create a new empty Deque and return a pointer to it
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Deque *new_deque() {
    Deque *newdq = malloc(sizeof(Deque));
    newdq->list = new_dlist();
    return newdq;
}

// Free the memory associated with a Deque
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void free_deque(Deque *deque) {
    // call free_dlist to free each node in the dlist
    free_dlist(deque->list);
    // free the structure itself
    free(deque);
}

// Add a Point to the top of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_push(Deque *deque, Point data) {
    dlist_add_start(deque->list, data);
}

// Add a Point to the bottom of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_insert(Deque *deque, Point data) {
    // TODO: Implement deque_insert()
    dlist_add_end(deque->list, data);
}

// Remove and return the top Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_pop(Deque *deque) {
    // TODO: Implement deque_pop()
    return dlist_remove_start(deque->list);
}

// Remove and return the bottom Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_remove(Deque *deque) {
    // TODO: Implement deque_remove()
    return dlist_remove_end(deque->list);
}

// Return the number of Points in a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: ...
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
int deque_size(Deque *deque) {
    return dlist_size(deque->list);
}

// TODO: Add any other functions you might need for your Deque module
