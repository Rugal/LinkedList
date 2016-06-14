#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

 
    typedef struct dynamicarray {
        int *data;
        int number_of_data;
        int size_of_array;
    } dynamic_array;
    
  //constructor & destructor
  dynamic_array* createArray(int size);
  void deleteArray(dynamic_array* array);
  //--------------------------------------------
  /*
    Clean an array so it looks as if just created
   */
  void cleanArray(dynamic_array* array);
  
  /*
    Get data at the index of an array
   */
  int indexAt(dynamic_array* array, int index);
  
  /*
    Add a data at the end of array
   */
  void append(dynamic_array* array, int data);
  
  /*
    Insert the data in specific index position
   */
  void insertAt(dynamic_array* array, int data, int index);
  
  /*
    Delete the data in specific index position
   */
  void deleteAt(dynamic_array* array, int index);
  
  /*
    Update the data in specific index position
   */
  void updateAt(dynamic_array* array, int data, int index);
  
  /*
    See if this array is empty
   */
  bool isEmpty(dynamic_array* array);
#ifdef __cplusplus
}
#endif

#endif /* DYNAMICARRAY_H */
