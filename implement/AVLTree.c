#include "AVLTree.h"

typedef struct Node Node;
struct Node
{
  Node *left, *right;
  int data, height;
};

struct AVLTree AVLTree
{
  Node *root;
  int size;
};


