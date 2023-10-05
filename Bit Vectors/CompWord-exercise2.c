#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;
typedef enum {FALSE, TRUE} Bool;

void initSet(SET *A);
void displaySet(SET A);
void Insert(SET *A, SET elem);
Bool Member(SET *A);
void Delete(SET *A);
SET Union(SET* A, SET *B);
SET Intersection(SET* A, SET *B);
SET Difference(SET* A, SET *B);

int main() {

	SET C;
	initSet(&C);
	Insert(&C, 2);
	displaySet(C);

}

void initSet(SET *A) {
	*A = 0;
}

void displaySet(SET A) {
	printf("Displaying the bit value of the SET:\n");
	SET mask;
	int elem;
	int display;
	for(mask = 1 << (sizeof(SET)*8 - 1); mask > 0; mask >>= 1) {
		printf("[%d]", (A & mask) ? 1 : 0);
	}
	printf("\nDisplaying the SET:\n");
	for(elem = (sizeof(SET)*8 - 1), mask = 1 << (sizeof(SET)*8 - 1); elem >= 0; mask >>= 1, elem--) {
		if(A & mask) {
			printf("[%d]", elem);
		}
	}
	printf("\n");
}

void Insert(SET *A, SET elem) {

	*A |= (1 << elem);

}
