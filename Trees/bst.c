//my attempt at an BST
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int key;
	struct node *left, *right;

}*tree;

tree newNode(int key);
tree insert(tree node, int key);
void printInorder(tree node);

int main() {

	tree root = NULL;

	root = insert(root, 5);

	insert(root, 3);
	insert(root, 4);
	insert(root, 6);
	insert(root, 7);

	printInorder(root);


}

tree newNode(int key) {

	tree temp = (tree)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;

}

tree insert(tree node, int key) {

	if(node == NULL) {
		return newNode(key);
	}
	if(key < node->key) {
		node->left = insert(node->left, key);
	} else if(key > node->key) {
		node->right = insert(node->right, key);
	}
	return node;
}



void printInorder(tree node) {

	if (node != NULL) {
		printInorder(node->left);
		printf("%d ", node->key);
		printInorder(node->right);
	}

}


