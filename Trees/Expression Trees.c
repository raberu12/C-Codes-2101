//expression trees
#include <stdio.h>
#include <stdlib.h>
typedef struct node {

	char key;
	struct node *left, *right, *next;

}NODE;

NODE* head = NULL;

NODE *newNode(int key);
void printInorder(NODE* node);
void push(NODE* node);
NODE *pop();


int main() {
	char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
	int length = sizeof(s)/sizeof(s[0]);
	NODE *x, *y, *z;
	int i;	
	for(i = 0; i < length; i++) {
		if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^') {
			z = newNode(s[i]);
			x = pop();
			y = pop();
			z->left = y;
			z->right = x;
			push(z);
		} else {
			z=newNode(s[i]);
			push(z);
		}
	}
	printf("Inorder Traversal of Tree: \n");
	printInorder(z);
	return 0;

}

NODE *newNode(int key) {

	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	temp->next = NULL;

	return temp;
}

void printInorder(NODE* node) {
	if(node != NULL) {
		printInorder(node->left);
		printf("%c ", node->key);
		printInorder(node->right);
	} else {
		return;
	}
}

void push(NODE* node) {
	if (head == NULL) {
		head = node;
	} else {
		node->next = head;
		head = node;
	}
}

NODE *pop() {
	NODE *popped = head;
	head = head->next;
	return popped;
}

