#ifndef DYNAMIC_ARRAY_H_   
#define DYNAMIC_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamic_array {

	int length;
	int capacity;
	int *array;

} dynamic_array;

dynamic_array * create_array(int capacity);

void pretty_print(dynamic_array * d_array);

int get_length(dynamic_array * d_array);

int get_capacity(dynamic_array * d_array);

bool is_empty(dynamic_array * d_array);

void push_back(dynamic_array * d_array, int item);

#endif 

