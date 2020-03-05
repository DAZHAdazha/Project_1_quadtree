#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "destroy.h"

// a function that could recursively free all the tree nodes
void destroyTree(Node *root){
	for(int i=0;i<4;i++){
		if (root->child[i])
			destroyTree(root->child[i]);
	}
	free(root);
	root = NULL; 
	return;
}
// assuming all children are lead nodes
void removeChildren(Node *parent){
	for(int i=0;i<4;i++){
		if(parent->child[i]!=NULL){
			free(parent->child[i]);
			parent->child[i] = NULL;
		}
	}
	return;
}
