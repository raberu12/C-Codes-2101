#include <stdio.h>
#include <stdlib.h>

#define MAX 13

typedef struct node {
	int elem[MAX];
	int last;
} Heap;

void init(Heap *H);
void swap(int *a, int *b);
void insert(Heap *H, int elem);
void heapify(Heap *H, int index);
void deleteMax(Heap *H);
void heapsort(Heap *H);
void display(Heap H);

int main() {

	Heap myheap;
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

void init(Heap *H) {
	int i = 0;
	for(i = 0; i < MAX; i++) {
		H->elem[i] = 0;
	}
	H->last = -1;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(Heap *H, int elem) {
	if(H->last < MAX) {
		H->last++;
		H->elem[H->last] = elem;
	}
	int temp = H->last;
	while(temp > 0 && H->elem[temp/2] < H->elem[temp]) {
		swap(&H->elem[temp/2], &H->elem[temp]);
		temp = temp/2;
	}
}

void heapify(Heap *H, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = left + 1;

	if(left < H->last && H->elem[largest] < H->elem[left]) {
		largest = left;
	}
	if(right < H->last && H->elem[largest] < H->elem[right]) {
		largest = right;
	}
	if(largest != index) {
		swap(&H->elem[largest], &H->elem[index]);
		heapify(H, largest);
	}
}
void deleteMax(Heap *H) {
	if(H->last == -1) {
		printf("EMPTY HEAP");
	}
	H->elem[0] = H->elem[H->last];
	H->last--;
	heapify(H, 0);
}

void heapsort(Heap *H) {
	int i;
	for(i = (H->last-1)/2; i >= 0; i--)
		heapify(H, i);
	int temp = H->last;
	while(H->last != 0) {
		swap(&H->elem[0], &H->elem[H->last]);
		H->last--;
		heapify(H, 0);
	}
	H->last = temp;
}


void display(Heap H) {
	int i;
	for(i = 0; i < H.last; i++) {
		printf("%d - ", H.elem[i]);
	}
	printf("%d", H.elem[i]);
}
