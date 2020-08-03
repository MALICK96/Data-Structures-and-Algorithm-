/*
  Date: 03/08/2020
  Program: Search a Name in list of stored names
  Author: Malick Diakite
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void sortNames(char *names[]);
void searchName(char *names[], char *name);
void displayNames(char *names[]);

int main(void)
{
    char *names[SIZE], *ptr, str[30];
    char name[30];
    int i;

    // Prompt the User for Names
    printf("Enter Name 5 Names one at a time\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter Name[%d]: ", i);
        fgets(str, 29, stdin);
        // Allocate memory of str length + 1  for the '\0'
        ptr = (char *)malloc(sizeof(strlen(str)) + 1);
        if (ptr == NULL)
        {
            printf("Cannot Allocate the memory\n");
            exit(1);
        }
        strcpy(ptr, str); // copy the str in ptr
        names[i] = ptr;   // assign ptr in the names array
    }

    // Sort the Names
    sortNames(names);
    // Display ALL Names
    displayNames(names);

    // Prompt For Name to be Searched
    printf("Enter Name to be Searched: ");
    fgets(name, 29, stdin);

    // Search Function
    searchName(names, name);

    return 0;
}

void sortNames(char *names[])
{

    int i, j;
    char *t;

    // Go through the names array
    for (i = 0; i < SIZE; i++)
    {

        for (j = i + 1; j < SIZE; j++)
        {
            /* check if the order of the string poiter 
    in the names array and sort them 
    aphabetically if not sorted
    */
            if (strcmp(names[i], names[j]) > 0)
            {
                t = names[i];
                names[i] = names[j];
                names[j] = t;
            }
        }
    }
}

void displayNames(char *names[])
{
    int i;

    printf("\n\nList Of Names\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("names[%d]: %s\n", i, names[i]);
    }
}

void searchName(char *names[], char *name)
{
    int i;

    /* Go through the names pointer to string array
    check if the i'th names is eqaul to name
  */
    for (i = 0; i < SIZE; i++)
    {
        if (!strcmp(names[i], name))
        {
            printf("Name %s found at index: %d\n", names[i], i);
            exit(0);
        }
    }
    // If name not found in the array
    printf("Name %s Not found\n", names[i]);
    exit(1);
}
