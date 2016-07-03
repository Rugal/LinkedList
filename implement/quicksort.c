/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 2016/7/3 HYH
 */
#include "sort.h"
#include <stdlib.h>

static void quick_sort (int data[], int start, int end);
static void swap (int array[], int a, int b);

void
quickSort (int data[], int size)
{
  if (!data || size < 1)
    return;
  quick_sort (data, 0, size - 1);
}

void
quick_sort (int data[], int start, int end)
{
  if (start < end)
    {
      int current_index1, current_index2, current_data;
      int mid = (start + end) / 2;
      if (data[start] > data[end] && data[start] < data[mid])
        current_data = data[start];
      else if (data[end] > data[start] && data[end] < data[mid])
        {
          swap (data, end, start);
          current_data = data[start];
        }
      else
        {
          swap (data, mid, start);
          current_data = data[start];
        }
      current_index1 = start;
      current_index2 = end;
      while (current_index1 < current_index2)
        {
          while (current_index1 < current_index2 && data[current_index2] > current_data)
            current_index2--;
          if (current_index1 < current_index2)
            data[current_index1++] = data[current_index2];
          while (current_index1 < current_index2 && data[current_index1] < current_data)
            current_index1++;
          if (current_index1 < current_index2)
            data[current_index2--] = data[current_index1];
        }
      data[current_index1] = current_data;
      quick_sort (data, start, current_index1 - 1);
      quick_sort (data, current_index1 + 1, end);
    }
}

static void
swap (int array[], int a, int b)
{
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}
