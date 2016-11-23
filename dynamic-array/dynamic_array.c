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
		printf("\t        : [%d]: %d\n", i, *(d_array->array + i));
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

void push_back(dynamic_array * d_array, int item) {
	
	// Check if there's room at the inn...
	if (is_at_capacity(d_array)) {
		// TODO: Double array capacity		
	}

	// Add it at the end
        *(d_array->array + d_array->length) = item;
	d_array->length++;
}



