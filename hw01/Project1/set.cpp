#include <stdio.h>
#include <stdlib.h>
#include "set.h"

//====================
SET *create(void)// �� ������ �����Ͽ� return�� 
{
	SET * set = (SET *)malloc(sizeof(SET));//�ϳ��� ������ SET *�� ǥ��, SETũ�⸸ŭ �����Ҵ�
	set -> len = 0;//set�� len�� 0���� �ʱ�ȭ
	return set;//������ ��ȯ
}
//====================
int member(SET * set, int element)
// ���� set�� element�� ���ԵǾ� ������ TRUE�� �׷��� ������ FALSE�� return�� (TRUE �� FALSE�� macro�� ���ǵ�)
{
	int i;
	for (i = 0; i < set->len; i++) {
		if (set->array[i] == element) {
			return TRUE;
		}
	}
		return FALSE;
}
//====================
int length(SET * set)// ���� set�� element�� ������ return��-sum
{
	return set-> len;
	//count++->count�� ���̼��� ��(�� count�ϳ�...)
}
//====================
SET *insert(SET * set, int element)//���� set�� element�� �߰��� �� �� ������ return��
{
	int i;
	for (i = 0; i < set->len; i++) {
		if (set->array[i] == element) {
			return set;
		}
	}						
	set->array[set->len] = element;
	set->len++;
		return set;
	//array���� ������ ���� ���� �ƴ� ������ ���� �� �ٽ� ������
}
//====================
SET *Delete(SET *set, int element)//���� set�� element�� ������ �� �� ������ return��-free-��������
{
	int i;
	for (i = 0; i < set->len; i++) {
		if (set->array[i] == element) {
			for (; i < set->len; i++) {
				set->array[i] = set->array[i + 1];
			}
			set->len--;
		}
	}
			return set;
}
//====================
SET *sunion(SET * set1, SET * set2)//���� set1�� ���� set2�� union�� �� ������ return��-������
{
	int i;
	SET * set3 = create();
	for (i = 0; i < set1->len; i++)
		insert(set3, set1->array[i]);
	for (i = 0; i < set2->len; i++)
		insert(set3, set2->array[i]);
	return set3;
}
//====================
SET *intersection(SET * set1, SET * set2)//���� set1�� ���� set2�� intersection�� �� ������ return��-������
{
	int i, j;
	SET * set4 = create();
	for (i = 0; i < set1->len; i++)
		for (j = 0; j < set2->len; j++)
			if (set1-> array[i] == set2-> array[j])
				insert(set4, set1->array[i]);
	return set4;
	//SET * set4 = set1 == set2
	//return set4;
}
//====================
SET *difference(SET * set1, SET * set2)//���� set1���� ���� set2�� different�� �� ������ return��-������
{
	SET * set5 = create();
	int i;
	for (i = 0; i < set1->len; i++)
		insert(set5, set1->array[i]);
	for (i = 0; i < set2->len; i++)
		Delete(set5, set2->array[i]);
	return set5;
}
//====================
void print(SET * set)
//���� set�� ��� element�� �� �ٿ� �����. �� �� ���� ��ȣ { �� }�� ����ϰ� �� element ���� , ����� 
{
	int i;
	printf("{");
	for (i = 0; i < set->len - 1; i++)
		printf("%d", set->array[i]);
	printf("%d}\n", set->array[set->len-1]);
}
//====================
int main() {
	SET *s1, *s2, *s3, *s4, *s5, *s6;

	//s1
	s1 = create();
	s1 = insert(s1, -10);
	s1 = insert(s1, 30);
	s1 = insert(s1, -20);
	s1 = insert(s1, 5);
	s1 = insert(s1, -20);
	s1 = insert(s1, 90);
	s1 = insert(s1, -70);
	printf("s1=");
	print(s1);

	//s2
	s2 = create();
	s2 = insert(s2, 5);
	s2 = insert(s2, -15);
	s2 = insert(s2, -20);
	s2 = insert(s2, -50);
	s2 = insert(s2, 15);
	s2 = insert(s2, -70);
	s2 = insert(s2, 90);
	s2 = insert(s2, -3);
	printf("s2=");
	print(s2);

	//member
	if (member(s1, 30) == TRUE)
		printf("member(s1, 30)=TRUE\n");
	else if (member(s1, 30) == FALSE)
		printf("member(s1, 30)=FALSE\n");
	else
		printf("member(s1,30)=???\n");

	if (member(s2, -90) == TRUE)
		printf("member(s2, -90)=TRUE\n");
	else if (member(s2, -90) == FALSE)
		printf("member(s2, -90)=FALSE\n");
	else
		printf("member(s2, -90)=???\n");

	//length
	printf("length(s1)=%d\n", length(s1));
	printf("length(s2)=%d\n", length(s2));

	//s3 = s1 U s2
	s3 = sunion(s1, s2);
	printf("s1Us2=");
	print(s3);

	//s4 = s1 ^ s2
	s4 = intersection(s1, s2);
	printf("s1^s2=");
	print(s4);

	//s5 = s1 - s2
	s5 = difference(s1, s2);
	printf("s1-s2=");
	print(s5);

	//s6 = s2 - s1
	s6 = difference(s2, s1);
	printf("s2-s1=");
	print(s6);

	return EXIT_SUCCESS;
}