// main
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "destroy.h"
#include "writeTree.h"
#include "buildTree.h"



int main( int argc, char **argv ) {

	Node *head;
	
	// make the head node
	head = makeNode( 0.0,0.0, 0 );	
	// make a tree
	//makeChildren( head );
	int mark;
	growTree(head);
	//growTree(head);
	makeChildren(head->child[0]);
	makeChildren(head->child[2]);
	removeChildren(head->child[1]);
	// print the tree for Gnuplot
	writeTree( head );	
	destroyTree(head);	
  return 0;
}
