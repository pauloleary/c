#include "dynamic_array.h"



dynamic_array * create_array(int capacity) {
	dynamic_array * d_array = malloc(sizeof(dynamic_array));
        d_array->length = 0;
	d_array->capacity = capacity;
        d_array->array =  malloc(capacity * sizeof(int));
	return d_array;
}

void pretty_print(dynamic_array * d_array) {
	printf("\t************************\n");
	printf("\t  Length: %d\n", d_array->length);
	printf("\tCapacity: %d\n", d_array->capacity);
	printf("\tIs Emtpy: %d\n", is_empty(d_array));
	// printf("\t   Items: %d\n", d_array->array);
	
	// Iterate items and create a string
	for (int i = 0; i < d_array->length; i++) {
		printf("\t          [%d]: %d\n", i, *(d_array->array + i));
	}
	
}

int get_length(dynamic_array * d_array) {
	return d_array->length;
}

int get_capacity(dynamic_array * d_array) {
	return d_array->capacity;
}

bool is_empty(dynamic_array * d_array) {
	return (d_array->length == 0) ? 0 : 1;	
}

bool is_at_capacity(dynamic_array * d_array) {
	return (d_array->length == d_array->capacity);
}

void resize(dynamic_array * d_array, int new_capacity) {
	int *new_array = malloc(new_capacity * sizeof(int));	
	for (int i = 0; i < d_array->capacity; i++) {
		*(new_array + i) = *(d_array->array + i);
	}
	free(d_array->array);
	d_array->array = new_array;
	d_array->capacity = new_capacity;
}

void push_back(dynamic_array * d_array, int item) {
	
	// Check if there's room at the inn...
	if (is_at_capacity(d_array)) {
		resize(d_array, d_array->capacity * 2);
	}

	// Add it at the end
        *(d_array->array + d_array->length) = item;
	d_array->length++;
}

int get(dynamic_array * d_array, int index) {
	if (index < 0 || index >= d_array->length) {
		return -1;
	}
	return *(d_array->array + index);
}

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


