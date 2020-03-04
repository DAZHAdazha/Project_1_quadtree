#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "destroy.h"

// a function that could recursively free all the tree nodes
void destroy_Tree(Node *root){
	for(int i=0;i<4;i++){
		if (root->child[i])
			destroy_Tree(root->child[i]);
	}
	free(root);
	root = NULL; 
	return;
}
void destroy_Node(Node *root){
	
	return;
}
