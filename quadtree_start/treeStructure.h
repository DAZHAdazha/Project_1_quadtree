// tree data structure
#ifndef flag
#define flag 1
struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
};
typedef struct qnode Node;
#endif

