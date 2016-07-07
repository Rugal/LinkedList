/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLtree.h
 * Author: Administrator
 *
 * Created on 2016年6月23日, 上午5:30
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#ifdef __cplusplus
extern "C" {
#endif


    typedef struct AVLtree AVLtree;

    /*
     * Instantiate an AVL tree object.
     */
    AVLtree* createTree();

    /*
     * Delete an AVL tree object.
     */
    void deleteTree(AVLtree* tree);

    /*
     * Insert a data into AVL tree.
     */
    void insert(AVLtree* tree, int data);

    /*
     * Delete a node from AVL tree if it exists.
     */
    void delete (AVLtree* tree, int data);
    /*
     * Traverse a tree, print it as top down, left to right order.
     */
    void traverse(AVLtree*);


#ifdef __cplusplus
}
#endif

#endif /* AVLTREE_H */

