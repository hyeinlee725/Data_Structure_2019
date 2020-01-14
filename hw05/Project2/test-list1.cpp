//#include <stdio.h>
//#include <stdlib.h>
//#include "list.h"
//
//int main()
//{
//	NODE *l1, *l2, *l3, *l4;
//
//	//length_list
//	printf("===== test-list1: length_list =====\n");
//
//	l1 = NULL;
//	if (length_list(l1) != 0) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l1 = (NODE *)malloc(sizeof(NODE));
//	l1->data = 10;
//	l1->link = NULL;
//	if (length_list(l1) != 1) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l2 = (NODE *)malloc(sizeof(NODE));
//	l2->data = 20;
//	l2->link = NULL;
//	l1->link = l2;
//	if (length_list(l1) != 2) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l3 = (NODE *)malloc(sizeof(NODE));
//	l3->data = 30;
//	l3->link = NULL;
//	l2->link = l3;
//	if (length_list(l1) != 3) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	l4 = (NODE *)malloc(sizeof(NODE));
//	l4->data = 40;
//	l4->link = NULL;
//	l3->link = l4;
//	if (length_list(l1) != 4) {
//		printf("ERROR: length_list\n");
//		return EXIT_FAILURE;
//	}
//	print_list(l1);
//
//	return EXIT_SUCCESS;
//}