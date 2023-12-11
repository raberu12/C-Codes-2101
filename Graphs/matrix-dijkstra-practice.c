#include <stdio.h>

#define INFINITY 999
#define MAX 5

int minDistance(int dist[], int sptSet[]);
void print(int dist[]);
void dijkstra(int graph[MAX][MAX], int src);

int main() {

	int graph[MAX][MAX] = {
		{0, 1, 4, 0, 0},
		{1, 0, 4, 2, 7},
		{4, 4, 0, 3, 5},
		{0, 2, 3, 0, 4},
		{0, 0, 0, 6, 7}
	};
	dijkstra(graph, 0);

	return 0;

}

int minDistance(int dist[], int sptSet[]) { // spt = shortest path tree
	int min = 999, min_index;
	int v;
	for(v = 0; v < MAX; v++) {
		if(sptSet[v] == 0 && dist[v] <= min) { //if shortest path in index v is equal to 0 and distance in index v is less than min;
			min = dist[v]; //replaces min with current value of index v in distance array
			min_index = v; //min_index now holds value v
		}
	}
	return min_index;
}
void print(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < MAX; i++) {
        if (dist[i] == INFINITY) {
            printf("%d \t Not Reachable\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

void dijkstra(int graph[MAX][MAX], int src) {
	int dist[MAX]; //value of dist[i] holds shortest distance from src to i
	int sptSet[MAX]; //sptSet[i] is true if the vertex i is included in path

	int i;
	for(i = 0; i < MAX; i++) {
		dist[i] = INFINITY;
		sptSet[i] = 0;
	}
	//distance to self is always 0
	dist[src] = 0;

	//find shortest path
	int count;
	for(count = 0; count < MAX - 1; count++) {
		int x = minDistance (dist, sptSet); //pick the min distance vertex from the set of vertices not yet visited

		//chosen vertex set as true
		sptSet[x] = 1;

		//update distance value of neighboring vertex of src
		int v;
		//update dist[v] only happens if it is not in sptSet, an edge is present from x to v, and the total weight of path from src to v through x is less than the current value of dist[v]
		for(v = 0; v < MAX; v++) {
			if(!sptSet[v] && graph[x][v] && dist[x] != INFINITY && dist[x] + graph[x][v] < dist[v]) {
				dist[v] = dist[x] + graph[x][v];
			}
		}
		printf("Iteration %d:\n", count + 1);
		printf("Selected vertex: %d\n", x);
		printf("Shortest distances: ");
		for (int i = 0; i < MAX; i++) {
			printf("%d ", dist[i]);
		}
		printf("\n\n");
	}
	print(dist);
}

