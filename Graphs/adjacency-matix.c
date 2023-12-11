#include <stdio.h>
#include <stdlib.h>



int main() {

	int set[5][5] = 
	{
	{0, 1, 1, 1, 0}, //vertex 0
	{0, 0, 1, 0, 0}, //vertex 1
	{0, 0, 0, 1, 1}, //vertex 2
	{0, 1, 0, 0, 0}, //vertex 3
	{0, 0, 0, 1, 0}  //vertex 4
	};
	
	int i, j;
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			if(set[i][j] == 1){
				printf("Vertex [%d] is adjacent to Vertex [%d]\n\n", i, j);
			}
		}
	}


}
