#include <stdio.h>
#include <stdlib.h>
#include "tree3.h"

NODE *insert_node(NODE * root, int key)
{
	NODE * key_node = (NODE *)malloc(sizeof(NODE));
	key_node->key = key;
	key_node->left = NULL;
	key_node->right = NULL;
	while (root != NULL && root->key != key) {
		if (key == root->key)
			return root;
		else if (key < root->key) {
			root->left = insert_node(root->left, key);
			return root;
		}
		else {
			root->right = insert_node(root->right, key);
			return root;
		}
	}
	return key_node;
	/*if (root == NULL) {
		NODE * key_node = (NODE *)malloc(sizeof(NODE));
		key_node->key = key;
		key_node->left = NULL;
		key_node->right = NULL;
		return key_node;
	}
	while (root != NULL && root->key != key) {
		if (key == root->key)
			return root;
		else if (key < root->key) {
			root->left = insert_node(root->left, key);
			return root;
		}
		else {
			root->right = insert_node(root->right, key);
			return root;
		}
	}*/
}



void print_inorder(NODE * root)
{
	if (root == NULL)
		return;
	else/* if (root->key != NULL)*/ {
		print_inorder(root->left);
		printf("(%d)", root->key);
		print_inorder(root->right);
	}
}