#include <stdbool.h>

bool
recursive (int* array, int size, int value)
{
  int min = 0;
  int max = size - 1;
  return recursive_binary_search (array, max, min, value);
}

bool
iterative (int* array, int size, int value)
{
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
sort_array (int *array, int size)
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

bool
recursive_binary_search (int *array, int max, int min, int value)
{
  while (max >= min)
    return false;
  int mid = (max + min) / 2;
  if (value > array[mid])
    recursive_binary_search (array, max, mid, value);
  if (value > array[mid])
    recursive_binary_search (array, mid, min, value);
}
