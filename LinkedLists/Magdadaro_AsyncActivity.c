#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data;
	struct node *next;

}*LIST, lType;

void initialize(LIST *L);
void insertFirst(LIST *L, int elem);
void insertLast(LIST *L, int elem);
void insertSorted(LIST *L, int elem);
LIST retrieve(LIST L, int position);
LIST deleteNode(LIST *L, int elem);
void displayList(LIST *L);

int main() {

	LIST head;

	initialize(&head);

	printf("Initial LIST:\n");

	insertFirst(&head, 2);
	insertLast(&head, 4);
	insertSorted(&head, 3);

	displayList(&head);

	printf("\nRetrieved Node:\n");
	LIST retrievedNode = retrieve(head, 3);
	printf("%d\n", retrievedNode->data);

	printf("\nDeleted Node:\n");
	LIST deletedNode = deleteNode(&head, 4);
	printf("%d\n", deletedNode->data);

	return 0;
}

void initialize(LIST *L) {

	*L = NULL;

}

void insertFirst(LIST *L, int elem) {

	LIST temp;
	temp = (LIST)malloc(sizeof(lType));
	if(temp != NULL) {
		temp->data = elem;
		temp->next = *L;
		*L = temp;
	} else {
		printf("Memory Allocation Failed!");
	}

}

void insertLast(LIST *L, int elem) {

	LIST temp;
	LIST *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->next) {}
	temp = (LIST)malloc(sizeof(lType));
	if(temp != NULL) {
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	} else {
		printf("Memory Allocation Failed!");
	}

}

void insertSorted(LIST *L, int elem) {

	LIST temp;
	LIST *trav;
	for(trav = L; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next) {}
	temp = (LIST)malloc(sizeof(lType));
	if(temp != NULL) {
		temp->data = elem;
		temp->next = *trav;
		*trav = temp;
	} else {
		printf("Memory Allocation Failed!");
	}

}

LIST retrieve(LIST L, int position) {

	LIST trav;
	int count = 1;
	for(trav = L; trav->next != NULL && count != position; trav = trav->next, count++) {}

	return trav;
}

LIST deleteNode(LIST *L, int elem) {

	LIST *trav;
	for(trav = L; (*trav)->next != NULL && (*trav)->data != elem; trav = &(*trav)->next) {}

	return *trav != NULL ? *trav : NULL;

}

void displayList(LIST *L) {

	LIST *trav;
	int index = 1;
	printf("[LIST POS] - ELEM\n");
	printf("-------------------\n");
	for(trav = L, index = 1; (*trav) != NULL; trav = &(*trav)->next, index++) {
		printf("[%d] - %d\n", index, (*trav)->data);
	}

}



