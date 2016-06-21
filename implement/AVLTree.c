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
    T3  T4 T2  T1 
 */
static Node* rightRotate(Node*);
/*
    Turn the tree 
    
   [x]              
   / \
 T1   [y]   
      / \
    T2  [z]
        / \ 
      T3   T4
     
    into
  
        [y] 
        / \
     [x]   [z]
     / \   / \
  T1  T2  T3  T4
 */
static Node* leftRotate(Node*);
