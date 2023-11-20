#include <stdio.h>
#include <stdlib.h>
#define MAX 15

typedef struct setType {

	int elem[MAX];
	int last;

} heap;

void init(heap *A);
void insert(heap *A, int elem);
void swapHeap(heap *A, int i, int j);
void insertHeap(heap *A, int elem);
void swap(int *a, int *b);
void heapifyMax(heap *A, int index);
int deleteMax(heap *A);
void heapsortMin(heap *A);
void display(heap A);

int main() {
	heap A;
	init(&A);
	insertHeap(&A, 5);
	insertHeap(&A, 3);
	insertHeap(&A, 8);
	insertHeap(&A, 2);
	insertHeap(&A, 7);
	insertHeap(&A, 9);

	deleteMax(&A);

	printf("Heap:\n");
	display(A);


}

void init(heap *A) {
	int i;
	for(i = 0; i < MAX; i++) {
		A->elem[i] = 0;
	}
	A->last = -1;
}

void insert(heap *A, int elem) {
	if(A->last != MAX-1) {
		A->last++;
		A->elem[A->last] = elem;
	}
}

void swapHeap(heap *A, int i, int j) {
	int temp = A->elem[i];
	A->elem[i] = A->elem[j];
	A->elem[j] = temp;
}

void insertHeap(heap *A, int elem) {
	int childPos;
	int parentPos;
	if(A->last < MAX - 1) {
		A->last++;
		childPos = A->last;
		parentPos = (childPos-1)/2;
		A->elem[childPos] = elem;
		while(A->elem[parentPos] < A->elem[childPos] && childPos > 0) {
			swapHeap(A, parentPos, childPos);
			childPos = parentPos;
			parentPos = (childPos-1)/2;
		}
	}
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = *a;
}

void heapifyMax(heap *A, int index) {
	int largest = index;
	int lc = 2 * index + 1;
	int rc = lc + 1;

	if(lc < A->last && A->elem[largest] < A->elem[lc]) {
		largest = lc;
	}
	if(rc < A->last && A->elem[largest] < A->elem[rc]) {
		largest = rc;
	}
	if(largest < index) {
		swap(&(A->elem[index]), &(A->elem[largest]));
		heapifyMax(A, largest);
	}
}

int deleteMax(heap *A) {
	int retval = A->elem[0];
	A->elem[0] = A->elem[A->last];
	A->last--;
	heapifyMax(A, 0);
	return retval;
}

void heapsortMin(heap *A) {
	int n = A->last + 1;
	for (int i = n/2 - 1; i >= 0; i--)
		heapifyMax(A, i);
	for (int i=n-1; i>=0; i--) {
		swapHeap(A, 0, i);
		heapifyMax(A, i);
	}
}


void display(heap A) {
	int i;
	for(i = 0; i < A.last; i++) {
		printf("%d - ", A.elem[i]);
	}
	printf("%d", A.elem[i]);
}
