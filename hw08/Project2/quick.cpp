#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

int partition(int list[], int left, int right)
{
	int low = left, high = right + 1, pivot = list[left];
	int t; 
	do {     
		do {
			low++;
		}
		while(low <= right && list[low] < pivot);     
		do {
			high--;
		}
		while(high >= left && list[high] > pivot);     
		if (low < high) {
			SWAP(list[low], list[high], t);
		}
	} 
	while(low < high); 
	SWAP(list[left], list[high], t);
	return high;
}