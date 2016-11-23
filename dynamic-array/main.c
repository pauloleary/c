#include <stdio.h>
#include "dynamic_array.h"


int main (void)
{
	// Create the dynamic array
	dynamic_array * d_array = create_array(4);
	
	// Print the details
	pretty_print(d_array);	

	// Add an item to the back
	push_back(d_array, 73);

	// Print the details
	pretty_print(d_array);

	// Add some more items	
	push_back(d_array, 74);
	push_back(d_array, 75);
	push_back(d_array, 76);

	// Print the details
	pretty_print(d_array);
	
	// Add another item
	push_back(d_array, 77);
	
	// Print the details
	pretty_print(d_array);	

	printf("get(d_array, 0): %d\n", get(d_array, 0));	
	printf("get(d_array, 1): %d\n", get(d_array, 1));	
	printf("get(d_array, 2): %d\n", get(d_array, 2));	
	printf("get(d_array, 3): %d\n", get(d_array, 3));	
	printf("get(d_array, 4): %d\n", get(d_array, 4));	
	printf("get(d_array, 5): %d\n", get(d_array, 5));	
	printf("get(d_array, -1): %d\n", get(d_array, -1));	
	
	// Insert a number	
	insert(d_array, 1, 7);

	// Print the details
	pretty_print(d_array);

  	return 0;
}


