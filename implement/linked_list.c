#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"
#define TRUE 1
#define FALSE 0

linked_list*
creat_linked_list ()
{
  linked_list * list = malloc (sizeof (linked_list));
  memset (list, 0, sizeof (linked_list));
  return list;
}

linked_list*
add_on_head (linked_list *list)
{
  node * n = create_node ();
  if (TRUE == is_empty (list->head))
    {
      list->head = n;
      list->tail = n;
      return list;
    }
  node * current = list->head;
  list->head = n;
  list->head->next = current;
  current->previous = list->head;
  list->size = size_of_list (list);
  return list;

}

linked_list*
input_data (linked_list * list, int position, int value)
{
  list->size = size_of_list (list);
  if (position > list->size || position < 1)
    {
      printf ("void input position\n");
      return list;
    }
  linked_list *temp=list ;
  for (int i = 1; i < list->size; i++)
    {
      list->head = list->head->next;
    }
  list->head->data = value;
  return temp;
}

int
size_of_list (linked_list *list)
{
  int counter = 0;
  while (FALSE == is_empty (list->head))
    {
      counter++;
      list->head = list->head->next;
    }
  return counter;
}

linked_list*
add_on_tail (linked_list *list)
{
  node * n = create_node ();
  if (TRUE == is_empty (list->tail))
    {
      list->head = n;
      list->tail = n;
      return list;
    }
  node * last = list->head;
  while (1)
    {

      while (TRUE == is_empty (list->head))
        {
          last->next = n;
          list->tail = n;
          return list;
        }
      last = list->head;
      list-> head = list->head->next;
    }
  //  node*current = list->tail;
  //  list->tail = n;
  //  list->tail->previous = current;
  //  current->next = list->tail;
  list->size = size_of_list (list);
  return list;
}

linked_list*
delete_list (linked_list *list)
{
  if (TRUE == is_empty (list->head))
    {
      free (list);
      return list;
    }
  while (FALSE == is_empty (list->head))
    {
      node*temp = list->head;
      list->head = list->head->next;
      delete_node (temp);
    }
  free (list);
  list->size = size_of_list (list);
  return list;
}

linked_list*
updata (linked_list *list, int position, int value)
{
  if (list->size < position || position < 1)
    return list;
  node*current = list->head;
  for (int i = 1; i <= position; i++)
    current = current->next;
  current->data = value;
  return list;
}

linked_list*
sort_list (linked_list *list)
{
  int size = size_of_list (list);
  node * value1 = list->head;
  node * value2 = list->head->next;
  while (NULL != value2)
    {
      if (value1->data > value2->data)
        {
          node * temp;
          temp = value2;
          value2->previous = value1->previous;
          value2->next = value1;
          value1->next = temp->next;
          value1->previous = value2;
        }
      value2 = value2->next;
    }
  list->head = value1;
  value2 = list->head->next;
  for (int i = 1; i <= size - 1; i++)
    {
      for (int j = 1; j <= size - 1 - i; j++)
        {
          if (value1->data > value2->data)
            {
              node*temp;
              temp = value2;
              value2->previous = value1->previous;
              value2->next = value1;
              value1->next = temp->next;
              value1->previous = value2;
            }
          value2 = value2->next;
        }
      value1 = value1->next;
    }
  return list;
}

void
display_list (linked_list * list)
{
  node * temp = list->head;
  while (NULL != temp)
    {
      display_node (temp);
      temp = temp->next;
    }
}
