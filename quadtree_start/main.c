// main
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "destroy.h"
#include "writeTree.h"
#include "buildTree.h"


void test_1(Node *head){
	grow_Tree(head);
}
void test_2(Node *head){
	grow_Tree(head);
	grow_Tree(head->child[0]);
	grow_Tree(head->child[2]);
}

int main( int argc, char **argv ) {

	Node *head;
	
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	
	// make a tree
	makeChildren( head );
	int mark;
  	printf("please enter 1 or 2 to run different test\n");
	scanf("%d",&mark);
	if (mark==1){
		test_1(head);
	}
	else if(mark==2){
		test_2(head);
	}
	
	else{
		printf("wrong input\n");
	} 
	removeChildren(head->child[1]);
	// print the tree for Gnuplot
	writeTree( head );	
		
  return 0;
}
