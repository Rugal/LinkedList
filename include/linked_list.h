#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct LinkedList {
        node* head;
        node* tail;
        int size;
    } linked_list;

    linked_list*
    create_linked_list();
    linked_list*
    add_on_head(linked_list *list);
    linked_list*
    add_on_tail(linked_list *list);
    linked_list*
    delete_one_node(linked_list * list, int position);
    void
    delete_list(linked_list *list);
    linked_list*
    updata(linked_list *list, int position, int value);
    linked_list*
    sort_list(linked_list *list);
    void
    display_list(linked_list * list);

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */
