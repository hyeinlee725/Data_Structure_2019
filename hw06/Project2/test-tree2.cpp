#include <stdio.h>
#include <stdlib.h>
#include "tree2.h"

int main()
{
	int sum;
	NODE *t0, *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10, *t11;
	
	printf("===== test-tree2 =====\n");

	t0 = create_node(0);
	t1 = create_node(10);
	t2 = create_node(20);
	t3 = create_node(30);
	t4 = create_node(40);
	t5 = create_node(50);
	t6 = create_node(60);
	t7 = create_node(70);
	t8 = create_node(80);
	t9 = create_node(90);
	t10 = create_node(100);
	t11 = create_node(110);
	/*printf("%d %d %d %d %d %d %d %d %d %d %d %d\n", t0->data, t1->data, t2->data, t3->data, t4->data, t5->data, t6->data
		, t7->data, t8->data, t9->data, t10->data, t11->data);*/

	add_child(t3, t7, t8);
	add_child(t4, t9, t10);
	add_child(t5, t11, NULL);
	add_child(t1, t3, t4);
	add_child(t2, t5, t6);
	add_child(t0, t1, t2);

	/*printf("%d %d %d %d %d %d %d %d %d %d %d\n",
		t0->left->data, t0->right->data, t1->left->data, t1->right->data, t2->left->data, t2->right->data,  
		t3->left->data, t3->right->data, t4->left->data, t4->right->data, t5->left->data);*/

	sum = sum_tree(t0);
	printf("sum_tree(t0)=%d\n", sum);

 	sum = sum_tree(t1);
	printf("sum_tree(t1)=%d\n", sum);

	sum = sum_tree(t2);
	printf("sum_tree(t2)=%d\n", sum);

	sum = sum_tree(t4);
	printf("sum_tree(t4)=%d\n", sum);

	sum = sum_tree(t5);
	printf("sum_tree(t5)=%d\n", sum);

	return EXIT_SUCCESS;
}