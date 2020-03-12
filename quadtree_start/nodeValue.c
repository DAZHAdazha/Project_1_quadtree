#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "nodeValue.h" 

int add_count = 0;
int remove_count = 0;
extern int maxLevel;

// Evaluate function at centre of quadtree node
double nodeValue( Node *node, double time ) {

	int level = node->level;
	double x = node->xy[0];
	double y = node->xy[1];
	double h = pow(2.0,-level);
	return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function
double value( double x, double y, double time ) {
	return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

// stage_1 Function that used to set all the flags to the whole tree
void setTree(Node *root){
	if(root->child[0]==NULL){	// if it is leaf node
	double current_value = nodeValue(root, 0.0); // get the node value
		if(current_value>0.5){
			root->flag = 1;
		}
		else if(current_value<-0.5){
			root->flag = -1;
		}
	}
	else{	// if it is not a leaf node, then recursively traverse to leaf nodes
		for(int i=0;i<4;i++){
			setTree(root->child[i]);
		}
	}
	return;
}

// stage_2 Function that used to adjust the tree
void adjustTree(Node *root){
	if(root->child[0]==NULL){	// if it is leaf node
		if((root->flag==1) && (root->level<maxLevel)){
			makeChildren(root);
			add_count += 4;	// increment the count of adding nodes
		}
	}
	else{	// if it is not leaf node
		int sum = 0; // to find out whether the four children of root node is all -1 
		for(int i=0;i<4;i++){
			sum += root->child[i]->flag;
		}
		if(sum==-4){
			removeChildren(root);
			remove_count += 4; //increment the cout of removing nodes
		}
	}
	setTree(root);	//since there are changes in the tree, the flag should be set again
	if(root->child[0]!=NULL){	// recursively traverse the tree
		for(int i=0;i<4;i++){
			adjustTree(root->child[i]);
		}
	}
	return;
}

// Function that used to adjust the whole tree automatically until the tree will not change
void adapt(Node *root){
	int temp_remove_count = remove_count;	//set the temporary removing count
	int temp_add_count = add_count;	// set the temporary adding count
	int end_loop = 1;	//set the mark of loop to be true
	while(end_loop!=0){
		setTree(root);	//set the flag first
		adjustTree(root);	//adjust the tree
		if((temp_remove_count==remove_count) && (temp_add_count==add_count))	//if no changes happened, end the loop
			end_loop = 0;
		else{	//if changes happend, refresh the temporary counts
			temp_remove_count = remove_count;
			temp_add_count = add_count;	
		}
		printf("add:%d remove:%d\n",add_count, remove_count);
	}
	return;
}
