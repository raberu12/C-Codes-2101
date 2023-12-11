#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex;
	struct node *next;
} node;

typedef struct graph {
	int count;
	node **list;
} graph;

node *createNode(int v);
graph *createGraph(int vertices);
void addEdge(graph *G, int src, int dest);
void printGraph(graph *G);

int main() {
	graph *G = createGraph(5);

	addEdge(G, 0, 1);
	addEdge(G, 0, 2);
	addEdge(G, 0, 3);
	addEdge(G, 1, 2);
	addEdge(G, 2, 3);
	addEdge(G, 2, 4);
	addEdge(G, 3, 1);
	addEdge(G, 4, 3);

	printGraph(G);

}

node *createNode(int v) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}
graph *createGraph(int vertices) {
	graph *G = (graph*)malloc(sizeof(graph));
	G->count = vertices;
	G->list = (node**)malloc(vertices *(sizeof(node*)));
	for(int i = 0; i < vertices; i++) {
		G->list[i] = NULL;
	}
	return G;
}
void addEdge(graph *G, int src, int dest) {
	node *newNode = createNode(dest);
	newNode->next = G->list[src];
	G->list[src] = newNode;
}
void printGraph(graph *G) {
	int v;
	for(v = 0; v < G->count; v++) {
		node *temp = G->list[v];
		printf("\nAdjacency list of vertex %d - >\n", v);
		while(temp) {
			if(temp->next == NULL) {
				printf("%d", temp->vertex);
			} else {
				printf("%d -> ", temp->vertex);
			}
			temp = temp->next;
		}
		printf("\n");
	}
}

