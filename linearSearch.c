/*
  Date: 03/08/2020
  Program: Implement a linear search algorithm 
    to array if to find the number is present or not. 

  Author: Malick Diakite

  The runtime of this algorithm is O(n)
  because we have to iterate in the worst case
  n time to check if the element is present or not 
*/
#include <stdio.h>

#define FALSE -1
#define SIZE 10

int linearSearch(int *, int);

int main(void) {
  // Variables declaration
  int arr[SIZE], i, key, pos;

  // Prompt for the integers  
  printf("Enter 10 unordered/ordored integers\n");

  // Read The Elements in the array
  for (i = 0; i < SIZE; i++) {
    printf("Enter arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }
  
  // Prompt for the integer to be searched
  printf("Enter the integer number to be searched: ");
  scanf("%d", &key);

  // Get return value of the function
  pos = linearSearch(arr, key);

  /* check IF pos is eqaul to -1
    if it is that means element not found at any index*/ 
  if (pos == -1)
    printf("Element is Not Found\n");
  else
    printf("Element Found at index %d\n", pos);
  return 0;
}

int linearSearch(int *arr, int key) {
  int i;

  /* Iterate through the arr elements
  and check if the current element 
  is the key? If it is return it's index */

  for (i = 0; i < SIZE; i++) {

    if (*(arr + i) == key)
      return i;
  }

  // If not found return false (ie -1)
  return FALSE;
}