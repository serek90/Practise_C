/*
*Plik naglowkowy z funkcjami do linkedlist
*
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
   int value;
   struct *node next;
};

typdef struct node node_t;

node_t *find_node(node_t *head, int value);
node_t *create_new_node(node_t *head, int value);
void printList(*head);

#endif
