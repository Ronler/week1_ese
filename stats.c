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

  print_array(test);
  print_statistics(test);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *array){
  printf("Median of array: %d\n", find_median(array));
  printf("Maximum of array: %d\n", find_maximum(array));
  printf("Minimum of array: %d\n", find_minimum(array));
  printf("Mean of array: %d\n\n", find_mean(array));
}

void print_array(unsigned char *arr){
  for (int i = 0; i < SIZE;  i++){
    if (i%8==0)
      printf("\n");
    printf(" %d ", arr[i]);
  }
  printf("\n\n");
}

void sort_array(unsigned char *arr){

}

int find_median(unsigned char *ptr){
  int mid = SIZE/2;
  return ptr[mid];
}

int find_maximum(unsigned char *arr){
  int max = 0;

  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int find_minimum(unsigned char *arr){
  int min = arr[0];

  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

int find_mean(unsigned char *arr){
  int mean = 0;

  for (int i = 0; i < SIZE; i++)
  {
    mean += arr[i];
  }
  return (mean / SIZE);
}