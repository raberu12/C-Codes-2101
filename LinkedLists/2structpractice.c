#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

	int id;
	char name[50];
	int age;

} STUDENT;

typedef struct node {

	STUDENT student;
	struct node *next;

}*LIST, lType;

void initList(LIST *L);
void insertFirst(LIST *L, STUDENT stud);
void insertLast(LIST *L, STUDENT stud);
void deleteFirst(LIST *L);
void deleteLast(LIST *L);
LIST retrieve(LIST L, int position);
void displayList(LIST *L);

int main() {
	LIST head;
	initList(&head);

	STUDENT B;
	B.age = 17;
	B.id = 1;
	strcpy(B.name, "Jeremy");
	
	STUDENT A;
	A.age = 18;
	A.id = 2;
	strcpy(A.name, "Michael");
	
	STUDENT C;
	C.age = 17;
	C.id = 3;
	strcpy(C.name, "Rich");
	
	insertFirst(&head, B);
	insertFirst(&head, A);
	insertLast(&head, C);
	displayList(&head);
}

void initList(LIST *L) {

	*L = NULL;
}

void insertFirst(LIST *L, STUDENT stud) {

	LIST temp;
	temp = (LIST)malloc(sizeof(lType));
	if(temp != NULL) {
		temp->student = stud;
		temp->next = *L;
		*L = temp;
	} else {
		printf("Memory Allocation Failed");
	}
}

void insertLast(LIST *L, STUDENT stud) {

	LIST temp;
	LIST *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->next) {}
	temp = (LIST)malloc(sizeof(lType));
	if(temp != NULL) {
		temp->student = stud;
		temp->next = *trav;
		*trav = temp;
	} else {
		printf("Memory Allocation Failed");
	}

}

void deleteFirst(LIST *L) {

	LIST temp;
	if(*L != NULL) {
		temp = *L;
		*L = temp->next;
		free(temp);
	}
}

void deleteLast(LIST *L) {

	LIST temp;
	LIST *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->next) {}
	if(temp != NULL) {
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

LIST retrieve(LIST L, int position){
	
	
	
}

void displayList(LIST *L) {
	LIST *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->next) {
		printf("ID: %d\nStudent: %s\nAge: %d\n\n", (*trav)->student.id, (*trav)->student.name, (*trav)->student.age);
	}
}
