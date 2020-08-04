#include <stdio.h>

#define SIZE 5

// Fuctions prototypes declaration 
void selectionSort(int *arr);
void display(int *arr);

int main(void) {
  // Variables declaration 
  int arr[SIZE], i;

  // Prompt for the elements 
  printf("Enter 5 Element in the array\n");
  for (i = 0; i < SIZE; i++) {
    printf("arr[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  // selection sort function call
  selectionSort(arr);

  printf("After Sorting Process\n");
  
  // Display the elements 
  display(arr);
  
  return 0;
}

void selectionSort(int *arr) {
 // Variables declarations 
  int i, j, min, t;

  // Iterarte from  i = 0 to i < SIZE-1
  for (i = 0; i < SIZE - 1; i++) {
    // Get the i'th index as min 
    min = i;
    // Iterarte from  j = i + 1 to j < SIZE
    for (j = i + 1; j < SIZE; j++) {
      // check if value at min index is greater  
      if (*(arr + min) > *(arr + j)) {
        // Swap Logic
        t = *(arr + min);
        *(arr + min) = *(arr + j);
        *(arr + j) = t; 
      }
    }     
  }
}

// Display the array elements
void display(int *arr) {
  int i;
  for (i = 0; i < SIZE; i++) {
    printf("arr[%d]: %d\t", i, *(arr + i));
  }
}
