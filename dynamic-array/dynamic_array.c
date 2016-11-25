#include "dynamic_array.h"


/** 
 * Create an array and allocalte the memory 
 */
dynamic_array * create_array(int capacity) {
	dynamic_array * d_array = malloc(sizeof(dynamic_array));
        d_array->length = 0;
	d_array->capacity = capacity;
        d_array->array =  malloc(capacity * sizeof(int));
	return d_array;
}

/** 
 * Pretty print the array
 */
void pretty_print(dynamic_array * d_array) {
	
	// Print some of the meta data
	printf("**************************************\n");
	printf("\t  Length: %d\n", d_array->length);
	printf("\tCapacity: %d\n", d_array->capacity);
	printf("\tIs Emtpy: %d\n", is_empty(d_array));

	// Iterate items and create a string
	for (int i = 0; i < d_array->length; i++) {
		printf("\t          [%d]: %d\n", i, *(d_array->array + i));
	}
	
	printf("**************************************\n");
}

/** 
 * Get the length of the array  
 */
int get_length(dynamic_array * d_array) {
	return d_array->length;
}

/** 
 * Get the capacity of the array
 */
int get_capacity(dynamic_array * d_array) {
	return d_array->capacity;
}

/** 
 * Determine if the array is empty  
 */
bool is_empty(dynamic_array * d_array) {
	return (d_array->length == 0) ? 0 : 1;	
}

/** 
 * Determine if the array is at capacity
 */
bool is_at_capacity(dynamic_array * d_array) {
	return (d_array->length == d_array->capacity);
}

/** 
 * Determine if the array is at capacity
 */
bool is_oversize(dynamic_array * d_array) {
	return (d_array->length <= d_array->capacity / 4);
}

/** 
 * Resize the array - O(n)
 */
void resize(dynamic_array * d_array, int new_capacity) {
	int *new_array = malloc(new_capacity * sizeof(int));	
	for (int i = 0; i < d_array->capacity; i++) {
		*(new_array + i) = *(d_array->array + i);
	}
	free(d_array->array);
	d_array->array = new_array;
	d_array->capacity = new_capacity;
}

/** 
 * Add an item to the end of the array 
 * Worse case - O(n)
 * Best case - 0(1)
 */
void push_back(dynamic_array * d_array, int item) {
	
	// Check if there's room at the inn...
	if (is_at_capacity(d_array)) {
		resize(d_array, d_array->capacity * 2);
	}

	// Add it at the end
        *(d_array->array + d_array->length) = item;
	d_array->length++;
}

/** 
 * Get the item at an index from the array - O(1)
 */
int get(dynamic_array * d_array, int index) {
	if (index < 0 || index >= d_array->length) {
		exit(EXIT_FAILURE);
	}
	return *(d_array->array + index);
}

/** 
 * Insert an item at a given index - O(n)
 */
void insert(dynamic_array * d_array, int index, int item) {

	// Check if there's room at the inn...
	if (is_at_capacity(d_array)) {
		resize(d_array, d_array->capacity * 2);
	}

	// Shift the items in front forward an index
	for (int i = d_array->length - 1; i >= index; i--) {
		*(d_array->array + i + 1) = *(d_array->array + i);
	}
	
	// Put the at desired index 
	*(d_array->array + index) = item;
	d_array->length++;
}

/** 
 * Add an item to the start of the array - 0(n)
 */
void push(dynamic_array * d_array, int item) {
	insert(d_array, 0, item);	
}

/** 
 * Remove and return the last item in the array - O(1)
 */
int pop(dynamic_array * d_array) {
	int value = *(d_array->array + d_array->length - 1);	
	d_array->length--;

	// Check if we're too big...
	if (is_oversize(d_array)) {
		resize(d_array, d_array->capacity / 2);
	}

	return value;
}

/**
 * Delete item at an index - 0(n)
 */
void delete(dynamic_array * d_array, int index) {
	
	// Shift the items in front forward an index
	for (int i = index; i < d_array->length; i++) {
		*(d_array->array + i) = *(d_array->array + i + 1);
	}
	
	d_array->length--;

	// Check if we're too big...
	if (is_oversize(d_array)) {
		resize(d_array, d_array->capacity / 2);
	}

}

/**
 * Remove all instances of value - O(n)
 */
void remove_all(dynamic_array * d_array, int value) {
	
	int shift_count = 0;
	for (int i = 0; i < d_array->length; i++) {
		int curr_value = *(d_array->array + i);
		printf("\ti = %d : shift_count = %d : curr_value = %d\n", 
                	i, shift_count, curr_value);
		*(d_array->array + i - shift_count) = *(d_array->array + i);
		if (curr_value == value) {
			shift_count++;	
		}

	}
	d_array->length -= shift_count;

	// Check if we're too big...
	if (is_oversize(d_array)) {
		resize(d_array, d_array->capacity / 2);
	}

}

/**
 * Find the index of the first instance of value
 */
int find(dynamic_array * d_array, int value) {

	for (int i = 0; i < d_array->length; i++) {
		int curr_value = *(d_array->array + i);
		if (curr_value == value) {
			return i;	
		}

	}
	return -1;	

}


