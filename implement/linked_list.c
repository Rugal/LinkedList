/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"
#define TRUE 1
#define FALSE 0

linked_list*
create_linked_list ()
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
      list->head = list->tail = n;
    }
    else
    {
      node * current = list->head;
      list->head = n;
      list->head->next = current;
      current->previous = list->head; 
    }
  list->size++;
  return list;
}

//linked_list*
//input_data (linked_list * list, int position, int value)
//{
//  list->size = size_of_list (list);
//  if (position > list->size || position < 1)
//    {
//      printf ("void input position\n");
//      return list;
//    }
//  linked_list *temp = list;
//  for (int i = 1; i < list->size; i++)
//    {
//      list->head = list->head->next;
//    }
//  list->head->data = value;
//  return temp;
//}

linked_list*
input_data (linked_list * list, int position, int value)
{

  if (position > list->size || position < 1)
    {
      printf ("void input position\n");
      return list;
    }
  node *temp = list->head;
  int counter = 1;
  while (position > counter)
    {
      temp = temp->next;
      counter++;
    }
  temp->data = value;

  return list;
}

//linked_list*
//size_of_list (linked_list *list)
//{
//  linked_list *temp = list;
//  int counter = 0;
//  while (FALSE == is_empty (list->head))
//    {
//      counter++;
//      list->head = list->head->next;
//    }
//  list->size = counter;
//  return temp;
//}

linked_list*
add_on_tail (linked_list *list)
{
  node * n = create_node ();
  if (TRUE == is_empty (list->tail))
    {
      list->head = n;
      list->tail = n;
      list->size++;
      return list;
    }
  node* temp = list->head;
  node * last = temp;
  while (1)
    {

      while (TRUE == is_empty (temp))
        {
          last->next = n;
          list->tail = n;
          list->size++;
          return list;
        }
      last = temp;
      temp = temp->next;
    }
  //  node*current = list->tail;
  //  list->tail = n;
  //  list->tail->previous = current;
  //  current->next = list->tail;

  return list;
}

void
delete_list (linked_list *list)
{
  if (TRUE == is_empty (list->head))
    {
      free (list);
      list->size--;

    }
  while (FALSE == is_empty (list->head))
    {
      node*temp = list->head;
      list->head = list->head->next;
      delete_node (temp);
    }
  free (list);
  list->size--;

}

//linked_list*
//updata (linked_list *list, int position, int value)
//{
//  if (list->size < position || position < 1)
//    return list;
//  node*current = list->head;
//  for (int i = 1; i <= position; i++)
//    current = current->next;
//  current->data = value;
//  return list;
//}

linked_list*
sort_list (linked_list *list)
{

  node * value1 = list->head;
  node * value2 = list->head->next;
  while (NULL != value2)
    {
      if (value1->data > value2->data)
        {
          //          node * temp_;
          //          temp = value2;
          //          value2->previous = value1->previous;
          //          value2->next = value1;
          //          value1->next = temp->next;
          //          value1->previous = value2;
          //          node * temp_previous = value2->previous;
          //          node * temp_next = value2->next;
          //          value2->next = value1->next;
          //          value2->previous = value1->previous;
          //          value1->next = temp_next;
          //          value2->previous = temp_previous;
          //          list->head = value2;
          value2->previous->next = value2->next;//segemetation fault
          value1->previous = value2;
          value2->next = value1;
          list->head = value2;
          value1 = list->head;
          value2 = list->head->next;
          display_list (list);
          printf ("!!!!\n");
        }
      value2 = value2->next;
    }
  value2 = list->head->next;
  //still not work
  for (int i = 1; i <= list->size - 1; i++)
    {
      for (int j = 1; j <= list->size - 1 - i; j++)
        {
          if (value1->data > value2->data)
            {
              //              node*temp;
              //              temp = value2;
              //              value2->previous = value1->previous;
              //              value2->next = value1;
              //              value1->next = temp->next;
              //              value1->previous = value2;
              node *temp_previous = value2->previous;
              node *temp_next = value2->next;
              value2->next = value1->next;
              value2->previous = value1->previous;
              value1->next = temp_next;
              value2->previous = temp_previous;
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

linked_list*
delete_one_node (linked_list * list, int position)
{
  if (position > list->size)
    {
      printf ("void delete position\n");
      return list;
    }
  node * temp = list->head;
  node * last = temp;
  if (1 == position)
    {
      list->head = temp->next;
      free (temp);
      list->head->previous = NULL;
      list->size--;
      return list;
    }


  while (NULL != temp)
    {
      for (int i = 1; i < position; i++)
        {
          last = temp;
          temp = temp->next;
        }
      last->next = temp->next;
      free (temp);
      list->size--;
      return list;
    }
  temp = list->tail;
  list->tail = temp->previous;
  list->tail->next = NULL;
  free (temp);
  list->size--;
  return list;

}
