/*
 Date: 04/08/2020
 Program: Implement a Insetion sort algorithm
 Author: Malick Diakite

 Time complexity: O(n2)
*/

#include <stdio.h>

#define SIZE 5

void insertionSort(int *arr);
void display(int *arr);

int main(void)
{
    int arr[SIZE], i;

    printf("Enter 5 intergers\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr);

    printf("After Sorting Process\n");
    display(arr);

    return 0;
}

void display(int *arr)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("arr[%d] = %d\t", i, *(arr + i));
    }
}
void insertionSort(int *arr)
{
    int i, key, index, min;

    // i Start form second index till i is less n
    for (i = 1; i < SIZE; i++)
    {

        // Get the value of the at i'th index
        key = *(arr + i);

        // Get Previous index
        index = i - 1;

        /* while index is not -1 to avoid negative indexing
      and value at arr[index] > than value at i'th index 
    */
        while (index >= 0 && key < *(arr + index))
        {
            // move value at arr[index] to arr[index + 1]
            *(arr + index + 1) = *(arr + index);
            //decrease index by 1
            index -= 1;
        }
        *(arr + index + 1) = key;
    }
}
