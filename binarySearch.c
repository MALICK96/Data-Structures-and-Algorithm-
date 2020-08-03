/*
  Date: 03/08/2020
  Program: Implement a Binarny Search Algorithm 
    to an array to find if the number is present or not  
  Author: Malick Diakite

  runtime is O(log n)
*/
#include <stdio.h>

#define FALSE -1
#define SIZE 10

int binarySearch(int *, int);

int main(void)
{
  // Variables declaration
  int arr[SIZE], i, key, pos;

  // Prompt for the integers
  printf("Enter 10 ordored integers: \n");

  // Read The Elements in the array
  for (i = 0; i < SIZE; i++)
  {
    printf("Enter arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  // Prompt for the integer to be searched
  printf("Enter the integer number to be searched: ");
  scanf("%d", &key);

  // Get return value of the function
  pos = binarySearch(arr, key);

  /* check IF pos is eqaul to -1
    if it is that means element not found at any index*/
  if (pos == -1)
    printf("Element is Not Found\n");
  else
    printf("Element Found at index %d\n", pos);
  return 0;
}

int binarySearch(int *arr, int key)
{
  int low, high, mid, i;

  // lower bound
  low = 0;

  // upper bound
  high = SIZE - 1;

  /*
    while lower bound is not
    equal to upper bound
  */
  while (low != high)
  {
    // Get the midpoint of the array
    mid = (low + high) / 2;

    // if mid is eqaul to key
    if (*(arr + mid) == key)
      return mid;
    //else if it is less key
    else if (*(arr + mid) < key)
      // lower start at mid + 1
      low = mid + 1;
    else
      // high start at mid - 1
      high = mid - 1;
  }

  // If Element Not found
  return FALSE;
}