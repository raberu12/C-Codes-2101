//my attempt at a bst
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} tree;

tree *newNode(int key);
tree *insert(tree *node, int key);
tree *search(tree *node, int key);
tree *findSucc(tree *node);
tree *findPred(tree *node);
tree *Delete(tree *node, int key);
void printInorder(tree *node);
void printPreorder(tree *node);
void printPostorder(tree *node);

int main() {
	
	tree *mytree = NULL;
	mytree = insert(mytree, 50);
	
	insert(mytree, 30);
	insert(mytree, 40);
	insert(mytree, 20);
	insert(mytree, 10);
	insert(mytree, 80);
	
	printf("After insertion:\n");
	printPreorder(mytree);
	
	printf("\nAfter deletion:\n");
	Delete(mytree, 30);
	printInorder(mytree);
	
	printf("\n");
	tree *searchedTree = search(mytree, 50);
	printf("\nSearched for: %d", searchedTree->key);
	

	return 0;
}
tree *newNode(int key) {
	tree *temp = (tree*)malloc(sizeof(tree));
	if(temp == NULL) {return temp;}
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}
tree *insert(tree *node, int key) {
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
tree *search(tree *node, int key){
	if(node == NULL){
		printf("Tree empty!");
		return node;
	}
	if(key < node->key){
		search(node->left, key);
	}else if(key > node->key){
		search(node->right, key);
	}else{
		printf("FOUND!");
	}
	return node;
}
tree *findSucc(tree *node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}
tree *findPred(tree *node){
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}
tree *Delete(tree *node, int key){
	if(node == NULL){
		return node;
	}
	if(node->key < key){
		node->right = Delete(node->right, key);
		return node;
	}else if(node->key > key){
		node->left = Delete(node->left, key);
		return node;
	}
	if(node->left == NULL){
		tree *temp = node->right;
		free(node);
		return temp;
	}else if(node->right == NULL){
		tree *temp = node->left;
		free(node);
		return temp;
	}else{
		tree *temp = findSucc(node->right);
		node->key = temp->key;
		node->right = Delete(node->right, temp->key);	
	}
	return node;
}
void printInorder(tree *node){
	if(node != NULL){
		printInorder(node->left);
		printf("%d ", node->key);
		printInorder(node->right);
	}
}
void printPreorder(tree *node){
	if(node != NULL){
		printf("%d ", node->key);
		printPreorder(node->left);
		printPreorder(node->right);
	}
}
void printPostorder(tree *node){
	if(node != NULL){
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d ", node->key);
	}
}

