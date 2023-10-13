//Cursor-based
#include <stdio.h>
#include <stdlib.h>
#define MAX 7
#define EMPTY -99

typedef struct {
	int elem;
	int next;
} Node;

typedef struct {
	Node nodes[MAX];
	int avail;
} Vheap;

typedef int LIST;

void display(Vheap V, LIST L);
void initVheap(Vheap *V, LIST *L);
int allocSpace(Vheap *V);
int deallocSpace(Vheap *V, int ndx);
void insert(Vheap *V , LIST *L, int elem;);
void insertLast(Vheap *V, LIST *L, int elem);
void deleteElem(Vheap *V, LIST *L, int elem);




int main() {
	Vheap V;
	LIST L;
	initVheap(&V, &L);
	insert(&V, &L, 2);
	insert(&V, &L, 3);
	display(V, L);
}

void display(Vheap V, LIST L) {
	LIST trav;
	for(trav = L; trav != -1; trav = V.nodes[trav].next) {
		printf("%d ", V.nodes[trav].elem);
	}
}

void initVheap(Vheap *V, LIST *L) {
	int i;
	for(i = MAX - 1; i > 0; i--) {
		V->nodes[i].next = i-1;
		V->nodes[i].elem = EMPTY;
	}
	V->nodes[i].next = -1;
	V->nodes[i].elem = EMPTY;
	V->avail = MAX - 1;
	*L = -1;
}
int allocSpace(Vheap *V) {
	int retval = -1;
	if(V->avail != -1) {
		retval = V->avail;
		V->avail = V->nodes[V->avail].next;
	}
	return retval;
}
int deallocSpace(Vheap *V, int ndx) {
	V->nodes[ndx].next = V->avail;
	V->avail = ndx;
}
void insert(Vheap *V, LIST *L, int elem) {
	LIST temp;
	temp = allocSpace(V);
	if (temp != -1) {
		V->nodes[temp].elem = elem;
		V->nodes[temp].next = *L;
		*L = temp;
	}
}
void insertLast(Vheap *V, LIST *L, int elem) {
	LIST temp, *trav;
	*trav = *L;
	for(trav = L ; (*trav) != -1 ; trav = &V->nodes[*trav].elem) {}
	if(V->avail != -1) {
		temp = allocSpace(V);
		V->nodes[temp].elem = elem;
		V->nodes[temp].next = *trav;
		*trav = temp;
	}
}
void deleteElem(Vheap *V, LIST *L, int elem){
	LIST *trav, temp;
	for(trav = L ; *trav != -1 && V->nodes[*trav].elem != elem; trav = &V->nodes[*trav].next){}
	if(V->avail != -1){
		temp = *trav;
		*trav = V->nodes[*trav].next;
		deallocSpace(V, temp);
	}
}

