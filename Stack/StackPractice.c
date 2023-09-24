#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef char *ElemArray, ElemType;
typedef struct stackType{
	
	ElemArray E;
	int top;
	
}*Stack;

typedef enum{FALSE, TRUE} Bool;

void initializeStack(Stack *S);
Bool isFull(Stack S);
Bool isEmpty(Stack S);
ElemType top(Stack S);
void push(Stack *S, char data);
void pop(Stack *S);

int main(){
	
	Stack S;
	initializeStack(&S);
	printf("Is the Stack empty?\n");
	if(isEmpty(S)){
		printf("The Stack is currently empty\n");
	}else{
		printf("The Stack is not empty\n");
	}
	printf("Is the Stack full?\n");
	if(isFull(S)){
		printf("The Stack is currently full!\n");
	}else{
		printf("The Stack is not full!\n");
	}
	push(&S, 'b');
	push(&S, 'a');
	push(&S, 'c');
	if(isEmpty(S) == TRUE){
		printf("The Stack is currently empty\n");
	}else{
		printf("The Stick is not empty\n");
	}
	printf("The current top element is: %c\n", top(S));
	pop(&S);
	printf("The current top element is: %c\n", top(S));
}

void initializeStack(Stack *S){
	(*S) = (Stack)malloc(sizeof(Stack));
	(*S)->E = (ElemType*)malloc(sizeof(ElemType)*SIZE);
	(*S)->top = SIZE;
}

Bool isFull(Stack S){
	return (S->top == 0) ? TRUE : FALSE;
}

Bool isEmpty(Stack S){
	return (S->top == SIZE) ? TRUE : FALSE;
}

ElemType top(Stack S){
	return (isEmpty(S) == FALSE) ? S->E[S->top] : '!';
}

void push(Stack *S, char data){
	if(isFull(*S) == FALSE){
		(*S)->top--;
		(*S)->E[(*S)->top] = data;
	}
}

void pop(Stack *S){
	if(isEmpty(*S) == FALSE){
		(*S)->top++;
	}
}
