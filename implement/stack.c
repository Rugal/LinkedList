/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 /* 
 * File:   stack.c
 * Author: HYH
 *
 * Created on 2016年7月5日, 上午12:31
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Node
{
  int data;
  struct Node* next;
} NODE;

struct Stack
{
  NODE * head;
  int size_of_stack;
};

NODE *
create_node ()//create a new node and initialize this node
{
  NODE * n = malloc (sizeof (NODE));
  assert (n);
  memset (n, 0, (sizeof (NODE)));
  return n;
}

static void
delete_node (NODE *n)
{
  free (n);
}

stack *
create_stack ()
{
  stack * s = malloc (sizeof (stack));
  assert (s);
  memset (s, 0, (sizeof (stack)));
  return s;
}

int
is_empty (stack * s)
{
  assert (s);
  if (s->size_of_stack == 0)
    return true;
  return false;
}

void
push (stack * s, int data)// add the new data on head of stack(DEMON subordinates 1)
{
  assert (s);
  NODE * n = create_node ();
  n->data = data;
  if (!s->head)
    s->head = n;
  else
    {
      n->next = s->head;
      s->head = n;
    }
  s->size_of_stack++;
}

int
pop (stack* s)//get the first data and delete it from stack(DEMON subordinates 2)
{
  assert (s);
  int data = peek (s);
  NODE * temp = s->head;
  if (s->head->next)
    {
      s->head = s->head->next;
    }
  delete_node (temp);
  s->size_of_stack--;
  return data;
}

int
peek (stack *s)//get the first data (DEMON subordinates 3)
{
  assert (s);
  assert (!is_empty (s));
  return s->head->data;
}

void
delete_stack (stack * s)
{
  assert (s != NULL);
  while (!is_empty (s))
    pop (s);
}
//author:Thanks undercover Mr.pop
// DEMON:WTF??
//pop; For the glory!
