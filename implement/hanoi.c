/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
// Our mission is to move all plates from the 'Start' tower(A) to 'Stop' tower(C) by using 'temp' tower(B).

void
Hanoi (int plate, char a, char b, char c)
{
  if (1 == plate)
    {
      printf ("move plate %d from %c to %c\n", plate, a, b);
      printf ("move plate %d from %c to %c\n", plate, b, c);
    }
  else
    {
      Hanoi (plate - 1, a, b, c);
      printf ("move plate %d from %c to %c\n", plate, a, b);
      Hanoi (plate - 1, c, b, a);
      printf ("move plate %d from %c to %c\n", plate, b, c);
      Hanoi (plate - 1, a, b, c);
    }
}

void
hanoi (int plate)
{
  Hanoi (plate, 'A', 'B', 'C');
}
