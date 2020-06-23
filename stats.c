/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c  
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author Aaron Miller
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_array(test, SIZE);
  printf("Median of array: %d\n", find_median(test, SIZE));
  printf("Maximum of array: %d\n", find_maximum(test, SIZE));
  printf("Minimum of array: %d\n", find_minimum(test, SIZE));
  printf("Mean of array: %d\n\n", find_mean(test, SIZE));
  /*print_statistics(test, SIZE);*/

}

/* Add other Implementation File Code Here */

/*void print_statistics(unsigned char *array, int size){
  
  printf("The original Array:\n");
  print_array(array, size);
  sort_array(array, size);
  printf("Sorted array:\n");
  print_array(array, size);
  printf("Median of array: %d", find_median(array, size));
  printf("Mean of array: %d", find_mean(array, size));
  printf("Max of array: %d", find_maxinum(array, size));
  printf("Min of array: %d", find_minimum(array, size));
}
*/
void print_array(unsigned char *arr, int len){
  for (int i = 0; i < len;  i++){
    if (i%8==0)
      printf("\n");
    printf(" %d ", arr[i]);
  }
  printf("\n\n");
}

void sort_array(unsigned char *arr, int len){

}

int find_median(unsigned char *ptr, int len){
  int mid = len/2;
  return ptr[mid];
}

int find_maximum(unsigned char *arr, int len){
  int max = 0;

  for (int i =0; i < len; i++){
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int find_minimum(unsigned char *arr, int len){
  int min = arr[0];

  for (int i = 0; i < len; i++){
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

int find_mean(unsigned char *arr, int len){
  int mean = 0;

  for (int i = 0; i < len; i++){
    mean += arr[i];
  }
  return (mean / len);
  
}