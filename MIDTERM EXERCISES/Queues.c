#include <stdio.h>
#include <stdlib.h>
typedef struct node {

	char elem;
	struct node *next;

}*nodePtr;
typedef struct {

	nodePtr front;
	nodePtr rear;

} Queue;

void init(Queue *Q);
void enqueue(Queue *Q, char elem);
void dequeue(Queue *Q);
void display(Queue Q);

int main() {
	Queue Q;

	init(&Q);
	enqueue(&Q, 'D');
	enqueue(&Q, 'E');
	enqueue(&Q, 'F');
	enqueue(&Q, 'A');
	enqueue(&Q, 'B');
	enqueue(&Q, 'C');
	enqueue(&Q, 'G');

	dequeue(&Q);
	dequeue(&Q);
	dequeue(&Q);

	printf("Current front: %c\n", Q.front->elem);
	printf("Current rear: %c\n", Q.rear->elem);

	display(Q);

}

void init(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

void enqueue(Queue *Q, char elem) {
	nodePtr temp = (nodePtr)malloc(sizeof(struct node));
	temp->elem = elem;
	if(Q->front == NULL) {
		Q->front = temp;
		Q->rear = temp;
	} else {
		Q->rear->next = temp;
		Q->rear = temp;
	}
	Q->rear->next = NULL;
}
void dequeue(Queue *Q) {
	nodePtr temp;
	temp = Q->front;
	if(Q->front != NULL) {
		temp = Q->front;
		Q->front = temp->next;
		if(Q->front == NULL) {
			Q->rear = NULL;
		}
		free(temp);
	}
}

void display(Queue Q) {
	nodePtr trav;
	printf("Displaying the Queue: \n");
	for(trav = Q.front; trav != NULL; trav = trav->next) {
		printf("%c\n", trav->elem);
	}
}
