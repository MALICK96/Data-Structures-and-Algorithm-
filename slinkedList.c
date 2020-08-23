/*
 Date: 18/07/2020
 Program: Implement all the operations of Single Linked List
 Author: Malick Diakite
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *link;
} node;
node *root = NULL;
int len;
node *createLinkedList(int n);
void display();
void addAtBeguin();
void addAtEnd();
void addAtafter();
int length();
void delete ();
void swap(node *a, node *b);
// void interchange(node *x, node *y);
void sortLinkedList();

void gotoxy(short int col, short int row);

int main()
{
    char choice;
    int n;
    while (1)
    {
        system("cls");
        // Menu of the Program
        gotoxy(30, 8);
        printf("1.Create Node List\n");
        gotoxy(30, 10);
        printf("2.Insert Node at the start of the List\n");
        gotoxy(30, 12);
        printf("3.Insert Node at the end of the List\n");
        gotoxy(30, 14);
        printf("4.Find Length of the Node(s) List\n");
        gotoxy(30, 16);
        printf("5.Display the node(s) in the List\n");
        gotoxy(30, 18);
        printf("6. Delete a node at specied location\n");
        gotoxy(30, 20);
        printf("7.Add the node after a specified node\n");
        gotoxy(30, 22);
        printf("8.Sort The Node List\n");
        gotoxy(30, 24);
        printf("0.Exit the program");
        gotoxy(30, 26);

        // Read user choice
        printf("What's your choice: ");
        fflush(stdin);
        choice = getche();

        // Trigger the approce call code based on the choice value
        switch (choice)
        {
        case '1':
            printf("\nEnter number of node to create: ");
            scanf("%d", &n);
            root = createLinkedList(n);
            break;

        case '2':
            addAtBeguin();
            system("pause");
            break;

        case '3':
            addAtEnd();
            system("pause");
            break;
        case '4':
            len = length();
            printf("\nLength of the Linked list = %d\n", len);
            system("pause");
            break;
        case '5':
            display();
            system("pause");
            break;
        case '6':
            delete ();
            system("pause");
            break;
        case '7':
            addAtafter();
            system("pause");
            break;
        case '8':
            sortLinkedList();
            system("pause");
            break;
        case '0':
            system("cls");
            exit(0);
        }
    }
    return 0;
}

// Fuction to inset a node at the start of the linked list
void addAtBeguin()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nOut of memory error");
        exit(2);
    }
    printf("\nEnter the node to add: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        temp->link = root; // right connection
        root = temp;       // left connection
    }

    printf("\nInsertion successfull\n");
}

// Fuction to insert node at end
void addAtEnd()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nOut of memory error");
        exit(3);
    }

    printf("\nEnter node to insert: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        node *p;
        p = root;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

// Fuction to find the length of the list
int length()
{
    int count = 0;
    node *temp = root;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

// Add node at a particular location
void addAtafter()
{
    node *temp, *p;
    int loc, len;

    // count num of node
    int i = 1;

    len = length();
    printf("\nEnter location: ");
    scanf("%d", &loc);

    if (loc > len)
    {
        printf("\nInvalid location\n");
        printf("Currently there are %d nodes in the list\n", len);
    }
    else
    {
        p = root;

        while (i < loc)
        {
            p = p->link;
            i++;
        }
        // Creation the node to insert
        temp = (void *)malloc(sizeof(node));
        printf("Enter the node: ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        temp->link = p->link; // right connection
        p->link = temp;       // right side connection
        printf("\nnode added successfully\n ");
    }
}

// Delete a node at specific location
void delete ()
{
    node *temp;
    int loc, len;

    printf("\nEnter location to delete: ");
    scanf("%d", &loc);

    len = length();
    if (loc > len)
    {
        printf("\nInvalid input list is having %d node(s)\n", len);
        exit(1);
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link; // Point the next node
        temp->link = NULL; // set the link part of temp to NULL

        free(temp); // Vacate memory
    }
    else
    {
        node *q;
        temp = root;

        //count number of node
        int count = 1;

        while (count < loc - 1)
        {
            temp = temp->link;
            count++;
        }
        q = temp->link;
        temp->link = q->link;
        q->link = NULL;

        free(q);
    }
    printf("\nNode deleted sucessfully\n");
}
// Fuction to display the linked list
void display()
{
    node *temp = root;

    printf("\nThe node(s) of the linked list\n");

    if (temp == NULL)
        printf("No node in the list\n");
    else

        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->link;
        }
    printf("NULL\n\n");
}

// Fuction append node(s) to linked list
node *createLinkedList(int n)
{
    node *root = NULL;
    node *temp = NULL;
    node *p = NULL;

    for (int i = 0; i < n; i++)
    {
        temp = (void *)malloc(sizeof(node));

        if (temp == NULL)
        {
            printf("\nOut of memory error");
            exit(0);
        }
        printf("Enter node{%d}: ", i);
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (root == NULL)
            root = temp;
        else
        {
            p = root;

            while (p->link != NULL)
            {
                p = p->link;
            }
            p->link = temp;
        }
    }

    return root;
}

/* function to swap data of two nodes a and b*/
void swap(node *a, node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Fuction to sort the linked list
void sortLinkedList()
{

    node *ptr;
    node *lptr = NULL;
    int swapped = 0;

    if (root == NULL)
        return;

    while (1)
    {
        swapped = 0;
        ptr = root;

        while (ptr->link != lptr)
        {
            if (ptr->data > ptr->link->data)
            {
                // swap the 2 node
                swap(ptr, ptr->link);
                swapped = 1;
            }
            ptr = ptr->link;
        }
        lptr = ptr;

        if (!swapped)
            break;
    }
    printf("\nLinked list sorted successfuly\n");
}

void gotoxy(short int col, short int row)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(hStdout, position);
}