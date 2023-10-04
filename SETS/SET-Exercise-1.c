#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef int SET;

void initSet(SET *A);
void addElem(SET *A, int num);
SET* Union(SET *A, SET *B);
SET* Intersection(SET *A, SET *B);
SET* Difference(SET *A, SET *B);
void displaySET(SET *A);


int main() {

	SET A[SIZE];
	SET B[SIZE];
	SET *C;
	SET *D;
	SET *E;

	initSet(A);
	initSet(B);

	addElem(A, 0);
	addElem(A, 3);
	addElem(A, 4);
	addElem(A, 7);
	
	addElem(B, 1);
	addElem(B, 2);
	addElem(B, 4);
	addElem(B, 7);
	
	C = Union(A, B);
	D = Intersection(A, B);
	E = Difference(A, B);
	
	printf("SET A\n");
	displaySET(A);
	printf("\n\nSET B\n");
	displaySET(B);
	printf("\n\nSET C (SET UNION of A and B)\n");
	displaySET(C);
	printf("\n\nSET D (SET INTERSECTION of A and B)\n");
	displaySET(D);
	printf("\n\nSET E (SET DIFFERENCE of A and B)\n");
	displaySET(E);
	
	free(C);
	free(D);
	free(E);

	return 0;
}

void initSet(SET *A) {

	int i;
	for(i = 0; i < SIZE; i++) {
		A[i] = 0;
	}
}

void addElem(SET *A, int num) {

	int i;
	if(num < SIZE) {
		A[num] = 1;
	}
}

SET* Union(SET *A, SET *B) {
	SET *result = (SET *)malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = A[i] || B[i];
	}
	return result;
}

SET* Intersection(SET *A, SET *B) {
	SET *result = (SET *)malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = A[i] && B[i];
	}
	return result;
}

SET* Difference(SET *A, SET *B) {
	SET *result = (SET *)malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = A[i] != B[i];
	}
	return result;
}

void displaySET(SET *A) {
	int i = 0;
	int isPrinted = 0;
	printf("The Elements of this SET are: \n");
	printf("{");
	for(i = 0; i < SIZE; i++) {
		if(A[i] == 1) {
			if(isPrinted) {
				printf(", ");
			}
			printf("%d", i);
			isPrinted = 1;
		}
	}
	printf("}");
}
