#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

	int data;
	struct node *link;

}*nodePtr;

void initList(nodePtr *L) {

	*L = NULL;

}

void displayAll(nodePtr *L) {

	nodePtr *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->link) {
		printf("%d\n", (*trav)->data);
	}
	if(*L == NULL){
		printf("NULL");
	}
}

void insertFirst(nodePtr *L, int elem) {

	nodePtr newNode = (nodePtr)malloc(sizeof(struct node));
	if(newNode != NULL) {
		newNode->data = elem;
		newNode->link = *L;
		*L = newNode;
	}
}

void deleteLast(nodePtr *L) {

	nodePtr *trav;
	nodePtr temp;
	for(trav = L; (*trav)->link != NULL; trav = &(*trav)->link) {}
	temp = *trav;
	*trav = temp->link;
	free(temp);
}

void deleteFirst(nodePtr *L) {

	if(*L != NULL) {
		nodePtr temp;
		temp = *L;
		*L = temp->link;
		free(temp);
	}
}

void deleteAll(nodePtr *L){
	if(*L != NULL){
		nodePtr temp;
		for(; *L != NULL;){
			temp = *L;
			*L = temp->link;
			free(temp);
		}
	}
	
}

int main() {

	nodePtr hey;
	
	initList(&hey);

	insertFirst(&hey, 4);
	insertFirst(&hey, 3);
	insertFirst(&hey, 2);

	displayAll(&hey);

	deleteLast(&hey);
	deleteFirst(&hey);
	
	displayAll(&hey);
	
	deleteAll(&hey);

	displayAll(&hey);

}
