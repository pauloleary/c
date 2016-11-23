#include <stdio.h>
#include "dynamic_array.h"


int main (void)
{
	// Create the dynamic array
	dynamic_array * d_array = create_array(10);
	
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
	push_back(d_array, 77);
	
	// Print the details
	pretty_print(d_array);	
	
  	return 0;
}

