/* 
    This program read the data saved in  the record.bin 
    file that was created by the stack.c rogram
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("record.bin", "rb");

    if (fp == 0)
    {
        printf("Cannot open the file\n");
        exit(1);
    }

    long size = ftell(fp);
    printf("size = %ld\n", size);

    // Find  out the number of record in the file
    fseek(fp, 0L, 2);
    size = ftell(fp);
    int n = size / sizeof(int);

    // Allocate space for the record
    int *stack = calloc(n, sizeof(int));

    // Move the pointer at the start of the file
    rewind(fp);
    // read the record from the file into the stack
    fread((void *)stack, sizeof(int), n, fp);

    // Print out the content of the stack
    for (int i = 0; i < n; i++)
        printf("stack[%d] = %d\t", i, *(stack + i));

    fclose(fp);
    return 0;
}