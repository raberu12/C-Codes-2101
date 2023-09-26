#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	
	char elem;
	struct node *next;
	
}*nodePtr;
typedef struct{
	
	nodePtr front;
	nodePtr rear;
	
}Queue;

void init(Queue *Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
void display(Queue Q);

int main(){
	
	Queue Q;
	init(&Q);
	enqueue(&Q, 'A');
	enqueue(&Q, 'B');
	dequeue(&Q);
	dequeue(&Q);
	display(Q);
	
}

void init(Queue *Q){
	
	Q->front = NULL;
	Q->rear = NULL;
}

void enqueue(Queue *Q, char elem){
	
	nodePtr temp = (nodePtr)malloc(sizeof(struct node));
	temp->elem = elem;
	if(Q->front == NULL){
		Q->front = temp;
		Q->rear = temp;
	}else{	
		Q->rear->next = temp;
		Q->rear = temp;
	}
	Q->rear->next = NULL;
}

void dequeue(Queue *Q){
	
	nodePtr temp;
	if(Q->front != NULL){
		temp = Q->front;
		Q->front = Q->front->next;
		if(Q->front == NULL){
			Q->rear = NULL;
		}
		free(temp);
	}
}

void display(Queue Q){
	nodePtr trav;
	for(trav = Q.front; trav != Q.rear->next; trav = trav->next){
		printf("%c ", trav->elem);
	}
}


