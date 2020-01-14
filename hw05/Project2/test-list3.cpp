#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
	{
		node *l1;

		//nth_list
		printf("===== test-list3: add_list =====\n");

		l1 = NULL;
		print_list(l1);

		l1 = add_list(l1, 40);
		print_list(l1);

		l1 = add_list(l1, 30);
		print_list(l1);

		l1 = add_list(l1, 20);
		print_list(l1);

		l1 = add_list(l1, 10);
		print_list(l1);

		return EXIT_SUCCESS;
	}