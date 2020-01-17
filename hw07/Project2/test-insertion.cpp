#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

int grade[MAX_LIST_LENGTH] = {
	5, 3, 8, 1, 2, 7
};

int main()
{
	print_array(grade, MAX_LIST_LENGTH);
	insertion_sort(grade, MAX_LIST_LENGTH);

	return EXIT_SUCCESS;
}

void print_array(int list[], int n)
{
	static int step = 0;
	int i;
	printf("step %d: ", step++);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}