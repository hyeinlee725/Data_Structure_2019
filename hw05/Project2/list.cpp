#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(NODE * list)
{
	int i = 0;
	printf("(%d:", length_list(list));
	if (list != NULL) {
		int n = length_list(list);
		for (i = 0; i < n-1; i++)
		{
			printf("%d,", list->data);
			list = list->link;
		}
		printf("%d", list->data);
	}
	printf(")\n");
	/*NODE * a = 0;
	for (a = list; a != NULL; a = a->link)
	{
		printf("%d,", a->data);
	}*/
}

int length_list(NODE * list)
{
	int cnt = 0;
	for (; list != NULL; list = list->link) {
		cnt++;
		length_list(list->link);
	}
	return cnt;
}

NODE *nth_list(NODE * list, int n)
{
	int i = 0;
	if (n <= 0 || n > length_list(list))
		return NULL;
	else{//다음리스트로 넘어가게
		for (i = 0; i < n - 1; i++)
		{
			list = list->link;
		}
		return list;
	}
}

NODE *add_list(NODE * list, int item)
{
	NODE * add = (NODE *)malloc(sizeof(NODE));
	add->data = item;
	add->link = list;
	list = add;
	return list;
}

NODE *delete_list(NODE * list)
{
	NODE * del;
	if (list == NULL)
		return NULL;
		del = list;
		list = del->link;
		free(del);
		return list;
}