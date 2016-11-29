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
	l_list->sentinel = sentinel;
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
	printf("\tIs Empty: %d\n", is_empty(l_list));

	int index = 0;
	// Iterate items and create a string
	for (list_node * node = l_list->sentinel->next; 
             node != l_list->sentinel; 
             node = node->next) {
		printf("\t       %d: %d\n", index, node->value);
		index++;
	}
	
	printf("**************************************\n");
}

/**
 * Add an item to the front of the list - O(1)
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

/**
 * Is the list empty
 */
bool is_empty(linked_list * l_list) {
	return (l_list->length == 0) ? 0 : 1;
}


/**
 * Return the value at index - O(n)
 */
int value_at(linked_list * l_list, int index) {

	if (index >= l_list->length) {
		exit(EXIT_FAILURE);
	}
	int current_index = 0;
	for (list_node * node = l_list->sentinel->next; 
             node != l_list->sentinel; 
             node = node->next) {
		if (index == current_index) {
			return node->value;
		}	
		current_index++;
	}
	return -1;
}


