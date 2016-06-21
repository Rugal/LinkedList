#ifndef AVLTREE_H
#define AVLTREE_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct Node Node;
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
  void insertTree(AVLTree*, int data);
  
  
#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */
