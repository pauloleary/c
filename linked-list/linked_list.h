#ifndef LINKED_LIST_H_   
#define LINKED_LIST_H_ 

#include <stdio.h>
#include <stdlib.h>


/*
 * Struct representing a node in
 * in the linked list
 */
typedef struct list_node {

	int value;
	struct list_node * node;

} list_node;

/* 
 * Struct representing a linked list 
 */
typedef struct linked_list {

	int legth;
	list_node * head;

} linked_list;


#endif 

