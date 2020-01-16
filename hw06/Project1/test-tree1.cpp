#include <stdio.h>
#include <stdlib.h>
#include "tree1.h"

int main()
{
	int i;
	TREE t1;

	printf("===== test-tree1 =====\n");

	init_tree(&t1);
	for (i = 1; i < MAX_TREE_SIZE - 3; i++)
		t1.data[i] = 10 + i;

	printf("preorder=");
	preorder_tree(&t1, 1);
	printf("\n");

	printf("inorder=");
	inorder_tree(&t1, 1);
	printf("\n");

	printf("postorder=");
	postorder_tree(&t1, 1);
	printf("\n");

	return EXIT_SUCCESS;
}