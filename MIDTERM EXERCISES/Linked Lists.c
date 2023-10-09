#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *link;
} ctype, *List;

void initList(List *L);
void insertFirst(List *L, char elem);
void displayList(List L);
void display(List *L);
void insertLast(List *L, char elem);
void deleteFirst(List *L);
void deleteLast(List *L);


int main() {
	List L;
	List *p = &L;
	List q = L;
	initList(&L);
	insertFirst(&L, 'E');
	insertFirst(&L, 'P');
	insertFirst(&L, 'O');
	insertFirst(&L, 'H');
	insertLast(&L, 'S');
	deleteFirst(&L);
	deleteLast(&L);
	displayList(L);


}

void initList(List *L) {
	(*L) = NULL;
}

void insertFirst(List *L, char elem) {
	List temp =(List)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->elem = elem;
		temp->link = *L;
		*L = temp;
	}
}
void displayList(List L) {
	List trav;
	for(trav = L ; trav != NULL; trav = trav->link) {
		printf("%c", trav->elem);
	}
}

void display(List *L) {
	List *trav;
	for(trav = L; (*trav) != NULL; trav = &(*trav)->link) {
		printf("%c", (*trav)->elem);
	}
}

void insertLast(List *L, char elem) {
	List temp =(List)malloc(sizeof(struct node));
	List *trav;
	for(trav = L; (*trav) != NULL; trav = &(*trav)->link) {}
	if(temp != NULL) {
		temp->elem = elem;
		temp->link = *trav;
		*trav = temp;
	}
}
void deleteFirst(List *L){
	List temp;
	temp = (*L);
	*L = temp->link;
	free(temp);
}

void deleteLast(List *L){
	List temp;
	List *trav;
	for(trav = L; (*trav)->link != NULL; trav = &(*trav)->link){}
	temp = *trav;
	*trav = temp->link;
	free(temp);
}
