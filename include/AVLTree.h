#ifndef AVLTREE_H
#define AVLTREE_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct AVLTree AVLTree;
  
  /*
   * Instantiate an AVL tree object.
   */
  AVLTree* createTree();

  /*
   * Delete an AVL tree object.
   */
  void deleteTree(AVLTree*);
  
  /*
   * Insert a data into AVL tree.
   */
  void put(AVLTree*, int data);
  
  /*
   * Delete a node from AVL tree if it exists.
   */
  void remove(AVLTree*, int data);
  
  /*
   * Traverse a tree, print it as top down, left to right order.
   */
  void traverse(AVLTree*);
  
  
#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */
