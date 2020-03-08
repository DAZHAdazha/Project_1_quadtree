// tree data structure
#ifndef mark
#define mark 1
struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag; 
};
typedef struct qnode Node;
#endif

