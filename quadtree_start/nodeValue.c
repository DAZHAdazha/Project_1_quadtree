#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "nodeValue.h" 
// Evaluate function at centre of quadtree node
int add_count = 0;
int remove_count = 0;
extern int maxLevel;
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

void stage_1(Node *root){
	if(root->child[0]==NULL){
	double current_value = nodeValue(root, 0.0);
		if(current_value>0.5){
			root->flag = 1;
		}
		else if(current_value<-0.5){
			root->flag = -1;
		}
	}
	else{
		for(int i=0;i<4;i++){
			stage_1(root->child[i]);
		}
	}
	return;
}
void stage_2(Node *root){
	if(root->child[0]==NULL){
		if((root->flag==1) && (root->level<maxLevel)){
			makeChildren(root);
			add_count += 4;
		}
	}
	else{
		int sum = 0; 
		for(int i=0;i<4;i++){
			sum += root->child[i]->flag;
		}
		if(sum==-4){
			removeChildren(root);
			remove_count += 4;
		}
	}
	stage_1(root);
	if(root->child[0]!=NULL){
		for(int i=0;i<4;i++){
			stage_2(root->child[i]);
		}
	}
	return;
}

void adapt(Node *root){
	int temp_remove_count = remove_count;
	int temp_add_count = add_count;
	int end_loop = 1;
	while(end_loop!=0){
		stage_1(root);
		stage_2(root);

		if((temp_remove_count==remove_count) && (temp_add_count==add_count))
			end_loop = 0;
		else{
			temp_remove_count = remove_count;
			temp_add_count = add_count;	
		}
		
	}
	return;
}
