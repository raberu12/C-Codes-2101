//my attempt at a heap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 13
typedef struct name {
	char FN[26], LN[26], MI;
} nameType;

typedef struct student {
	nameType name;
	char course[5];
	int yearLevel;
	unsigned long idNumber;

} studType;

typedef struct setType {

	int elem[MAX];
	int last;

} Set;

void init(Set *A);
void insert(Set *A, int x);
void display(Set A);
void insertMin(Set *A, int x);
void heapifyMin(Set *A);
int deleteMin(Set *A);
void heapsortMax(Set *P);

int main() {

	Set A;
	init(&A);
	insert(&A, 7);
	insert(&A, 6);
	insert(&A, 5);
	insert(&A, 4);
	insert(&A, 3);
	insert(&A, 2);
	printf("After Insertion: \n");
	display(A);
	printf("After HEAPIFICATION: \n");
	heapifyMin(&A);
	display(A);
	printf("After Delete: \n");
	deleteMin(&A);
	display(A);
	printf("After HeapsortMax: \n");
	heapsortMax(&A);
	display(A);



}

//initializes all elements in the array to 0
void init(Set *A) {
	int i;
	for(i = 0; i < MAX; i++) {
		A->elem[i] = 0;
	}
	A->last = -1; // signifies empty
}

//inserts normally
void insert(Set* A, int x) {
	if(A->last != MAX-1) {
		A->last++;
		A->elem[A->last] = x;
	}
}

//inersts then checks if heap property is followed
void insertMin(Set *A, int x) {
	int childPosition; //new elem
	int parentPosition; //parent of new elem
	if(A->last < MAX - 1) {
		A->last++;
		childPosition = A->last;
		A->elem[childPosition] = x;
		//loop to compare newly inserted elem with parent. if new elem is < parent then swap. continues until parent > than child
		for(parentPosition = (childPosition - 1)/2; parentPosition >= 0 && A->elem[childPosition] < A->elem[parentPosition]; childPosition = parentPosition, parentPosition = (childPosition - 1)/2) {
			A->elem[childPosition] = A->elem[parentPosition];
			A->elem[parentPosition] = x;
		}
	}
}

//rearranges heap to maintain min heap property. stars the last internal node (parent and child) and moves up the root,
//comparing each node with the children. If node is larger than each of its children swap continues until the root
void heapifyMin(Set *A) {
	int tree; //current index
	int parentPos; //stores position of parent in heap
	int leftChild;  // stores left
	int rightChild; // stores right
	int temp; //stores the smaller child (be it left or right)
	int top; //stores value of current index
	for(tree = (A->last - 1)/2; tree >= 0; tree--) {
		parentPos = tree;
		top = A->elem[parentPos];

		leftChild = (parentPos*2)+1;
		rightChild = (parentPos*2)+2;
		while(leftChild < A->last && (top > A->elem[leftChild] || top > A->elem[rightChild])) {
			temp = (A->elem[leftChild] < A->elem[rightChild]) ? leftChild : rightChild;

			A->elem[parentPos] = A->elem[temp];
			A->elem[temp] = top;
			parentPos = temp;
			leftChild = (parentPos*2)+1;
			rightChild = leftChild + 1;
		}
	}
}
//deletes the minimum element from the heap.
int deleteMin(Set *A) {
	int parentPos, leftChild, rightChild, temp, top, retval; //same with heapify
	retval = A->elem[0];
	if(A->last > 0) {
		//replaces current root with the last element which also lets top variable hold the value
		top = A->elem[0] = A->elem[A->last];
		A->last--;
		parentPos = 0;
		leftChild = 1;
		rightChild = 2;
		//check whether child is not a leaf and then determines if its larger than
		//its children, if it is larger swap with children
		while(leftChild <= A->last && (top > A->elem[leftChild] || top > A->elem[rightChild])) {
			temp = (A->elem[leftChild] < A->elem[rightChild]) ? leftChild : rightChild;
			A->elem[parentPos] = A->elem[temp];
			A->elem[temp] = top;
			parentPos = temp;
			leftChild = (parentPos*2)+1;
			rightChild = leftChild + 1;
		}
	} else if(A->last == 0) {
		A->last--;
	}
	return retval;
}

//sort elements in the heap in descending order
void heapsortMax(Set *P) {
	int oldLast, x;
	
	//stores original last elem
	oldLast = P->last;
	
	//deletes min elem from the heap and insert it at pos oldLast-x, which sorts the heap
	//in descending order
	for(x = 0; x < oldLast; x++) {
		P->elem[oldLast-x] = deleteMin(P);
	}
	//resets the last elem in the heap and sorts the elems in the heap descending order
	P->last = oldLast;
}

void display(Set A) {
	int i;
	for(i=0; i<A.last; i++) {
		printf("%d ", A.elem[i]);
	}
	printf("%d\n", A.elem[i]);
}

