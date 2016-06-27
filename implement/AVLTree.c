
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>
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
};

static node*
right_rotate (node* unbalance_node);
static node*
left_rotate (node* unbalance_node);
static node*
right_left_rotate (node* unbalance_node);
static node*
create_node ();
static node *
insert_node (node* n, int data);
static node*
delete_node (node * n, int data);
static node*
find_max_data (node * n);
static node*
find_min_data (node * n);

static node*
find_min_data (node * n)
{
  if (NULL == node)
    return NULL;
  while (node->left)
    node = node->left;
  return node;
}

// exit (1) : unable to allocate space for this tree(node)
// exit (2) : user add the same data
// exit (3) ; user deletes a non-existent data

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
right_rotate (node* unbalance_node)
{
  node * lnode;
  lnode = unbalance_node->left;
  unbalance_node->left = lnode->right;
  lnode->right = unbalance_node;
  unbalance_node->height = MAX (HEIGHT (unbalance_node->left), HEIGHT (unbalance_node->right)) + 1;
  lnode->height = MAX (HEIGHT (lnode->left), HEIGHT (lnode->right)) + 1;
  return lnode;
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
left_rotate (node* unbalance_node)
{
  node * rnode;
  rnode = unbalance_node->right;
  unbalance_node->right = rnode->left;
  rnode->left = unbalance_node;
  unbalance_node->height = MAX (HEIGHT (unbalance_node->left), HEIGHT (unbalance_node->right)) + 1;
  rnode->height = MAX (HEIGHT (rnode->left), HEIGHT (rnode->right)) + 1;
}

static node*
right_left_rotate (node* unbalance_node)
{
  unbalance_node->right = right_rotate (unbalance_node->right);
  return left_rotate (unbalance_node);
}

static node*
left_right_rotate (node* unbalance_node)
{
  unbalance_node->right = left_rotate (unbalance_node->right);
  return right_rotate (unbalance_node);
}

AVLtree*
createTree ()
{
  AVLtree * tree = malloc (sizeof (AVLtree));
  if (NULL == tree)
    {
      printf ("ERROR: unable to allocate space for this tree\n");
      exit (1);
    }
  tree->root = create_node ();
  tree->size = 0;
  return tree;
}

static node*
create_node ()
{
  node * n = malloc (sizeof (node));
  if (NULL == n)
    {
      printf ("ERROR: unable to allocate space for this node\n");
      exit (1);
    }
  memset (n, 0, sizeof (node));
  return n;
}

void
insert (AVLtree* tree, int data)
{
  insert_node (tree->root, data);
  tree->size++;
}

node *
insert_node (node* root, int data)
{
  if (NULL == root)
    {
      root = create_node ();
      root->data = data;
      return root;
    }
  if (data == root->data)
    {
      return root;
    }
  if (root->data < data)
    {
      root->right = insert_node (root->right, data);
      if (HEIGHT (root->left) - HEIGHT (root->right) < -1)
        if (root->right->data < data)
          root = left_rotate (root);
        else
          root = right_left_rotate (root);
    }
  else
    {
      root->left = insert_node (root->left, data);
      if (HEIGHT (root->left) - HEIGHT (root->right) > 1)
        if (root->left->data > data)
          root = right_rotate (root);
        else
          root = left_right_rotate (root);
    }
  root->height = MAX (HEIGHT (root->left), HEIGHT (root->right)) + 1;
  return root;
}

void
delete (AVLtree* tree, int data)
{
  if (NULL == tree)
    return;
  delete_node (tree->root, data);
  tree->size--;
}

static node*
delete_node (node * root, int data)
{
  if (NULL == root)
    {
      return root;
    }
  if (root->data == data)
    {
      if (NULL == root->left && NULL == root->right)
        {
          free (root);
          return NULL;
        }
      if (root->left != NULL && root->right != NULL)
        {
          if (HEIGHT (root->left) > HEIGHT (root->right))
            {
              node * max_data_of_left_subtree = find_max_data (root->left);
              root->data = max_data_of_left_subtree->data;
              delete_node (max_data_of_left_subtree);
            }
          else
            {
              node * min_data_of_right_subtree = find_min_data (root->right);
              root->data = min_data_of_right_subtree->data;
              delete_node (min_data_of_right_subtree);
            }
        }
      else
        {
          node* temp = root->right ? root->right : root->left;
          free (root);
          root = temp;
        }
    }
  if (root->data > data)
    {
      root->left = delete_node (root->left, data);

    }
  else
    {
      root->right = delete_node (root->right, data);
    }
  root->height = MAX (HEIGHT (root->left), HEIGHT (root->right)) + 1;
  return root;
}

static node*
find_max_data (node * node)
{
  if (NULL == node)
    return NULL;
  while (node->right)
    node = node->right;
  return node;
}
