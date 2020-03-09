// main
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "destroy.h"
#include "writeTree.h"
#include "buildTree.h"
#include "nodeValue.h"

int maxLevel;
extern int add_count;
extern int remove_count;
int main( int argc, char **argv ) {
	printf("Enter the maxLevel:\n");
	scanf("%d",&maxLevel);
	Node *head;
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	// make a tree
	//makeChildren( head );
  	growTree(head); 
  	growTree(head); 
  	growTree(head); 
	stage_1(head);
  	//makeChildren(head->child[0]);
  	//makeChildren(head->child[2]);
	//removeChildren(head->child[1]);
	// print the tree for Gnuplot
	stage_2(head);
	adapt(head);
	//showFlag(head, maxLevel);
	//stage_2(head);
	//adapt(head);
	printf("add:%d remove:%d\n",add_count, remove_count);
	writeTree(head);	
	destroyTree(head);	
  return 0;
}

