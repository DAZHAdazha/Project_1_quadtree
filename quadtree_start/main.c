// main
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );
  for(int i=0;i<4;i++){
    makeChildren( head->child[i] );
  }
  

  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}
