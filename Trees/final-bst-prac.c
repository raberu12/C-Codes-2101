#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
}Tree;

Tree *newNode(int key);
Tree *insert(Tree *node, int key);
Tree *search(Tree *node, int key);
Tree *findSucc(Tree *node);
Tree *findPred(Tree *node);
Tree *Delete(Tree *node, int key);
void printInorder(Tree *node);
void printPreorder(Tree *node);
void printPostorder(Tree *node);

int main(){
	
	Tree *mytree = NULL;
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
	Tree *searchedTree = search(mytree, 50);
	printf("\nSearched for: %d", searchedTree->key);
	
}

Tree *newNode(int key){
	Tree *temp = (Tree*)malloc(sizeof(Tree));
	if(temp == NULL) {return temp;}
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

Tree *insert(Tree *node, int key){
	if (node == NULL){
		return newNode(key);
	}
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	if(key > node->key){
		node->right = insert(node->right, key);
	}
	return node;
}

Tree *search(Tree *node, int key){
	if(node == NULL){
		printf("TREE EMPTY");
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

Tree *findSucc(Tree *node){
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}

Tree *findPred(Tree *node){
	while(node->right != NULL){
		node = node->right;
	}	
	return node;
}

Tree *Delete(Tree *node, int key){
	if(node == NULL){
		return node;
	}
	if(node->key < key){
		node->right = Delete(node->right, key);
		return node;
	}else if(node->key > key){
		node->left = Delete(node->left, key);
	}
	if(node->left == NULL){
		Tree *temp = node->right;
		free(node);
		return temp;
	}else if(node->right == NULL){
		Tree *temp = node->left;
		free(node);
		return temp;
	}else{
		Tree *temp = findSucc(node->right);
		node->key = temp->key;
		node->right = Delete(node->right, temp->key);
	}
	return node;
}

void printInorder(Tree *node){
	if(node != NULL){
		printInorder(node->left);
		printf("%d ", node->key);
		printInorder(node->right);
	}
}

void printPreorder(Tree *node){
		if(node != NULL){
		printf("%d ", node->key);
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

void printPostorder(Tree *node){
		if(node != NULL){
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d ", node->key);
	}
}



