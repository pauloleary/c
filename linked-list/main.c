#include <stdio.h>
#include "linked_list.h"


int main (void) {

	// Create a list
  	linked_list * l_list = create_list();
	printf("linked_list * l_list = create_list()\n");
	
	pretty_print(l_list);

	// Push a few items onto the front of the list
	push_front(l_list, 101);
	printf("push_front(l_list, 101)\n");
	push_front(l_list, 54);
	printf("push_front(l_list, 54)\n");
	push_front(l_list, 11);
	printf("push_front(l_list, 11)\n");
	push_front(l_list, 75);
	printf("push_front(l_list, 75)\n");
	push_front(l_list, 73);
	printf("push_front(l_list, 73)\n");
	push_front(l_list, 1);
	printf("push_front(l_list, 1)\n");
	push_front(l_list, 18);
	printf("push_front(l_list, 18)\n");

	pretty_print(l_list);
	
	printf("value_at(l_list, 0): %d\n", value_at(l_list, 0));
	printf("value_at(l_list, 1): %d\n", value_at(l_list, 1));
	printf("value_at(l_list, 4): %d\n", value_at(l_list, 4));
	printf("value_at(l_list, 6): %d\n", value_at(l_list, 6));
	
	// printf("pop_front(l_list): %d\n", pop_front(l_list));

	pretty_print(l_list);

	printf("pop_back(l_list): %d\n", pop_back(l_list));

	pretty_print(l_list);

	printf("front(l_list): %d\n", front(l_list));

	printf("back(l_list): %d\n", back(l_list));

	push_back(l_list, 99);
	printf("push_front(l_list, 99)\n");
		
	pretty_print(l_list);

	insert(l_list, 3, 74);
	printf("insert(l_list, 3, 74)\n");
	
	pretty_print(l_list);

	erase(l_list, 5);
	printf("erase(l_list, 5)\n");
	
	pretty_print(l_list);

	reverse(l_list);
	printf("reverse(l_list)\n");
	
	pretty_print(l_list);


	return 0;
}


