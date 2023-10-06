#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;
typedef enum {FALSE, TRUE} Bool;

void initSet(SET *A);
void displaySet(SET A);
void Insert(SET *A, SET elem);
Bool Member(SET A, SET elem);
void Delete(SET *A, SET elem);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);

int main() {
	SET C;
	SET B; 
	printf("Initializing SET C... \n\n");
	initSet(&C);
	printf("Inserting Values in C\n");
	Insert(&C, 8);
	Insert(&C, 7);
	Insert(&C, 0);
	Insert(&C, 5);
	Insert(&C, 1);
	Insert(&C, 2);
	displaySet(C);
	
	int isMember = 5;
	printf("\nChecking if %d is a member of the SET\n", isMember);
	if(Member(C, isMember)) {
		printf("The element %d is a member\n", isMember);
	} else {
		printf("Element %d is not a member\n", isMember);
	}
	
	printf("\n");
	
	printf("Trying to Delete: 7\n");
	Delete(&C, 7);
	printf("Set AFTER Deletion: \n");
	displaySet(C);
	
	printf("\n");
	
	printf("Trying to Delete: 8\n");
	Delete(&C, 8);
	
	printf("\n");
	
	printf("Initializiing SET B...\n");
	initSet(&B);
	printf("Adding Values to B...\n");
	Insert(&B, 0);
	Insert(&B, 1);
	Insert(&B, 2);
	Insert(&B, 3);
	Insert(&B, 4);
	
	printf("Displaying SET B: \n");
	displaySet(B);
	
	printf("\n");
	
	printf("SET OPERATIONS: \n");
	SET U = Union(C, B);
	SET D = Difference(C, B);
	SET I = Intersection(C, B);
	printf("Union of C and B:\n");
	displaySet(U);
	
	printf("\n");
	
	printf("Difference of C and B:\n");
	displaySet(D);
	
	printf("\n");
	
	
	printf("Intersection of C and B:\n");
	displaySet(I);
	
}

void initSet(SET *A) {
	*A = 0;
}

void displaySet(SET A) {

	SET mask;
	int i;
	printf("Displaying the bit pattern of the SET:\n");
	for(mask = 1 << (sizeof(SET)*8 - 1); mask > 0; mask >>= 1) {
		printf("[%d]", (A & mask) ? 1 : 0);
	}
	printf("\nDisplaying the elements in the SET:\n");
	for(i = 0; i < (sizeof(SET) *8); i++) {
		if(A & (1 << i)) {
			printf("[%d] ", i);
		}
	}
	printf("\n");
}

void Insert(SET *A, SET elem) {
	if(elem > 7) {
		printf("Out of Range\n\n");
	} else {
		printf("Position #%d has been added!\n\n", elem);
		*A |= (1 << elem);
	}
}
Bool Member(SET A, SET elem) {
	return(A & (1 << elem)) ? TRUE : FALSE;
}

void Delete(SET *A, SET elem){
	if(elem > 7){
		printf("That number is out of range or is non-existent!\n");
	}else{
		*A &= ~(1 << elem);
	}
}

SET Union(SET A, SET B){
	SET C = A |= B;
	return C;
}

SET Intersection(SET A, SET B){
	SET C = A & B;
	return C;
}

SET Difference(SET A, SET B){
	SET C = A & ~(B);
	return C;
}


