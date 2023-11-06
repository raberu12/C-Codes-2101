//C program for tree traversal
#include <stdio.h>
#include <stdlib.h>

struct node { //def of a binary tree
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data);
void printInorder(struct node* node);

int main() {
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	root->right->right = newNode(6);
	
	printf("Inorder Traversal of binary tree is \n");
	printInorder(root);
	return 0;

}

struct node* newNode(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void printInorder(struct node* node) {
	if (node != NULL) {
		printInorder(node->left);
		printf("%d ", node->data);
		printInorder(node->right);
	} else {
		return;
	}
}

