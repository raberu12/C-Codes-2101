#include <stdio.h>
#include <stdlib.h>

//structure to represent a node in the priority queue
typedef struct node{
	int data;
	int prio;
}Node;

//structure to represent the priority queue
typedef struct queue{
	Node *arr;
	int capacity;
	int size;
}Queue;

Queue *initQueue(int capacity); //function to initialize a prio queue
void swap(Node *a, Node *b); //function to swap 2 nodes
void heapify(Queue *pq, int index); //function to heapify the prio queue
void enqueue(Queue* pq, int data, int priority); // Function to enqueue a new element into the prio queue
Node dequeue(Queue* pq);//function to extract the max node with the highest priority
void printQueue(Queue * pq);//prints the prio queue

int main(){
	
	Queue *pq = initQueue(10);
	
	enqueue(pq, 10, 2);
	enqueue(pq, 20, 1);
	enqueue(pq, 15, 3);
	
	printf("Priority Queue: ");
	printQueue(pq);
	
	Node max = dequeue(pq);
	printf("Max node is: %d, with a priority of %d\n", max.data, max.prio);
	
	printf("Priority Queue after extracting max: ");
	printQueue(pq);
	
}

Queue *initQueue(int capacity){
	Queue *pq = (Queue*)malloc(sizeof(Queue));
	pq->arr = (Node*)malloc(sizeof(Node) * capacity);
	pq->capacity = capacity;
	pq->size = 0;
	return pq;
}

void swap(Node *a, Node *b){
	Node temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(Queue *pq, int index){
	//assigning of values
	int largest = index; //assumes largest is current index
	int leftChild = 2 * index + 1; //find left child
	int rightChild = 2 * index + 2; //find right child
	
	//checks for left child's existence and if its priority is greater than priority of the current largest node, if true update largest to be index of left child.
	if(leftChild < pq->size && pq->arr[leftChild].prio > pq->arr[largest].prio){ 
		largest = leftChild;
	}
	//checks for right child's existence and if its priority is greater than priority of the current largest node, if true update largest to be index of right child.
	if(rightChild < pq->size && pq->arr[rightChild].prio > pq->arr[largest].prio){
		largest = rightChild;
	}
	//if current largest node is not the current node, swap current node with largest, call heapify to ensure heap property is maintained
	if(largest != index){
		swap(&(pq->arr[index]), &(pq->arr[largest]));
		heapify(pq, largest);
	}
	
}
void enqueue(Queue* pq, int data, int priority){
	//Checks if the queue is full
	if(pq->size == pq->capacity){
		printf("The Queue is full\n");
	}else{
		//actual insertion happens here
		pq->size++; //increment size to reflect newly enqueueed node
		int index = pq->size - 1;
		int parent = (index - 1)/2;
		pq->arr[index].data = data;
		pq->arr[index].prio = priority;
		
		//Ensures the max heap property
		while(index != 0 && pq->arr[parent].prio < pq->arr[index].prio){
			swap(&(pq->arr[index]), &(pq->arr[parent]));
			index = parent;
		}
	}
}

Node dequeue(Queue* pq){
	//Check if queue is empty, if empty return nothing
	if(pq->size <= 0){
		printf("Queue empty");
		Node nothing = {0, 0};
		return nothing;
	}
	//Special case: Check if there is only 1 element in the queue, then simply decrease size to signify the dequeue then returns the only element
	if(pq->size == 1){
		pq->size--;
		return pq->arr[0];
	}
	//Normal extraction from Max Heap
	Node root = pq->arr[0]; //Store the maximum priority element in variable root
	pq->arr[0] = pq->arr[pq->size - 1]; //replace with last number of array
	pq->size--; //Decrement size to signify the dequeue
	heapify(pq, 0); //Call heapify to ensure heap property is retained
	return root; 
}
void printQueue(Queue *pq){
	printf("\nDATA: PRIO: \n");
	for(int i = 0; i < pq->size; i++){
		printf("%d %d\n", pq->arr[i].data, pq->arr[i].prio);
	}
}

