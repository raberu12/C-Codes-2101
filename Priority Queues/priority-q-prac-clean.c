//my attempt at a priority queue
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int priority;
} Node;

typedef struct queue {
	Node *arr;
	int size;
	int capacity;

} Queue;

Queue *initQueue(int capacity);
void swap(Node *a, Node *b);
void heapify(Queue *pq, int index);
void enqueue(Queue *pq, int data, int priority);
Node dequeue(Queue *pq);
void printQueue(Queue *pq);

int main() {
	
	Queue *pq = initQueue(10);
	
	enqueue(pq, 10, 3);
	enqueue(pq, 20, 2);
	enqueue(pq, 15, 1);
	
	printf("Priority Queue: ");
	printQueue(pq);
	
	Node max = dequeue(pq);
	printf("Max node is: %d, with a priority of %d\n", max.data, max.priority);
	
	printf("Priority Queue after extracting max: ");
	printQueue(pq);
	return 0;
}

Queue *initQueue(int capacity) {
	Queue *temp = (Queue*)malloc(sizeof(Queue));
	temp->arr = (Node*)malloc(sizeof(Node));
	temp->capacity = capacity;
	temp->size = 0;

	return temp;
}

void swap(Node *a, Node *b) {
	Node temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Queue *pq, int index) {
	int largest = index;
	int leftChild = 1 + index * 2;
	int rightChild = 2 + index *2;
	
	if(leftChild < pq->size && pq->arr[largest].priority < pq->arr[leftChild].priority){
		largest = leftChild;
	}
	if(rightChild < pq->size && pq->arr[largest].priority < pq->arr[rightChild].priority){
		largest = rightChild;
	}
	
	if(largest < index){
		swap(&(pq->arr[index]), &(pq->arr[largest]));
		heapify(pq, largest);
	}
	
}

void enqueue(Queue *pq, int data, int priority) {

	if(pq->size == pq->capacity) {
		printf("Queue is full!");
	} else {
		
		pq->size++;
		int index = pq->size - 1;
		int parent = (index - 1)/2;
		pq->arr[index].data = data;
		pq->arr[index].priority = priority;
		while(index != 0 && pq->arr[parent].priority < pq->arr[index].priority){
			swap(&(pq->arr[parent]), &(pq->arr[index]));
			index = parent;
		}
	}

}

Node dequeue(Queue *pq){
	if(pq->size <= 0){
		printf("Queue is empty");
		Node nothing = {0, 0};
		return nothing;
	}
	
	if(pq->size == 1){
		pq->size--;
		return pq->arr[0];
	}
	
	Node root = pq->arr[0];
	pq->arr[0] = pq->arr[pq->size - 1];
	pq->size--;
	heapify(pq, 0);
	return root;
}

void printQueue(Queue *pq){
	printf("\nDATA: PRIO: \n");
	for(int i = 0; i < pq->size; i++){
		printf("%d %d\n", pq->arr[i].data, pq->arr[i].priority);
	}
}


