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
	Node *head;
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	
	/* task 1 test 1
	growTree(head); 
  	growTree(head); */
	
	/* task 1 test 2
	growTree(head); 
  	makeChildren(head->child[0]);
  	makeChildren(head->child[2]); */
	
	/* task 2 test 1
	growTree(head); 
	growTree(head);
  	removeChildren(head->child[1]);*/
	
	/* task 2 test 2
	growTree(head); 
	makeChildren(head->child[0]);
  	makeChildren(head->child[2]);
	removeChildren(head->child[1]);*/
	
	/* task 3 
	printf("Enter the maxLevel:\n");
	scanf("%d",&maxLevel);
	growTree(head); 
  	growTree(head); 
  	growTree(head); 
  	setTree(head);
  	adjustTree(head);
	printf("add:%d remove:%d\n",add_count, remove_count);*/
	
	/* task 3 extended
	printf("Enter the maxLevel:\n");
	scanf("%d",&maxLevel);
	growTree(head); 
  	growTree(head); 
  	growTree(head); 
  	adapt(head);
	printf("add:%d remove:%d\n",add_count, remove_count);*/
	
	writeTree(head);	// print the tree for Gnuplot
	destroyTree(head);	// free all the memory
  return 0;
}

