#include <stdio.h>

#define SIZE 5

void bubbleSort(int *arr);
void display(int *arr);

int main(void)
{
    int arr[SIZE], i;

    printf("Enter 5 integers in the array\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Sort the array elements
    bubbleSort(arr);

    printf("\nAfter Sorting Process\n");
    // Display the array elements
    display(arr);

    return 0;
}

void bubbleSort(int *arr)
{
    int i, t, swapped;

    while (1)
    {
        // Set a swapped to 0
        swapped = 0;

        for (i = 0; i < SIZE - 1; i++)
        {
            // if the i'th elem > next i'th elem
            if (*(arr + i) > *(arr + i + 1))
            {
                // swapping logic
                t = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = t;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void display(int *arr)
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("arr[%d]: %d\t", i, *(arr + i));
    }
}