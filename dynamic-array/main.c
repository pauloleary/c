#include <stdio.h>
#include "dynamic_array.h"


int main (void)
{
	// Create the dynamic array
	dynamic_array * d_array = create_array(4);
	printf("dynamic_array * d_array = create_array(4)\n");
	
	// Print the details
	pretty_print(d_array);	

	// Add an item to the back
	push_back(d_array, 73);
	printf("push_back(d_array, 73)\n");

	// Print the details
	pretty_print(d_array);

	// Add some more items	
	push_back(d_array, 74);
	printf("push_back(d_array, 74)\n");
	push_back(d_array, 75);
	printf("push_back(d_array, 75)\n");
	push_back(d_array, 76);
	printf("push_back(d_array, 76)\n");


	// Print the details
	pretty_print(d_array);
	
	// Add another item
	push_back(d_array, 77);
	printf("push_back(d_array, 77)\n");

	
	// Print the details
	pretty_print(d_array);	

	// Run some gets 
	printf("get(d_array, 0): %d\n", get(d_array, 0));	
	printf("get(d_array, 1): %d\n", get(d_array, 1));	
	printf("get(d_array, 2): %d\n", get(d_array, 2));	
	printf("get(d_array, 3): %d\n", get(d_array, 3));	
	printf("get(d_array, 4): %d\n", get(d_array, 4));	
	
	// Insert a number	
	insert(d_array, 1, 8);
	printf("insert(d_array, 1, 8)\n");

	// Print the details
	pretty_print(d_array);

	// Insert an item at thet start
	push(d_array, 3);
	printf("push(d_array, 3)\n");
	
	// Print the details
	pretty_print(d_array);

	// Retrieve and remove the last item
	printf("pop(d_array): %d\n", pop(d_array));

	// Print the details
	pretty_print(d_array);
	
	// Delete an item
	delete(d_array, 4);
	printf("delete(d_array, 4)\n");

	// Print the details
	pretty_print(d_array);
	
	// Remove all
	remove_all(d_array, 8);
	printf("remove_all(d_array, 8)\n");

	// Print the details
	pretty_print(d_array);


	// Insert a number a few times	
	insert(d_array, 0, 10);
	printf("insert(d_array, 0, 10)\n");
	insert(d_array, 0, 10);
	printf("insert(d_array, 0, 10)\n");
	insert(d_array, 4, 10);
	printf("insert(d_array, 4, 10)\n");
	insert(d_array, 7, 10);
	printf("insert(d_array, 7, 10)\n");

	// Print the details
	pretty_print(d_array);
	
	// Remove all instances of a number
	remove_all(d_array, 10);
	printf("remove_all(d_array, 8)\n");

	// Print the details
	pretty_print(d_array);
	
	// Insert a number
	insert(d_array, 4, 73);
	printf("insert(d_array, 4, 73)\n");

	// Print the details
	pretty_print(d_array);
	
	// Find a number
	printf("find(d_array, 73): %d\n", find(d_array, 73));	

	// Retrieve and remove the last items
	printf("pop(d_array): %d\n", pop(d_array));
	printf("pop(d_array): %d\n", pop(d_array));

	// Print the details
	pretty_print(d_array);

	// Retrieve and remove the last items
	printf("pop(d_array): %d\n", pop(d_array));

	// Print the details
	pretty_print(d_array);

  	return 0;
}


