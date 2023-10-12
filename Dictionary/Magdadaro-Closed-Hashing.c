#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define EMPTY -1
#define DELETED -99

typedef struct node{
	
	unsigned int idNumber; 
	char FN[20];
	char LN[20];
	char MI;
	int yearLevel;
	
}studType;

typedef studType Dictionary[SIZE];
typedef enum {FALSE, TRUE} Boolean;

//function prototypes
void init(Dictionary D);
int hash(unsigned int x);
Boolean member(Dictionary D, unsigned int elem);
void insert(Dictionary D, studType S);
void deleteElem(Dictionary D, studType S);


int main(){
	Dictionary D;
	studType s1 = {11400071, "Matt Vincent", "Magdadaro", 'E', 2};
	init(D);
	insert(D, s1);
	member(D, 11400071);
}

void init(Dictionary D){
	int i;
	for(i = 0; i < SIZE; ++i){
		D[i].idNumber = EMPTY;
	}
}

int hash(unsigned int x){
	int sum = 0;
	while(x > 0){
		sum += x % 10;
		x /= 10;
	}
	return sum % SIZE;
}

Boolean member(Dictionary D, unsigned int elem){
	int hashvalue = hash(elem);
	int count = 0;
	for(; D[hashvalue].idNumber != elem && D[hashvalue].idNumber != EMPTY && count < SIZE ; hashvalue = (hashvalue + 1) % SIZE, count++) {}
	
	return D[hashvalue].idNumber == elem ? TRUE : FALSE;
}

void insert(Dictionary D, studType S){
	int hashvalue = hash(S.idNumber);
	int count = 0;
	for(; D[hashvalue].idNumber != EMPTY && D[hashvalue].idNumber != DELETED && count < SIZE; hashvalue = (hashvalue + 1) % SIZE, count++){}
	D[hashvalue] = S;
}

void deleteElem(Dictionary D, studType S){
	int hashvalue = hash(S.idNumber);
	int count = 0;
	for(; D[hashvalue].idNumber != EMPTY; hashvalue = (hashvalue + 1) % SIZE, count++){}
	D[hashvalue].idNumber = DELETED;
}
