#include <stdio.h>
#include "linked_list.h"


int main (void) {

	// Create a list
  	linked_list * l_list = create_list();
	
	// Push a few items onto the front of the list
	push_front(l_list, 101);
	push_front(l_list, 54);
	push_front(l_list, 11);
	push_front(l_list, 99);
	push_front(l_list, 73);
	push_front(l_list, 1);
	push_front(l_list, 18);

	pretty_print(l_list);

	return 0;
}


