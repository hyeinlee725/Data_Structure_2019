#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

void insertion_sort(int list[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++) {
		t = list[i];
		for (j = i - 1; list[j] > t && j >= 0; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = t;
		print_array(list, n);
	}
}