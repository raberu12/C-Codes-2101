#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef char *ElemArray, ElemType;
typedef struct stackType {
	ElemArray E;
	int top;
}*Stack;
typedef enum {FALSE, TRUE} BOOL;

void initialize(Stack *S);
BOOL isFull(Stack S);
BOOL isEmpty(Stack S);
ElemType top(Stack S);
void push(Stack *S, char data);
void pop(Stack *S);
void displayStack(Stack S);

int main() {
	Stack S;
	initialize(&S);
	push(&S, 'A');
	push(&S, 'B');
	push(&S, 'C');
	push(&S, 'D');
	push(&S, 'E');
	pop(&S);
	push(&S, 'F');
	displayStack(S);
	
	
	printf("Current top: %c", top(S));

}

void initialize(Stack *S) {
	(*S) = (Stack)malloc(sizeof(struct stackType));
	(*S)->E = (ElemArray)malloc(sizeof(ElemType)*SIZE);
	(*S)->top = SIZE;
}

BOOL isFull(Stack S) {
	return S->top == 0 ? TRUE : FALSE;
}
BOOL isEmpty(Stack S) {
	return S->top == SIZE ? TRUE : FALSE;
}
ElemType top(Stack S) {
	return !(isEmpty(S)) ? S->E[S->top] : '!';
}
void push(Stack *S, char data) {
	if(!(isFull(*S))) {
		(*S)->top--;
		(*S)->E[(*S)->top] = data;
	} else {
		printf("Stack is full, cannot add '%c'\n", data);
	}
}
void pop(Stack *S) {
	if(!(isEmpty(*S))) {
		(*S)->top++;
	}
}
void displayStack(Stack S){
	int i;
	for(i = 0; i < SIZE; i++){
		printf("[%d] - %c\n", i, S->E[i]);
	}
}
