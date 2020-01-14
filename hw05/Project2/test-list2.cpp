//#include <stdio.h>
//#include <stdlib.h>
//#include "list.h"
//
//int main()
//{
//	NODE *l1, *l2, *l3, *l4;
//	NODE *p;
//
//	//nth_list
//	printf("===== test-list2: nth_list =====\n");
//
//	l1 = (NODE *)malloc(sizeof(NODE));
//	l1->data = 10;
//	l1->link = NULL;
//
//	l2 = (NODE *)malloc(sizeof(NODE));
//	l2->data = 20;
//	l2->link = NULL;
//	l1->link = l2;
//
//	l3 = (NODE *)malloc(sizeof(NODE));
//	l3->data = 30;
//	l3->link = NULL;
//	l2->link = l3;
//
//	l4 = (NODE *)malloc(sizeof(NODE));
//	l4->data = 40;
//	l4->link = NULL;
//	l3->link = l4;
//	
//	p = nth_list(l1, 0);
//	if (p == NULL)
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 1);
//	if ((p != NULL) && (p->data == 10))
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 3);
//	if ((p != NULL) && (p->data == 30))
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//	p = nth_list(l1, 5);
//	if (p == NULL)
//		printf("OK: nth_list\n");
//	else
//		printf("ERROR: nth_list\n");
//
//
//	return EXIT_SUCCESS;
//}