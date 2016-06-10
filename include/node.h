#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Node {
        int data;
        struct Node * previous;
        struct Node * next;
    } node;

    int
    delete_node(node*n);
    int
    is_empty(node* n);
    node*
    create_node();
#ifdef __cplusplus
}
#endif

#endif /* NODE_H */
