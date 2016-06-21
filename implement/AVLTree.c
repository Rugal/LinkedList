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

/*
    Turn the tree 
    
           [x]              
           / \
        [y]   T1   
        / \
     [z]   T2
     / \ 
   T3   T4
     
    into
  
              [y] 
              / \
           [z]   [x]
           / \   / \
        T3  T4  T2  T1 
 */
static Node* rightRotate(Node*);
static Node* leftRotate(Node*);
