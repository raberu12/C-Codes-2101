#include <stdio.h>
#include  <stdlib.h>
#define SIZE 5

//Open Hashing: Linked Lists (Unlimited Storage Space)
//Closed Hashing: Arrays (Size Constraint)

typedef struct {

	unsigned long int idNum;
	char FN[20];
	char LN[20];
	char MI;
	int yearLevel;

} Student;

typedef struct node {

	Student data;
	struct node *next;

} NodeType, *NodePtr;

typedef NodePtr Dictionary[SIZE];
typedef enum {FALSE, TRUE} Boolean;

void initDictionary(Dictionary *D);
int hash(unsigned int x);
void insert(Dictionary D, Student S);
Boolean isMember(Dictionary D, unsigned int x);
void Delete(Dictionary D, unsigned int x);
Student search(Dictionary D, unsigned int x);
void display(Dictionary D);

int main() {
	
	//initial declarations
	Student s1 = {11400071, "Matt", "Magdadaro", 'E', 2}; 
	Student s2 = {22101281, "Sky", "Sayson", 'C', 2};
	Dictionary D;
	initDictionary(&D);
	
	//insertin into the dictionary
	insert(D, s1);
	insert(D, s2);
	
	//check if member
	if(isMember(D, 11400071)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	if(isMember(D, 22101288)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	
	//displaying and searching
	Student match = search(D, 11400071);
	printf("--------------\nSEARCHED STUDENT:\nID: %d\nName: %s %s, %c\nYear Level: %d\n--------------\n", match.idNum, match.FN, match.LN, match.MI, match.yearLevel);
	Delete(D, 11400071);
	display(D);
}

void initDictionary(Dictionary *D) {
	int i;
	for(i = 0; i < SIZE; i++) {

		(*D)[i] = NULL;
	}
}

int hash(unsigned int x) {
	int sum = 0;
	while(x > 0) {
		sum += x% 10;
		x /=10;
	}
	return (int) sum % SIZE;
}

void insert(Dictionary D, Student S) {
	int hashValue = hash(S.idNum);
	NodePtr *trav, temp;
	for(trav = &D[hashValue]; (*trav) != NULL; trav = &(*trav)->next) {}
	temp = (NodePtr)malloc(sizeof(NodeType));
	temp->data = S;
	temp->next = NULL;
	*trav = temp;
}

Boolean isMember(Dictionary D, unsigned int x) {
	int hashval = hash(x);
	NodePtr trav;
	for(trav = D[hashval]; trav != NULL && trav->data.idNum != x; trav = trav->next) {}

	return trav == NULL ? FALSE : TRUE;

}
void Delete(Dictionary D, unsigned int x) {
	NodePtr temp;
	int hashval = hash(x);
	NodePtr *trav;
	for(trav = &D[hashval]; *trav != NULL && (*trav)->data.idNum != x; trav = &(*trav)->next) {}
	temp = *trav;
	*trav = (*trav)->next;
	free(temp);
}

Student search(Dictionary D, unsigned int x) {
	int hashval = hash(x);
	NodePtr trav;
	for(trav = D[hashval]; trav !=NULL && trav->data.idNum != x; trav = trav->next) {}
	return trav->data;
}
void display(Dictionary D) {
	NodePtr trav;
	int i;
	for(i = 0; i < SIZE; i++) {
		for(trav = D[i]; trav != NULL; trav = trav->next) {
			printf("Name: %s %c %s\nID: %d\nYear Level: %d\n", trav->data.FN, trav->data.MI, trav->data.LN, trav->data.idNum, trav->data.yearLevel);
		}
	}
}

