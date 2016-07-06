/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   iterative_quicksort.c
 * Author: HYH
 *
 * Created on 2016年7月5日, 上午12:31
 */
#include <stdlib.h>
#include "sort.h"
#include "stack.h"
static void
iterative_quick_sort (int data[], int size);
static int
get_mid (int data[], int start, int mid, int end);
static void
swap (int array[], int a, int b);


//if no staic in function definition , the output is "Unexpected error."



static int
get_mid (int data[], int start, int mid, int end)//iterative_quicksort.c:66:1: error: static declaration of ‘get_mid’ follows non-static declaration
{
  int temp;
  if (data[start] > data[end] && data[start] < data[mid])
    temp = data[start];
  else if (data[end] > data[start] && data[end] < data[mid])
    {
      swap (data, end, start);
      temp = data[start];
    }
  else
    {
      swap (data, mid, start);
      temp = data[start];
    }
  return temp;
}

static void
swap (int array[], int a, int b)//iterative_quicksort.c:85:1: error: static declaration of ‘swap’ follows non-static declaration
{
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

static void
iterative_quick_sort (int data[], int size)//iterative_quicksort.c:23:1: error: static declaration of ‘iterative_quick_sort’ follows non-static declaration
{
  if (size < 1)//the array must have at least 1 data
    return;
  int temp_tail, temp_head;
  int temp_left, temp_right;
  stack * s = create_stack (); //create a new Stack
  int head = 0, tail = size; // index of array
  push (s, head); //push into Stack head and tail
  push (s, tail);
  while (!is_empty (s))
    {
      temp_tail = pop (s); //Get the head pointer and tail pointer of this loop
      temp_head = pop (s);
      if (temp_head < temp_tail)
        {
          int pivot = get_mid (data, temp_head, (temp_tail + temp_head) / 2, temp_tail);

          temp_left = temp_head;
          temp_right = temp_tail;
          while (temp_left < temp_right)
            {
              while (temp_left < temp_right && data[--temp_right] > pivot);
              if (temp_left < temp_right)
                data[temp_left++] = data[temp_right];
              while (temp_left < temp_right && data[++temp_left] < pivot);
              if (temp_left < temp_right)
                data[temp_right--] = data[temp_left];
            }
          data[temp_left] = pivot;
          push (s, temp_head);
          push (s, temp_left);
          push (s, temp_left + 1);
          push (s, temp_tail);
        }
    }
  delete_stack (s);
}


void
quickSort (int data[], int size)
{
  iterative_quick_sort (data, size);
}
