#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

void merge(int list[], int left, int mid, int right)
{
	int sort_list[MAX_LIST_LENGTH];//정렬할 공간이 따로 필요하므로 sort_list[]을 선언한다.
	int l = left, m = mid + 1, i = left;//l은 left, m은 mid + 1, i 역시 left로 초기화한다.
	int x = m;//x를 선언하고 m으로 초기화 한다.
	//이때, l은 정렬된 왼쪽 list[]의 index, m은 정렬된 오른쪽 list[]의 index, i는 정렬할 sort_list[]의 index이다.
	while(l <= mid && m <= right) {//l이 mid보다 작거나 같고 right보다 작거나 같을 동안(왼쪽 배열에 해당되는 경우)
		if (list[l] <= list[m]) {//만약 list[l]이 list[m]보다 작거나 같으면
			sort_list[i++] = list[l++];//왼쪽 배열을 sort_list[]로 복사한다.
		}
		else {//그렇지 않으면(오른쪽 배열에 해당되는 경우)
			sort_list[i++] = list[m++];//오른쪽 배열을 sort_list[]로 복사한다.
		}
	}   
	//if (l > mid) {//만약 l이 mid보다 크면(오른쪽 배열에 해당하는 경우)
	//	for (x = m; x <= right; x++)//x는 m부터 right보다 작을 때가지 후위연산을 반복
	//		sort_list[i++] = list[x];//오른쪽에 남아있던 배열을 sort_list로 복사
	//}
	if (l > mid && x <= right) {//만약 l이 mid보다 크거나 x가 m부터 right보다 작을 때까지(오른쪽 배열에 해당하는 경우)
		sort_list[i++] = list[x++];//오른쪽에 남아있던 배열을 sort_list로 복사
	}
	else {//그렇지 않으면(왼쪽 배열에 해당하는 경우)
		for (x = l; x <= mid; x++)//x는 ㅣ부터 mid보다 작거나 같을 때까지 후위연산을 반복
			sort_list[i++] = list[x];//왼쪽에 남아있던 배열을 sort_list로 복사
	}
	for (x = left; x <= right; x++) {//x는 left부터 right보다 작거나 같을 때까지 후위연산을 반복
		list[x] = sort_list[x];//sort_list[]에 있는 값을 원래 배열인 list[]로 복사
	}
}
