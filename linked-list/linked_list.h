#ifndef LINKED_LIST_H_   
#define LINKED_LIST_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 * Struct representing a node in
 * in the linked list
 */
typedef struct list_node {

	int value;
	struct list_node * next;

} list_node;

/* 
 * Struct representing a linked list 
 */
typedef struct linked_list {

	int length;
	list_node * head;
	list_node * sentinel;

} linked_list;

/**
 * Create and return a linked list
 */
linked_list * create_list();

/** 
 * Pretty print the list 
 */
void pretty_print(linked_list * l_list); 

/**
 * Add an item to the front of the list
 */
void push_front(linked_list * l_list, int value);


/**
 * Is the list empty
 */
bool is_empty(linked_list * l_list);


/**
 * Get the value at index
 */
int value_at(linked_list * l_list, int index);

#endif 

