#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;	
};

struct node* newNode(int data); //allocates a new node with the given data and NULL left and rught pointers.
int maxDepth(struct node* node); //finds the max depth of a tree to its farthest leaf

int main(){
	
	struct node* root = newNode(1); //becomes the root of the tree
	root->left = newNode(2);
	root->right = newNode(3);
	//becomes left and right children of 1
	root->left->left = newNode(4);
	//becomes left child of 2
	
	printf("Height of tree is %d", maxDepth(root));
	
	return 0;
	
}

struct node* newNode(int data){
	
	struct node* node = (struct node*)malloc(sizeof(struct node)); //allocate memory for new node
	node->data = data; //assigns data to node
	node->left = NULL;
	node->right = NULL;
	//initialize left and right children as NULL
	return node;
	
}
//recursive function
int maxDepth(struct node* node){ //compute the max depth of a tree the number of nodes along the longest path from the root node down to the farthest leaf node.
	if(node == NULL){
		return 0;
	}else{
		//computes depth of each subtree
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
		
		//uses the larger num
		if(lDepth > rDepth){
			return (lDepth + 1);
		}else{
			return (rDepth + 1);
		}
		
	}
}
