
/*
 Date: 23/08/2020
 Program: Implement all the operations of Single Linked List
 Author: Malick Diakite
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *root = NULL;
int len = 0;

// function prototypes
void append(int);
void addAtBeguin();
void addAtEnd();
void addAtAfter();
int length();
void delete ();
void display();
void swap(node *a, node *b);
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
        printf("1.Append node(s)\n");
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

        switch (choice)
        {
        case '1':
            printf("\nEnter number of node(s) append: ");
            scanf("%d", &n);
            append(n);
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
            addAtAfter();
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
}

// Append function
void append(int n)
{
    for (int i = 0; i < n; i++)
    {
        node *tmp = (void *)malloc(sizeof(node));
        printf("Enter node{%d}: ", i + 1);
        scanf("%d", &tmp->data);
        tmp->link = NULL;

        if (root == NULL)
            root = tmp;
        else
        {
            node *p = root;

            while (p->link != NULL)
                p = p->link;
            p->link = tmp;
        }
    }
    printf("\nElement(s) added successfully\n\n");
}

// function to add node at the beguining
void addAtBeguin()
{
    node *tmp = (void *)malloc(sizeof(node));

    printf("\nEnter node to add at beguining: ");
    scanf("%d", &tmp->data);
    tmp->link = NULL;

    if (root == NULL)
        root = tmp;
    else
    {
        tmp->link = root;
        root = tmp;
    }
    printf("\nElement added successfully\n\n");
}

// fuction to add node at end

void addAtEnd()
{
    node *tmp = (void *)malloc(sizeof(node));
    printf("\nEnter node to add at End: ");
    scanf("%d", &tmp->data);
    tmp->link = NULL;

    if (root = NULL)
        root = tmp;
    else
    {
        node *p = root;
        while (p->link != NULL)
            p = p->link;
        p->link = tmp;
    }
    printf("\nElement added successfully\n\n");
}

// Fuction find length of the linked list
int length()
{
    node *tmp = root;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->link;
    }

    return cnt;
}

// Function to add after a node specified location
void addAtAfter()
{
    int loc, cnt = 1;

    node *tmp, *p;

    len = length();

    printf("\nEnter location to add: ");
    scanf("%d", &loc);

    if (loc > len)
        printf("\nInvalid input! currently list has %d node(s)\n\n", len);
    else
    {
        p = root;

        while (loc > cnt)
        {
            cnt++;
            p = p->link;
        }
        tmp = (void *)malloc(sizeof(node));
        printf("\nEnter the node to add at specified location: ");
        scanf("%d", &tmp->data);
        tmp->link = NULL;

        tmp->link = p->link;
        p->link = tmp;
    }
    printf("\nElement added successfully\n\n");
}

// Function to delete a node at a specified location
void delete ()
{
    node *tmp, *q;

    int loc, len, count = 1;

    printf("Enter location to delete: ");
    scanf("%d", &loc);

    len = length();

    if (loc > len)
        printf("\nInvalid input! currently list has %d noes(s)\n\n", len);
    else if (loc == 1)
    {
        tmp = root;
        root = tmp->link;
        tmp->link = NULL;

        free(tmp); // Vacate memory
    }
    else
    {
        tmp = root;
        while (count < (loc - 1))
        {
            tmp = tmp->link;
            count++;
        }
        q = tmp->link;
        tmp->link = q->link;
        q->link = NULL;

        free(q); // Vacate the memory
    }

    printf("\nElement delete successfully\n\n");
}

// Function to display all the node(s)
void display()
{
    node *tmp = root;

    if (tmp == NULL)
        printf("\nList is Empty\n\n");
    printf("\n");
    while (tmp != NULL)
    {
        printf("%d-->", tmp->data);
        tmp = tmp->link;
    }
    printf("NULL\n");
}

// function to swapped the linked list
void swap(node *a, node *b)
{
    int t = a->data;
    a->data = b->data;
    b->data = t;
}

// Function to sort the linked list
void sortLinkedList()
{
    node *ptr;
    node *lptr = NULL;
    int swapped;

    if (root == NULL)
        printf("\nThe list is Empty\n\n");

    while (1)
    {
        swapped = 0;

        ptr = root;

        while (ptr->link != lptr)
        {
            if (ptr->data > ptr->link->data)
            {
                swap(ptr, ptr->link);
                swapped = 1;
            }
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