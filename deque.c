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
#include <assert.h>
#include "deque.h"

// Create a new empty Deque and return a pointer to it
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Deque *new_deque() {
    Deque *newdq = (Deque*)malloc(sizeof(Deque));
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
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_push(Deque *deque, Point data) {
    dlist_add_end(deque->list, data);
}

// Add a Point to the bottom of a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
void deque_insert(Deque *deque, Point data) {
    // TODO: Implement deque_insert()
    dlist_add_start(deque->list, data);
}

// Remove and return the top Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_pop(Deque *deque) {
    // TODO: Implement deque_pop()
    return dlist_remove_end(deque->list);
}

// Remove and return the bottom Point from a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
Point deque_remove(Deque *deque) {
    // TODO: Implement deque_remove()
    return dlist_remove_start(deque->list);
}

// Return the number of Points in a Deque
//
// TODO: Fill in the runtime of this function
// Runtime: O(1)
//
// DO NOT CHANGE THIS FUNCTION SIGNATURE
int deque_size(Deque *deque) {
    return dlist_size(deque->list);
}

// Return the top Point from a Deque
Point access_top(Deque *deque){
    assert(deque);
    // Assert Deque is not empty
    assert(deque_size(deque) > 0);
    return deque->list->tail->data;
}

// Return the bottom Point from a Deque
Point access_bottom(Deque *deque){
    assert(deque);
    // Assert Deque is not empty
    assert(deque_size(deque) > 0);
    return deque->list->head->data;
}


// Provide "pythonic" access to deque by index.
// The bottom has index 0. The next one is 1 And so on
// The top has index -1. The next one is -2 and so on.
Point access_offset(Deque *deque, int offset){
    int length = deque_size(deque);
    // check if offset is valid
    assert(-(length+1)<offset && offset<length);
    // Access bottom
    if (offset >= 0){
        int i;
        // Retrieve head
        Node* curr = deque->list->head;
        // Traverse forward to target node
        for (i=offset;i>0;i--){
            curr = curr->next;
        }
        // return data
        return curr->data;
    }
    // Access top
    else {
        int i;
        // Retrieve tail
        Node* curr = deque->list->tail;
        // Traverse backward to target node
        for (i=offset;i<-1;i++){
            curr = curr->prev;
        }
        // return data
        return curr->data;
    }
}

// Function to test access_offset functionality
void test_access_offset(){
    // initialise test deque
    Deque* mydeque = new_deque();
    // add points to deque
    deque_push(mydeque, new_point(1.0, 2.0));
    deque_push(mydeque, new_point(3.0, 1.0));
    deque_push(mydeque, new_point(1.5, 1.5));
    // testing offsets
    print_point(access_offset(mydeque,0));
    print_point(access_offset(mydeque,1));
    print_point(access_offset(mydeque,2));
    //print_point(access_offset(mydeque,3));
    print_point(access_offset(mydeque,-1));
    print_point(access_offset(mydeque,-2));
    print_point(access_offset(mydeque,-3));
    print_point(access_offset(mydeque,-4));
}