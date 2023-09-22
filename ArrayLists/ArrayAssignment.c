#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct {

	char elem[MAX];
	int count;

} LIST;

typedef struct list2 {

	char elem[MAX];
	int count;

} *LIST2;

typedef struct {

	char *elemPtr;
	int count;

} LIST3;

typedef struct list4 {

	char *elemPtr;
	int count;

} *LIST4;

void initList(LIST *L);
void initList2(LIST2 *L);
void initList3(LIST3 *L);
void initList4(LIST4 *L);
void insertFirst(LIST *L, char elem);
void insertFirst2(LIST2 L, char elem);
void insertFirst3(LIST3 *L, char elem);
void insertFirst4(LIST4 L, char elem);
void deleteFirst(LIST *L);
void deleteFirst2(LIST2 L);
void deleteFirst3(LIST3 *L);
void deleteFirst4(LIST4 L);
void displayList1(LIST L);
void displayList2(LIST2 L);
void displayList3(LIST3 L);
void displayList4(LIST4 L);

int main() {

	LIST A;
	LIST2 B;
	LIST3 C;
	LIST4 D;

	initList(&A);
	initList2(&B);
	initList3(&C);
	initList4(&D);

	insertFirst(&A, 'a');
	insertFirst2(B, 'b');
	insertFirst3(&C, 'c');
	insertFirst4(D, 'd');

	displayList1(A);
	displayList2(B);
	displayList3(C);
	displayList4(D);

	printf("\n\nAfter Deletion:\n\n");

	deleteFirst(&A);
	deleteFirst2(B);
	deleteFirst3(&C);
	deleteFirst4(D);

	displayList1(A);
	displayList2(B);
	displayList3(C);
	displayList4(D);

	return 0;
}

void initList(LIST *L) {

	L->count = 0;
}

void initList2(LIST2 *L) {

	*L = malloc(sizeof(struct list2));
	(*L)->count = 0;
}

void initList3(LIST3 *L) {

	L->elemPtr = malloc(sizeof(char) * MAX);
	L->count = 0;
}

void initList4(LIST4 *L) {

	*L = malloc(sizeof(struct list4));
	(*L)->elemPtr = malloc(sizeof(char) * MAX);
	(*L)->count = 0;
}

void insertFirst(LIST *L, char elem) {

	int i;
	if (L->count < MAX) {
		for (i = L->count - 1; i >= 0; i--) {
			L->elem[i + 1] = L->elem[i];
		}
		L->elem[0] = elem;
		L->count++;
	} else {

		printf("MEMORY IS FULL");

	}
}

void insertFirst2(LIST2 L, char elem) {

	int i;
	if (L->count < MAX) {
		for (i = L->count - 1; i >= 0; i--) {
			L->elem[i + 1] = L->elem[i];
		}
		L->elem[0] = elem;
		L->count++;
	} else {

		printf("MEMORY IS FULL");
	}
}

void insertFirst3(LIST3 *L, char elem) {

	int i;
	if (L->count < MAX) {
		for (i = L->count - 1; i >= 0; i--) {
			L->elemPtr[i + 1] = L->elemPtr[i];
		}
		L->elemPtr[0] = elem;
		L->count++;
	} else {

		printf("MEMORY IS FULL");

	}
}

void insertFirst4(LIST4 L, char elem) {

	int i;
	if (L->count < MAX) {
		for (i = L->count - 1; i >= 0; i--) {
			L->elemPtr[i + 1] = L->elemPtr[i];
		}
		L->elemPtr[0] = elem;
		L->count++;
	} else {

		printf("MEMORY IS FULL");

	}
}

void deleteFirst(LIST *L) {

	int i;
	if(L->count != 0) {
		for(i = 0; i < L->count; i++) {

			L->elem[i] = L->elem[i+1];

		}

		L->count--;

	}

}

void deleteFirst2(LIST2 L) {
	int i;
	if(L->count != 0) {
		for(i = 0; i < L->count; i++) {

			L->elem[i] = L->elem[i+1];

		}

		L->count--;

	}
}
void deleteFirst3(LIST3 *L) {
	int i;
	if(L->count != 0) {
		for(i=0; i < L->count; i++) {

			L->elemPtr[i] = L->elemPtr[i+1];
		}
	}

	L->count--;
}
void deleteFirst4(LIST4 L) {
	int i;
	if(L->count != 0) {
		for(i=0; i < L->count; i++) {

			L->elemPtr[i] = L->elemPtr[i+1];
		}
	}
	L->count--;
}


void displayList1(LIST L) {

	int i;
	printf("VERSION 1:\n");
	if(L.count != 0) {
		for (i = 0; i < L.count; i++) {
			printf("%c\n", L.elem[i]);
		}
		printf("Current count: %d\n", L.count);
	} else {

		printf("Nothing is in this LIST!\n");

	}

}

void displayList2(LIST2 L) {

	int i;
	printf("VERSION 2:\n");
	if(L->count != 0) {
		for (i = 0; i < L->count; i++) {
			printf("%c\n", L->elem[i]);
		}
		printf("Current count: %d\n", L->count);
	} else {

		printf("Nothing is in this LIST!\n");

	}
}

void displayList3(LIST3 L) {

	int i;
	printf("VERSION 3:\n");
	if(L.count != 0) {
		for (i = 0; i < L.count; i++) {
			printf("%c\n", L.elemPtr[i]);
		}
		printf("Current count: %d\n", L.count);
	} else {

		printf("Nothing is in this LIST!\n");

	}
}

void displayList4(LIST4 L) {

	int i;
	printf("VERSION 4:\n");
	if(L->count != 0) {
		for (i = 0; i < L->count; i++) {
			printf("%c\n", L->elemPtr[i]);
		}
		printf("Current count: %d\n", L->count);
	} else {

		printf("Nothing is in this LIST!\n");

	}
}

