/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 2016/7/2 HYH
 */

#include "sort.h"
#include <stdlib.h>
void merge_sort (int data[], int start, int end);
void merge_array (int data[], int start, int mid, int end);

void
mergeSort (int data[], int size)
{
  merge_sort (data, 0, size - 1);
}

void
merge_sort (int data[], int start, int end)
{
  if (start < end && data)
    {
      int mid = (end + start) / 2;
      merge_sort (data, start, mid);
      merge_sort (data, mid + 1, end);
      merge_array (data, start, mid, end);
    }

}

void
merge_array (int data[], int start, int mid, int end)
{
  int *dynamic_array = malloc ((end - start + 1) * sizeof (int));
  int array1_start = start;
  int array2_start = mid + 1;
  int dynamic_array_index = 0;
  while (array1_start <= mid && array2_start <= end)
    {
      if (data[array1_start] <= data[array2_start])
        dynamic_array[dynamic_array_index++] = data[array1_start++];
      else
        dynamic_array[dynamic_array_index++] = data[array2_start++];
    }
  while (array1_start <= mid)
    dynamic_array[dynamic_array_index++] = data[array1_start++];
  while (array2_start <= end)
    dynamic_array[dynamic_array_index++] = data[array2_start++];
  for (int i = 0; i < dynamic_array_index; i++)
    data[start + i] = dynamic_array[i];
  free (dynamic_array);
}

