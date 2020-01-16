#include <stdio.h>
#include <stdlib.h>
#include "tree2.h"

NODE *create_node(int item)
{
	NODE * tree_node = (NODE *)malloc(sizeof(NODE));
	tree_node->data = item;
	tree_node->left = NULL;
	tree_node->right = NULL;
	return tree_node;
}

void add_child(NODE * root, NODE *left, NODE * right)
{
	/*if (right == NULL || left == NULL) {
		root->left = left;
		root->right = right;
	}
	else {
		root->left = left;
		left->left = NULL;
		left->right = NULL;
		root->right = right;
		right->left = NULL;
		right->right = NULL;
	}*/
	root->left = left;
	root->right = right;
}

int sum_tree(NODE * root)
{
	/*int sum = 0;
	if (root != NULL) {
		sum = sum + root->data + sum_tree(root->left) + sum_tree(root->right);
	}
	return sum;*/
	int sum = 0;
	if (root == NULL)
		return sum;
	else {
		sum = sum + root->data + sum_tree(root->left) + sum_tree(root->right);
		//sum = sum + sum_tree(root->left) + sum_tree(root->right);
	}
	/*else if (root->left != NULL && root->right != NULL) {
		sum = root->left->data + root->right->data;
		sum = sum + sum_tree(root->left) + sum_tree(root->right);
	}
	else if (root->left != NULL && root->right == NULL) {
		sum = root->left->data;
		sum = sum + sum_tree(root->left);
	}
	else if (root->left == NULL && root->right != NULL) {
		sum = root->right->data;
		sum = sum + sum_tree(root->right);
	}*/
	return sum;
}