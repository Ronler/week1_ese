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

  printf("Original array:\n");
  print_array(test, SIZE);
  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  printf("Sorted array:\n");
  print_array(test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *array, unsigned int len)
{
  printf("Median of array: %d\n", find_median(array, len));
  printf("Maximum of array: %d\n", find_maximum(array, len));
  printf("Minimum of array: %d\n", find_minimum(array, len));
  printf("Mean of array: %d\n\n", find_mean(array, len));
}

void print_array(unsigned char *arr, unsigned int len)
{
  for (int i = 0; i < len;  i++){
    if (i%8==0)
      printf("\n");
    printf(" %d ", arr[i]);
  }
  printf("\n\n");
}

void sort_array(unsigned char *arr, unsigned int len)
{
  int i, j;

  for (i = 0; i < (len-1); i++){
    for ( j = 0; j < (len-i-1); j++){
      if(arr[j] < arr[j+1]){
        swap(&arr[j+1], &arr[j]);
      }
    }
  }
}

void swap(unsigned char *x, unsigned char *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

unsigned char find_median(unsigned char *ptr, unsigned int len)
{
  int mid = len/2;
  return ptr[mid];
}

unsigned char find_maximum(unsigned char *arr, unsigned int len)
{
  int max = 0;

  for (int i = 0; i < len; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

unsigned char find_minimum(unsigned char *arr, unsigned int len)
{
  int min = arr[0];

  for (int i = 0; i < len; i++)
  {
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

unsigned char find_mean(unsigned char *arr, unsigned int len)
{
  int mean = 0;

  for (int i = 0; i < len; i++)
  {
    mean += arr[i];
  }
  return (mean / len);
}