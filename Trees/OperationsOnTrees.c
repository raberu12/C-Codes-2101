//my attempt at tree operations
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node *left; 
	struct node *right;

} Node;

Node* newNode(int key);
Node* insert(Node *node, int key);
void search(Node *node, int key);
Node* Delete(Node *node, int key);
void printInorder(Node *node);

int main() {
	
	Node *root = NULL;
	root = insert(root, 50);

	insert(root, 30);
	insert(root, 20);
	insert(root, 70);
	insert(root, 60);
	

	

	printf("Before deletion: \n");
	printInorder(root);
	printf("\n");

	Delete(root, 70);

	printf("After deletion: \n");
	printInorder(root);
	
	search(root, 20);

	return 0;
}

Node *newNode(int key) {

	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node *insert(Node *node, int key) {
	if(node == NULL) {
		return newNode(key);
	}

	if(key < node->data) {
		node->left = insert(node->left, key);
	} else if(key > node->data) {
		node->right = insert(node->right, key);
	}

	return node;
}

void printInorder(Node *node) {

	if(node != NULL) {
		
		printInorder(node->left);
		printf("%d ", node->data); 	
		printInorder(node->right);
		
	}

}

void search(Node *node, int key) {
	if(node == NULL) {
		printf("\nThat number does not exist\n");
	}

	if(node->data == key) {
		printf("\nNumber exists\n");
	} else if(key > node->data) {
		search(node->right, key);
	} else if(key < node->data) {
		search(node->left, key);
	}

}

Node* Delete(Node *node, int key) {

	//Base case: If NODE is null then return
	if(node == NULL) {
		return node;
	}

	//Checks if key is less than or greater than data to determine which subtree to recursively call from until we reach the node we need to delete from
	if(key > node->data) {
		node->right = Delete(node->right, key);
		return node;
	} else if(key < node->data) {
		node->left = Delete(node->left, key);
		return node;
	}

	//Checks whether there are children in either side of the subtree to determine whether which child to swap from
	//i.e if left is empty replace with right child, and vice-versa
	if(node->left == NULL) {
		Node *temp = node->right;
		free(node);
		return node;
	} else if(node->right == NULL) {
		Node *temp = node->left;
		free(node);
		return temp;
		
	//If both children are present case
	} else {
		Node *nextParent = node;
		Node *successor = node->right;
		while(successor->left != NULL){
			nextParent = successor;
			successor = successor->left;
		}
		if(successor != node){
			nextParent->left = successor->right;
		}else{
			nextParent->right = successor->right;
		}
		node->data = successor->data;
		free(successor);
		return node;
	}

}
