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

node*
create_node ()
{
  node*p = malloc (sizeof (node));
  memset (p, 0, sizeof (node));
  return p;
}

//node*
//input_node_data (node *n, int i)
//{
//  n->data = i;
//  return n;
//}

int
is_empty (node* n)
{
  if (NULL == n)
    return TRUE;
  return FALSE;
}

int
delete_node (node*n)
{
  if (TRUE == is_empty (n))
    return FALSE;
  free (n);
  return TRUE;
}

void
display_node (node* n)
{
  printf ("%d\n", n->data);
}
