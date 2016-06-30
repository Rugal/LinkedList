/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sort.h"
#include <stdlib.h>
void merge_sort (int data[], int size, int start, int end);
void merge_array (int data[], int start, int mid, int end);

void
mergeSort (int data[], int size)
{
  return merge_sort (data, size, 0, size);
}

void
merge_sort (int data[], int size, int start, int end)
{
  if (size < 1 || !data)
    return;
  merge_sort (data, size / 2, 0, size / 2);
  merge_sort (data, size / 2, size / 2, size);
  merge_array (data, start, end);
}

void
merge_array (int data[], int start, int end)
{
  int *array = malloc ((end - start + 1) * sizeof (int));


}
