/*
 Date: 13/08/2020
 Program: Implement a stack data structure 
 with additional functionalities 
 like sorting and searching
 Author: Malick Diakite 
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Top of stack
int top = -1;

// size of the stack
int size;

// Function prototype declarations
// void init(int *);
int isFull();
int isEmpty();
int pop(int *);
int peek(int *);
void push(int *, int);
void traverse(int *);
void swap(int *, int *);
void sort(int *);
int search(int *, int);
void insert(int *, int);

int main(void)
{
    // Declaration of ptr to the stack
    int *stack;

    int elem, num, key, pos;

    // For user choice
    char choice;

    // Prompt user for the size
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    if (size > 0)
    {
        // Allocate a block of memory of size
        stack = (int *)malloc(size * sizeof(int));

        if (stack == NULL)
        {
            printf("Error: Out of memory\n");
            exit(1);
        }
    }
    else
    {
        printf("\nsize must be greater than 0\n");
        exit(2);
    }

    while (1)
    {
        // clear screen function
        system("cls");

        // Possible operations of the stack

        printf("1.Push integer(s) into the Stack\n");
        printf("2.Pop the integer from the Stack\n");
        printf("3.Peek the integer from the Stack\n");
        printf("4.Display the integer(s) of the Stack\n");
        printf("5.Add integer(s) to the stack\n");
        printf("6.Sort the element(s) of the Stack\n");
        printf("7.Search an element in the Stack\n");
        printf("0.Exit the Program");

        // Read user choice
        printf("\nEnter your choice: ");
        fflush(stdin);
        choice = getche();

        // compare choice with diff cases
        switch (choice)
        {
        case '1':
            for (int i = 0; i < size; i++)
            {
                printf("\nstack[%d]: ", i);
                scanf("%d", &elem);
                push(stack, elem);
            }
            break;
        case '2':
            printf("\nPopped integer = %d\n", pop(stack));
            system("pause");
            break;
        case '3':
            printf("\nPeeked integer = %d\n", peek(stack));
            system("pause");
            break;
        case '4':
            traverse(stack);
            system("pause");
            break;
        case '5':
            num = 0;
            printf("\nHow many integer(s) to add: ");
            scanf("%d", &num);
            if (num > 0)
                insert(stack, num);
            else
                printf("\nCannot inserted %d element", num);
            break;
        case '6':
            sort(stack);
            system("pause");
            break;
        case '7':
            key = 0;
            printf("\nEnter the integer to search: ");
            scanf("%d", &key);
            pos = search(stack, key);
            if (pos == -1)
                printf("\n%d not found in the stack\n", key);
            else
                printf("%d Found at location %d\n", key, pos);
            system("pause");
            break;
        case '0':
            free(stack);
            system("cls");
            exit(0);
        }
    }
    return 0;
}

// Check if stack is Empty
int isEmpty()
{
    return top == -1;
}

// Peek Operation
int peek(int *stack)
{
    if (isEmpty())
    {
        printf("\nStack is Empty");
        exit(4);
    }

    return stack[top];
}

// Pop Operation
int pop(int *stack)
{
    int n;
    if (isEmpty())
    {
        printf("\nStack is Empty");
        exit(3);
    }
    n = stack[top];
    top--;

    // Decrease size
    //size--;
    return n;
}

// Check if stack is Full
int isFull()
{
    return top == size;
}

// Push elem to the stack
void push(int *stack, int elem)
{
    // Check if stack is full
    if (isFull())
    {
        printf("\nStack is Full\n");
        exit(2);
    }
    // Increase the top by 1
    top++;
    // Insert elem into top location
    stack[top] = elem;
    printf("%d Inserted into the stack\n", elem);
}

// Traverse Operation
void traverse(int *stack)
{
    if (isEmpty())
    {
        printf("\nStack is Empty\n");
        exit(5);
    }

    printf("\nThe element of the stack\n");

    for (int i = 0; i <= top; i++)
        printf("stack[%d]= %d\t", i, stack[i]);
    printf("\n");
}

// Swap function
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// Sort function
void sort(int *stack)
{
    int swapped, tmp;

    while (1)
    {
        // swapped to keep track of the sorting process
        swapped = 0;

        // iterate from 0 to less than size - 1
        for (int i = 0; i < top; i++)
        {
            // if i'th value is greater than i + 1 'th  value
            if (*(stack + i) > *(stack + i + 1))
            {
                // swapped logic
                swap((stack + i), (stack + i + 1));
                swapped = 1;
            }
        }

        // If stack is sorted
        if (!swapped)
        {
            printf("\nThe Stack is sorted successfully\n");
            break;
        }
    }
}

// Search Function
int search(int *stack, int key)
{
    int low, upper, mid;

    low = 0;
    upper = size - 1;

    while (low <= upper)
    {
        // Get the middle
        mid = (low + upper) / 2;

        printf("\nmid = %d\n", mid);
        // Return mid if it is == key
        if (*(stack + mid) == key)
            return mid;
        // Mve upper to mid - 1 if condition met
        else if (*(stack + mid) > key)
            upper = mid - 1;
        // Move lower to mid + 1
        else
            low = mid + 1;
    }

    // If not found
    return -1;
}

void insert(int *stack, int n)
{

    int i, x, temp, c = 0;

    temp = size;

    // Add n to size
    size += n;

    // Resize the block of memory by size bytes
    stack = (int *)realloc(stack, size * sizeof(int));

    for (i = temp; i < size; i++)
    {
        printf("Enter integer %d to insert : ", c++);
        scanf("%d", &x);

        //*(stack + i) = x;
        push(stack, x);
    }
}