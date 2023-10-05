#include <stdio.h>
#include  <stdlib.h>
#define SIZE 5

//Open Hashing: Linked Lists (Unlimited Storage Space)
//Closed Hashing: Arrays (Size Constraint)

typedef struct{
	
	unsigned long int idNum;
	char FN[20];
	char LN[20];
	char MI;
	int yearLevel;
	
}Student;

typedef struct node{
	
	Student data;
	struct node *next;
	
}NodeType, *NodePtr;

typedef NodePtr Dictionary[SIZE];

void initDictionary(Dictionary *D);
int hash(unsigned int x);
void insert(Dictionary D, Student S);

int main(){	

	Student s1 = {11400071, "Matt", "Magdadaro", 'E', 2};
	Student s2 = {22101281, "Sky", "Sayson", 'C', 2};	
	Dictionary D;
	initDictionary(&D);
	insert(D, s1);
	insert(D, s2);
	
	
}

void initDictionary(Dictionary *D){
	int i;
	for(i = 0; i < SIZE; i++){
		
		(*D)[i] = NULL;	
	}	
}

int hash(unsigned int x){
	int sum = 0;
	while(x > 0){
		sum += x% 10;
		x /=10;
	}
	return (int) sum % SIZE;
}

void insert(Dictionary D, Student S){
	int hashValue = hash(S.idNum);
	NodePtr *trav, temp;
	for(trav = &D[hashValue]; (*trav) != NULL; trav = &(*trav)->next){}
	temp = (NodePtr)malloc(sizeof(NodeType));
	temp->data = S;
	temp->next = NULL;
	*trav = temp;
}

