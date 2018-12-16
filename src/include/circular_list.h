/*
 * C Program to Implement Circular Doubly Linked List     
 * https://www.sanfoundry.com/c-program-circular-doubly-linked-list/            
 */

#ifndef _H_CIRCLIST_H_
#define _H_CIRCLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "indicators.h"
#include "init.h"
 
struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;

n* create_node(int);
void add_node();
void insert_at_first();
void insert_at_end();
void insert_at_position();
void delete_node_position();
void sort_list();
void update();
void search();
void display_from_beg();
void display_in_rev();

#endif