#include <stdlib.h>
#include "AVLtree.h"
#include "stack.h"

void
traverse (AVLtree * tree)
{
  assert (tree);
  stack * s = create_stack ();
  node * p = tree->root;
  printf ("%d\n", p->data);
  push (s, p);
  p = p->left;
  while (!is_empty (s))
    {
      while (p != NULL)
        {
          printf ("%d\n", p->data);
          if (p->left != NULL)
            {
              push (p);
              p = p->left;
            }
          else break;
        }
      p = pop (s);
      p = p->right;
      printf ("%d\n", p->data);
      push (p);
    }
}
