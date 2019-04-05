//
// Created by Haswe on 5/04/2019.
//

#ifndef COMP20007PEOJECT1_DLIST_H
#define COMP20007PEOJECT1_DLIST_H
// Change data type here
typedef int Data;
typedef struct dlist Dlist;

typedef struct node Node;

// Creation and deletion
Dlist *new_list();
void free_dlist(Dlist *ddl);

Node *new_node();
void free_node(Node *node);


// Manipulation
void list_add_start(Dlist *ddl, Data data);
void list_add_end(Dlist *ddl, Data data);
Data list_remove_start(Dlist *ddl);
Data list_remove_end(Dlist *ddl);



#endif //COMP20007PEOJECT1_DLIST_H
