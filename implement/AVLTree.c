/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "AVLtree.h"

#define MAX(A, B)    ( A > B ? A : B )

typedef struct node node;

struct node
{
  node *left, *right;
  int data, height;
};

#define HEIGHT(NODE)    ( (NODE==NULL) ? 0 : (((node *)(NODE))->height) )

typedef struct AVLtree
{
  node *root;
  int size;
} AVLtree;

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
static node*
rightRotate (node* unbalance_node)
{
  node * rnode;
  rnode = unbalance_node->left;
  unbalance_node->left = rnode->right;
  rnode->right = unbalance_node;
  unbalance_node->height = MAX (HEIGHT (unbalance_node->left), HEIGHT (unbalance_node->right)) + 1;
  rnode->height = MAX (HEIGHT (rnode->left), HEIGHT (rnode->right)) + 1;
}

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
static node*
leftRotate (node* unbalance_node)
{
  node * lnode;
  lnode = unbalance_node->right;
  unbalance_node->right = lnode->left;
  lnode->left = unbalance_node;
  unbalance_node->height = MAX (HEIGHT (unbalance_node->left), HEIGHT (unbalance_node->right)) + 1;
  lnode->height = MAX (HEIGHT (lnode->left), HEIGHT (lnode->right)) + 1;
}
