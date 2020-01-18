#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

void merge(int list[], int left, int mid, int right)
{
	int sort_list[MAX_LIST_LENGTH];//������ ������ ���� �ʿ��ϹǷ� sort_list[]�� �����Ѵ�.
	int l = left, m = mid + 1, i = left;//l�� left, m�� mid + 1, i ���� left�� �ʱ�ȭ�Ѵ�.
	int x = m;//x�� �����ϰ� m���� �ʱ�ȭ �Ѵ�.
	//�̶�, l�� ���ĵ� ���� list[]�� index, m�� ���ĵ� ������ list[]�� index, i�� ������ sort_list[]�� index�̴�.
	while(l <= mid && m <= right) {//l�� mid���� �۰ų� ���� right���� �۰ų� ���� ����(���� �迭�� �ش�Ǵ� ���)
		if (list[l] <= list[m]) {//���� list[l]�� list[m]���� �۰ų� ������
			sort_list[i++] = list[l++];//���� �迭�� sort_list[]�� �����Ѵ�.
		}
		else {//�׷��� ������(������ �迭�� �ش�Ǵ� ���)
			sort_list[i++] = list[m++];//������ �迭�� sort_list[]�� �����Ѵ�.
		}
	}   
	//if (l > mid) {//���� l�� mid���� ũ��(������ �迭�� �ش��ϴ� ���)
	//	for (x = m; x <= right; x++)//x�� m���� right���� ���� ������ ���������� �ݺ�
	//		sort_list[i++] = list[x];//�����ʿ� �����ִ� �迭�� sort_list�� ����
	//}
	if (l > mid && x <= right) {//���� l�� mid���� ũ�ų� x�� m���� right���� ���� ������(������ �迭�� �ش��ϴ� ���)
		sort_list[i++] = list[x++];//�����ʿ� �����ִ� �迭�� sort_list�� ����
	}
	else {//�׷��� ������(���� �迭�� �ش��ϴ� ���)
		for (x = l; x <= mid; x++)//x�� �Ӻ��� mid���� �۰ų� ���� ������ ���������� �ݺ�
			sort_list[i++] = list[x];//���ʿ� �����ִ� �迭�� sort_list�� ����
	}
	for (x = left; x <= right; x++) {//x�� left���� right���� �۰ų� ���� ������ ���������� �ݺ�
		list[x] = sort_list[x];//sort_list[]�� �ִ� ���� ���� �迭�� list[]�� ����
	}
}
