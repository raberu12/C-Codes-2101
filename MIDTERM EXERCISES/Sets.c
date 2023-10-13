#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef int SET;
void initSet(SET *A);
void addElem(SET *set, int num);
SET* Union(SET *set1, SET *set2);
SET* Intersection(SET *set1, SET *set2);
SET* Difference(SET *set1, SET *set2);
void displaySET(SET *set1);

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
	addElem(A, 6);

	addElem(B, 1);
	addElem(B, 2);
	addElem(B, 4);
	addElem(B, 7);
	addElem(B, 5);

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
void initSet(SET *set) {
	int i;
	for(i = 0; i < SIZE; i++) {
		set[i] = 0;
	}
}
void addElem(SET *set, int num) {
	if(set[num] == 0 && num < SIZE) {
		set[num] = 1;
	}
}
SET* Union(SET *set1, SET *set2) {
	SET *result = malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = set1[i] || set2[i];
	}
	return result;
}
SET* Intersection(SET *set1, SET *set2) {
	SET *result = malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = set1[i] && set2[i];
	}
	return result;
}
SET* Difference(SET *set1, SET *set2) {
	SET *result = malloc(sizeof(SET)*SIZE);
	int i;
	for(i = 0; i < SIZE; i++) {
		result[i] = set1[i] != set2[i];
	}
	return result;
}
void displaySET(SET *set) {
	int i = 0;
	int isPrinted = 0;
	printf("The Elements of this SET are: \n");
	printf("{");
	for(i = 0; i < SIZE; i++) {
		if(set[i] == 1) {
			if(isPrinted) {
				printf(", ");
			}
			printf("%d", i);
			isPrinted = 1;
		}
	}
	printf("}");
}


