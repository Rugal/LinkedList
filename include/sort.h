#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif
  
  /*
    Sort the given array with Merge Sort algorithm.
   */
  void mergeSort(int data[], int size);
  
  /*
    Sort the given array with Quick Sort algorithm.
   */
  void quickSort(int data[], int size);
  
  /*
    Sort the given array with Heap Sort algorithm.
   */
  void heapSort(int data[], int size);
  
  /*
    Sort the given array with Shell Sort algorithm.
   */
  void shellSort(int data[], int size);
  
#ifdef __cplusplus
}
#endif

#endif /* SORT_H */
