#include<stdio.h>
#include<stdlib.h>

typedef unsigned char SET;


int main(){
	
	char c = 'A';
	unsigned char x;
	
	for(x = 1 << (sizeof(x) * 8 - 1); x > 0; x >>= 1 ){
		printf("%d",(x&c)? 1:0);
	}

}

