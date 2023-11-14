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
int height(tree node);

int main() {

	tree root = NULL;

	insert(root, 5);

	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 6);
	insert(root, 7);

	printInorder(root);
	
	printf("\nThe height of this tree is = %d", height(root));

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

	if(node != NULL) {
		printInorder(node->left);
		printf("%d ", node->key);
		printInorder(node->right);
	}
}

int height(tree node) {

	int count = 0;

	if(node != NULL) {
		
		int left = height(node->left);
		int right = height(node->right);
		
		if(left > right){
			count = left + 1;
		}else{
			count = right + 1;
		}
	}

	return count;	
}


