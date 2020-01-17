#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

void selection_sort(int list[], int n)
{
	int i, j, least, t;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[least] > list[j]) {
				least = j;
			}
		}
		SWAP(list[i], list[least], t);
		print_array(list, n);
	}
}