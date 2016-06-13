#include "DynamicArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

dynamic_array*
createArray (int size)
{
  dynamic_array * array = malloc (sizeof (dynamic_array));
  array->data = malloc ((size * sizeof (int)));
  memset (array->data, 0, (size * sizeof (int)));
  array->size_of_array = size;
  array->number_of_data = 0;
  return array;
}

void
cleanArray (dynamic_array* array)
{
  //Remember to check validity of array pointer
  memset (array->data, 0, (array->size_of_array * sizeof (int)));
}

int
indexAt (dynamic_array* array, int index)
{
  //Remember to check validity of array pointer
  //So your index starts from 1?
  //Why not starts from 0 so that you just need to access data with data[index]
  if (index < 1 || index > array->size_of_array)
    {
      //In this case you should exit
      printf ("It is not a correct position\n");
      //    exit (1);
      return false;
    }
  return array->data[index - 1];
}

void
append (dynamic_array* array, int data)
{
  //Remember to check validity of array pointer
  array->size_of_array++;//this means you will only extend array by 1 for each time
  //Resize itself is a function that should be modularize, since it will be used repeatedly
  array->data = realloc (array->data, (array->size_of_array) * sizeof (int));
  //Error, this will literally place the data at the end of array.
  //But you need to place it right after the last element in array
  array->data[(array->size_of_array) - 1] = data;
  array->number_of_data++;
}

void
insertAt (dynamic_array* array, int data, int index)
{
  if (index < 1)
    {
      printf ("void insert position\n");
      return;
    }
  array->number_of_data++;
  while (index > array->size_of_array)
    {
      array->size_of_array = (array->size_of_array) * 2;
      printf ("%d!!!!!!\n", array->size_of_array);
      array->data = realloc (array->data, (array->size_of_array) * sizeof (int));
    }
  array->data[index - 1] = data;

}

void
deleteAt (dynamic_array* array, int index)
{
  if (index < 1 || index > array->size_of_array)
    {
      printf ("void delete position\n");
      return;
    }

  int temp = index - 1;
  while (temp < array->size_of_array)
    {
      array->data[temp] = array->data[temp + 1];
      temp++;
    }
  array->data = realloc (array->data, (array->size_of_array - 1) * sizeof (int));
  array->size_of_array--;
  array->number_of_data--;
}

void
updateAt (dynamic_array* array, int data, int index)
{
  if (index > array->size_of_array || index < 1)
    {
      printf ("It is not a correct position\n");
      return;
    }
  array->data[index - 1] = data;
  printf ("!!!!\n");
}

void
isEmpty (dynamic_array* array)
{
  if (0 == array->number_of_data)
    {
      printf ("this array is empty\n");
      return;
    }
    printf ("this array is not empty\n");
}
