#include <stdio.h>
#include <stdlib.h>
#include "tree1.h"

void init_tree(TREE * t)
{
	int i = 0;
	for (i = 0; i < MAX_TREE_SIZE; i++) {
		t->data[i] = -1;
	}
}

void preorder_tree(TREE * t, int root)
{
	if (root > MAX_TREE_SIZE - 3)
		return ;
	else if (t->data[root] != -1) {
		printf("(%d)", t->data[root]);
		preorder_tree(t, root * 2);
		preorder_tree(t, root * 2 + 1);
	}
}

void inorder_tree(TREE * t, int root)
{
	if (root > MAX_TREE_SIZE - 3)
		return;
	else if (t->data[root] != -1) {
		inorder_tree(t, root * 2);
		printf("(%d)", t->data[root]);
		inorder_tree(t, root * 2 + 1);
	}
}

void postorder_tree(TREE * t, int root)
{
	if (root > MAX_TREE_SIZE - 3)
		return;
	else if (t->data[root] != -1) {
		postorder_tree(t, root * 2);
		postorder_tree(t, root * 2 + 1);
		printf("(%d)", t->data[root]);
	}
}
