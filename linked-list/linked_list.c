#include "linked_list.h"



/**
 * Create and return a linked list
 */
linked_list * create_list() {
	
	// Allocate memory for the list
	linked_list * l_list = malloc(sizeof(linked_list));
	
	// Create a sentinel node
	list_node * sentinel = malloc(sizeof(list_node));
	sentinel->next = sentinel;
	l_list->head = sentinel;
	l_list->length = 0;
	return l_list;

}

/** 
 * Pretty print the array
 */
void pretty_print(linked_list * l_list) {
	
	// Print some of the meta data
	printf("**************************************\n");
	printf("\t  Length: %d\n", l_list->length);

	// Iterate items and create a string
	for (list_node * node = l_list->sentinel->next; 
             node != l_list->sentinel; 
             node = node->next) {
		printf("\t              : %d\n", node->value);
	}
	
	printf("**************************************\n");
}

/**
 * Add an item to the front of the list
 */
void push_front(linked_list * l_list, int value) {

	// Allocate memory for the list
	list_node * new_node = malloc(sizeof(list_node));

	// Set the new node values
	new_node->value = value;
       	new_node->next = l_list->sentinel->next;
 
	// Put it after the sentinel
	l_list->sentinel->next = new_node;

	l_list->length++;

}



