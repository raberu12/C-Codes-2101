#include <stdio.h>
#include <stdlib.h>

#define MAX 13

typedef struct heapType{
	int elem[MAX];
	int last;
}heap;

void init(heap *A);
void swap(int *a, int *b);
void insert(heap *A, int elem);
void heapify(heap *A, int index);
void deleteMax(heap *A);
void heapsort(heap *A);
void display(heap A);

int main(){
	
	heap myheap;
	init(&myheap);
	
	insert(&myheap, 7);
	insert(&myheap, 3);
	insert(&myheap, 2);
	insert(&myheap, 1);
	insert(&myheap, 9);
	insert(&myheap, 10);

	printf("After insertion:\n");
	display(myheap);

	deleteMax(&myheap);
	printf("\nAfter deletion:\n");
	display(myheap);

	heapsort(&myheap);
	printf("\nAfter heapsort:\n");
	display(myheap);
	
}

void init(heap *A){
	int i = 0;
	for(i = 0; i < MAX; i++){
		A->elem[i] = 0;
	}
	A->last = -1;
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void insert(heap *A, int elem){
	if(A->last < MAX){
		A->last++;
		A->elem[A->last] = elem;
	}
	int temp = A->last;
	while(temp > 0 && A->elem[temp/2] < A->elem[temp]){
		swap(&A->elem[temp/2], &A->elem[temp]);
		temp = temp/2;
	}
}
void heapify(heap *A, int index){
	int largest = index;
	int left = 2 * index + 1;
	int right = left + 1;
	
	if(left < A->last && A->elem[largest] < A->elem[left]){
		largest = left;
	}
	if(right < A->last && A->elem[largest] < A->elem[right]){
		largest = right;
	}
	if(largest != index){
		swap(&A->elem[largest], &A->elem[index]);
		heapify(A, largest);
	}
}
void deleteMax(heap *A){
	if(A->last == -1){
		printf("Heap is empty!");
	}
	A->elem[0] = A->elem[A->last];
	A->last--;
	heapify(A, 0);
}
void heapsort(heap *A){
	int i;
	for(i = (A->last-1)/2; i >= 0; i--){
		heapify(A, i);
	}
	int temp = A->last;
	while(A->last != 0){
		swap(&A->elem[0], &A->elem[A->last]);
		A->last--;
		heapify(A, 0);
	}
	A->last = temp;
}
void display(heap A) {
	int i = 0;
	for(i = 0; i < A.last; i++) {
		printf("%d - ", A.elem[i]);
	}
	printf("%d", A.elem[i]);
}
