#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {

	int arr[MAX];
	int last;

} heap;

void init(heap *A);
void swap(int *a, int *b);
void heapifyMax(heap* A, int index);
void insert(heap *A, int elem);
void deleteMax(heap *A);
void display(heap A);
void heapsort(heap *A);

int main() {
	
	heap A;
	init(&A);
	insert(&A, 8);
	insert(&A, 6);
	insert(&A, 7);
	insert(&A, 9);
	insert(&A, 10);
	insert(&A, 11);
	insert(&A, 31);
	
	deleteMax(&A);
	
	printf("Before heapsort: \n");
	display(A);
	printf("\nAfter heapsort: \n");
	heapsort(&A);
	display(A);

}

void init(heap *A) {
	int i;
	for(i = 0; i < MAX; i++) {
		A->arr[i] = 0;
	}
	A->last = -1;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapifyMax(heap* A, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = left + 1;
	if(left < A->last && A->arr[largest] < A->arr[left]) {
		largest = left;
	}
	if(right < A->last && A->arr[largest] < A->arr[right]) {
		largest = right;
	}
	if(largest != index) {
		swap(&(A->arr[index]), &(A->arr[largest]));
		heapifyMax(A, largest);
	}
}
void insert(heap *A, int elem) {
	if(A->last < MAX) {
		A->last++;
		A->arr[A->last] = elem;
	}
	int i = A->last;
	while(i > 0 && A->arr[i/2] < A->arr[i]) {
	swap(&(A->arr[i/2]), &(A->arr[i]));
		i = i/2;
	}
}
void deleteMax(heap *A) {
	if(A->last == -1) {
		printf("Heap is empty\n");
	}
	A->arr[0] = A->arr[A->last];
	A->last--;
	heapifyMax(A, 0);
}
void display(heap A){
	int i = 0;
	for(i = 0; i < A.last; i++){
		printf("%d - ", A.arr[i]);
	}
	printf("%d", A.arr[i]);
}
void heapsort(heap *A){
	int i;
	for(i = (A->last-1)/2; i >= 0; i--){
		heapifyMax(A, i);
	}
	int temp = A->last;
	while (A->last != 0) {
        swap(&A->arr[0], &A->arr[A->last]);
        A->last--;
        heapifyMax(A, 0);
    }
    A->last = temp;
}

