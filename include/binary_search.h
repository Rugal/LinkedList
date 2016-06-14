#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

  /*
    Implement binary search in recursive way.
    The parameters of this function are just for invocation, you can define your own function in .c file.
   */
  bool recursive(int* array, int size);
  /*
    Implement binary search in iterative way.
    The parameters of this function are just for invocation, you can define your own function in .c file.
   */
  bool iterative(int* array, int size);

#ifdef __cplusplus
}
#endif

#endif /* BINARY_SEARCH_H */
