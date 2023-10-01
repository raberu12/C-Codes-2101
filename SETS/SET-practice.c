#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

typedef int SET;

SET Union(SET *A, SET *B);
void initSet(SET *A);

int main() {

	SET A[SIZE];

	initSet(A);


	return 0;
}

void initSet(SET *A) {
	
	int i;
	for(i = 0; i < SIZE; i++) {
		if(i == 0 || i == 3 || i == 4 || i == 7 || i == 9) {
			A[i] = 1;
		}else{
			A[i] = 0;	
		}
	}

}
