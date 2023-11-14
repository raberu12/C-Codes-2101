#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}*BST, treeType;

BST isMember(BST node, int key);
BST newNode(int key); //helper function for insertion;
BST insert(BST node, int key);
void printInorder(BST node);
void printPreorder(BST node);
void printPostorder(BST node);

int main() {

	BST root = NULL;
	root = insert(root, 50);

	insert(root, 20);
	insert(root, 12);
	insert(root, 55);
	insert(root, 60);
	insert(root, 75);
	insert(root, 5);
	isMember(root, 20);
	isMember(root, 13);
	printf("-------------------------------------------");
	printf("\nInorder Traversal of Tree:\n\n");
	printInorder(root);
	printf("\n\nPreorder Traversal of Tree:\n\n");
	printPreorder(root);
	printf("\n\nPostorder Traversal of Tree:\n\n");
	printPostorder(root);


	return 0;
}

BST isMember(BST node, int key) {
	if(node == NULL) {
		printf("\nChecking if %d is member:", key);
		printf(" Key %d not found!\n", key);
		return NULL;
	}

	if(node->data == key) {
		printf("\nChecking if %d is member:", key);
		printf(" %d is a member of the tree\n", node->data);
		return node;
	}
	
	if(key < node->data) {
		node = isMember(node->left, key);
	} else if(key > node->data) {
		node = isMember(node->right, key);
	}
	return node;
}

BST newNode(int key) {

	BST temp = (BST)malloc(sizeof(treeType));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

BST insert(BST node, int key) {
	if(node == NULL) {
		return newNode(key);
	}
	if(key > node->data) {
		node->right = insert(node->right, key);
	} else if(key < node->data) {
		node->left = insert(node->left, key);
	}
	return node;
}

void printInorder(BST node) {

	if(node != NULL) {
		printInorder(node->left);
		printf("%d ", node->data);
		printInorder(node->right);
	}

}

void printPreorder(BST node) {
	if(node != NULL) {

		printf("%d ", node->data);
		printPreorder(node->left);
		printPreorder(node->right);

	}
}

void printPostorder(BST node) {
	if(node != NULL) {

		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d ", node->data);

	}
}

