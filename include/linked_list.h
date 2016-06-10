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
    creat_linked_list();
    linked_list*
    add_on_head(linked_list *list);
    int
    size_of_list(linked_list *list);
    linked_list*
    add_on_tail(linked_list *list);
    linked_list*
    delete_list(linked_list *list);
    linked_list*
    updata(linked_list *list, int position, int value);
    linked_list*
    sort_list(linked_list *list);
    void
    display_list(linked_list * list);
    linked_list*
    input_data(linked_list * list, int position, int value);
#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */
