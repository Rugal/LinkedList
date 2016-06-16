/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdbool.h>
#include <stdlib.h>
bool
recursive_binary_search (int *array, int max, int min, int value);
void
sort_array (int *array, int size);

bool
recursive_binary_search (int *array, int max, int min, int value) //O(1)?O(n)?
{
  if (max < min)
    return false;
  int mid = (max + min) / 2;
  if (value == array[mid])
    return true;
  if (value > array[mid])
    return recursive_binary_search (array, max, mid+1, value);
  else
    return recursive_binary_search (array, mid-1, min, value);

}

bool
recursive (int* array, int size, int value)//if not found,it always return 4. why? 
{
  if (NULL == array || size <= 0)
    return false;
  int min = 0;
  int max = size - 1;
  return recursive_binary_search (array, max, min, value);
}

bool
iterative (int* array, int size, int value)//O(n)
{
  if (NULL == array || size <= 0)
    return false;
  sort_array (array, size);
  int mid = size / 2;
  int min = 0;
  int max = size - 1;
  int temp = 0;
  if (array[min] == value || array[max] == value)
    return true;
  while (max >= min)
    {
      if (value > array[mid])
        {
          min = mid;
          mid = (min + max) / 2;
          if (temp == min)
            {
              return false;
            }
          temp = min;
        }
      if (value < array[mid])
        {
          max = mid;
          mid = (min + max) / 2;
          if (temp == max)
            {
              return false;
            }
          temp = max;
        }
      if (value == array[mid])
        return true;
    }
  return false;
}

void
sort_array (int *array, int size)//O(n^2)?
{
  for (int i = 0; i < size - 1; i++)
    {
      for (int j = i + 1; j < size; j++)
        {
          if (array[i] > array[j])
            {
              int temp = array[i];
              array[i] = array[j];
              array[j] = temp;
            }
        }
    }
}

bool binarySearch(int *data, int size, int value)//Rugal
{
    assert(data!=NULL);
    sort(data, size);
    int min = 0, max = size-1;
    while(min<=max)
    {
        int mid = (min+max)/2;
        if(data[mid] == value)
            return true;
        if(data[mid]>value)//in left segment
            max = mid-1;
        else
            min = mid+1;
    }
    return false;
}


