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
 * Pretty print the node
 */
void pretty_print_node(list_node * l_node) {
	
	// Print some of the meta data
	printf("[%d]->[%d]", l_node->value, l_node->next->value);
}

/** 
 * Pretty print the list in a single line
 */
void pretty_print_list(linked_list * l_list) {
	for (list_node * node = l_list->sentinel->next; 
             node != l_list->sentinel; 
             node = node->next) {
		printf("[%d]->", node->value);
	}
}


/** 
 * Pretty print the array
 */
void pretty_print(linked_list * l_list) {
	
	// Print some of the meta data
	printf("**************************************\n");
	printf("\t  Length: %d\n", l_list->length);
	printf("\tIs Empty: %d\n", is_empty(l_list));
	printf("\t    List: ");
	pretty_print_list(l_list);
	printf("\n");

	int index = 0;
	// Iterate items and create a string
	for (list_node * node = l_list->sentinel->next; 
             node != l_list->sentinel; 
             node = node->next) {
		printf("\t       %d: ", index);
		pretty_print_node(node);
		printf("\n");
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
 * Add an item to the front of the list - O(1)
 */
void push_back(linked_list * l_list, int value) {

	// Allocate memory for the list
	list_node * new_node = malloc(sizeof(list_node));

	// Set the new node values
	new_node->value = value;
       	new_node->next = l_list->sentinel;
 
	// Find the last node and set its next
	list_node * node = l_list->sentinel;
	for (int i = 0; i < l_list->length; i++) {
		node = node->next;	
	}
	node->next = new_node;	

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

/**
 * Remove and return the first value in the list
 */
int pop_front(linked_list * l_list) {
	
	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}	
	
	int value = l_list->sentinel->next->value;
	free(l_list->sentinel->next);
	l_list->sentinel->next = l_list->sentinel->next->next;	
	l_list->length--;
	return value;
}

/**
 * Remove and return the first value in the list - O(n)
 */
int pop_back(linked_list * l_list) {
	
	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}	

	// Keep of track of the current and the previous	
	list_node * previous;
	list_node * current = l_list->sentinel;

	for (int i = 0; i < l_list->length; i++) {
		previous = current;
		current = current->next;	
	}

	int value = current->value;
	free(current);
	previous->next = l_list->sentinel;
	l_list->length--;
	return value;
}

/**
 * Return the first value in the list
 */
int front(linked_list * l_list) {
	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}
	return l_list->sentinel->next->value;
}

/**
 * Return the last value in the list
 */
int back(linked_list * l_list) {
	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}
	
	list_node * node = l_list->sentinel;

	for (int i = 0; i < l_list->length; i++) {
		node = node->next;	
	}
	return node->value;
}

/**
 * Add an item to the front of the list
 */
void insert(linked_list * l_list, int index, int value) {

	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}	

	// Iterate the list until we reach the
	// node previous to the insertion index 
	list_node * node = l_list->sentinel;
	for (int i = 0; i < index; i++) {
		node = node->next;	
	}

	// Allocate memory for the list
	list_node * new_node = malloc(sizeof(list_node));
	new_node->value = value;	
	
	// Update the next pointers
	new_node->next = node->next;
	node->next = new_node;
	l_list->length++;
}
  
/**
 * Add an item to the front of the list
 */
void erase(linked_list * l_list, int index) {
	
	if (l_list->length == 0) {
		exit(EXIT_FAILURE);	
	}	

	// Keep of track of the current and the previous	
	list_node * previous;
	list_node * current = l_list->sentinel;

	for (int i = 0; i < index + 1; i++) {
		previous = current;
		current = current->next;	
	}
	
	// Update the next pointer
	previous->next = current->next;	
		
	// Free up the memory
	free(current);

	l_list->length--;

}

/**
 * Reverse the list
 */
void reverse(linked_list * l_list) {

	// Check we're dealing with a list
        // of at least two...
	if (l_list->length < 2) {
		return;
	}	
	
	list_node * previous = l_list->sentinel;
        list_node * current = l_list->sentinel->next;
        list_node * next = l_list->sentinel->next->next;
	
	do {
		// Flip the next pointer
		current->next = previous;

		// Move the references along
		previous = current;
		current = next;	
		next = next->next;
	}
	while(previous != l_list->sentinel);
} 



