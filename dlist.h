//
// Created by Haswe on 5/04/2019.
//

#ifndef DLIST_H
#define DLIST_H

#include "point.h"

// Change data type here
typedef struct dlist Dlist;
typedef Point Data;
typedef struct node Node;

// Creation and deletion
Dlist *new_dlist();
void free_dlist(Dlist *ddl);
Node *new_node();
void free_node(Node *node);


// Manipulation
void dlist_add_start(Dlist *ddl, Data data);
void dlist_add_end(Dlist *ddl, Data data);
Data dlist_remove_start(Dlist *ddl);
Data dlist_remove_end(Dlist *ddl);
int dlist_size(Dlist*ddl);



#endif //DLIST_H
