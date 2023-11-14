#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}*BST, treeType;

BST insert(BST node, int key);
void printInorder(BST node);
void printPreorder(BST node);
void printPostorder(BST node);

int main() {

	BST root = NULL;
	root = insert(root, 50);

}

BST insert(BST node, int key) {
	BST *trav = node;

	while(trav != NULL) {
		if(key > ((*trav)->data)) {
			trav = (*trav)->right;
		} else {
			trav = (*trav)->left;
		}
	}
	BST temp = (BST)malloc(sizeof(treeType));
	if(temp == NULL) {
		printf("Memory allocation failed!");
	} else {
		
		temp->data = key;
		temp->left = NULL;
		temp->right = NULL;
		(*trav) = temp;
		
	}
	return temp;
}
