#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	
	int data;
	struct node *link;
	
};




int main(){
	
	struct node *head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	
	head->data = 45;
	head->link = NULL;
	
	struct node *current = malloc(sizeof(struct node));
	current->data = 98;
	current->link = NULL;
	head->link = current;
	
	current = malloc(sizeof(struct node));
	current->data = 3;
	current->link = NULL;
	
	head->link->link = current;
	 
	
	printf("%d", head->data);
	return 0;
	
}
