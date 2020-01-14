//#include <stdio.h>
//#include <stdlib.h>
//#include "list.h"
//
//int main()
//	{
//		NODE *l1, *l2, *l3, *l4;
//
//		//print_list
//		printf("===== test-list0: print_list =====\n");
//
//		l1 = NULL;
//		print_list(l1);
//
//		l1 = (NODE *)malloc(sizeof(NODE));
//		l1->data = 10;
//		l1->link = NULL;
//		print_list(l1);
//
//		l2 = (NODE *)malloc(sizeof(NODE));
//		l2->data = 20;
//		l2->link = NULL;
//		l1->link = l2;
//		print_list(l1);
//
//		l3 = (NODE *)malloc(sizeof(NODE));
//		l3->data = 30;
//		l3->link = NULL;
//		l2->link = l3;
//		print_list(l1);
//
//		l4 = (NODE *)malloc(sizeof(NODE));
//		l4->data = 40;
//		l4->link = NULL;
//		l3->link = l4;
//		print_list(l1);
//
//		return EXIT_SUCCESS;
//	}