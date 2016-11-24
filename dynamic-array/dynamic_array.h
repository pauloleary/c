#ifndef DYNAMIC_ARRAY_H_   
#define DYNAMIC_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * Struct representing a dynamic array 
 * that contains an array and metadata 
 */
typedef struct dynamic_array {

	int length;
	int capacity;
	int *array;

} dynamic_array;

/** 
 * Create and return array 
 */
dynamic_array * create_array(int capacity);

/** 
 * Pretty pring array metadata and contents
 */
void pretty_print(dynamic_array * d_array);

/** 
 * Get the length of the array
 */
int get_length(dynamic_array * d_array);

/** 
 * Get the capacity of the array
 */
int get_capacity(dynamic_array * d_array);

/** 
 * Determine if the array is emtpy
 */
bool is_empty(dynamic_array * d_array);

/** 
 * Insert an item at an index
 */
void insert(dynamic_array * d_array, int index, int item);

/** 
 * Insert an item at the back of the array
 */
void push_back(dynamic_array * d_array, int item);

/** 
 * Get and return an item at an index
 */
int get(dynamic_array * d_array, int index);

/** 
 * Add an item to the start of the array
 */
void push(dynamic_array * d_array, int item);

#endif 

