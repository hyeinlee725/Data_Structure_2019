#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

void bubble_sort(int list[], int n)
{
	int i, j, t;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], t);
			}
		}
		print_array(list, n);
	}
}