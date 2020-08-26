/*
 Date: 18/07/2020
 Program: Implement all the operations of Single Linked List
 Author: Malick Diakite
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *root = NULL;
int len;

void append();
void addAtStart();
void addAtEnd();
void addAtAfter();
void deleteNode();
int length();
void display();
void search();
void sortList();
void swap(node *, node *);

void gotoxy(short int col, short int row);

int main(void)
{

    char choice;

    while (1)
    {
        system("cls");

        gotoxy(30, 8);
        printf("1.Append a node\n");
        gotoxy(30, 10);
        printf("2.Insert node at Start\n");
        gotoxy(30, 12);
        printf("3.Insert node at End\n");
        gotoxy(30, 14);
        printf("4.Insert a node after a specified node\n");
        gotoxy(30, 16);
        printf("5.Delete a node at specified location\n");
        gotoxy(30, 18);
        printf("6.Display node\n");
        gotoxy(30, 20);
        printf("7.Find length\n");
        gotoxy(30, 22);
        printf("8.Search for a node\n");
        gotoxy(30, 24);
        printf("9.Sort the linked list\n");
        gotoxy(30, 26);
        printf("0.Exit\n");
        gotoxy(30, 28);

        printf("Enter your choice: ");
        choice = getchar();

        switch (choice)
        {
        case '1':
            append();
            system("pause");
            break;
        case '2':
            addAtStart();
            system("pause");
            break;
        case '3':
            addAtEnd();
            system("pause");
            break;
        case '4':
            addAtAfter();
            system("pause");
            break;
        case '5':
            deleteNode();
            system("pause");
            break;
        case '6':
            display();
            system("pause");
            break;
        case '7':
            len = length();
            printf("\nLength of the Linked list = %d\n", len);
            system("pause");
            break;
        case '8':
            search();
            system("pause");
            break;
        case '9':
            sortList();
            system("pause");
            break;
        case '0':
            system("cls");
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

void append()
{
    int n;
    node *temp, *p;

    printf("\nEnter number of node to Insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter node{%d}: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (root == NULL)
            root = temp;
        else
        {
            p = root;

            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    printf("\n%d items Appended successfull\n", n);
}

void addAtStart()
{
    node *temp = (node *)malloc(sizeof(node));

    printf("\nEnter node to add: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        temp->link = root;
        root = temp;
    }
    printf("\nInsertion successfull\n");
}

void addAtEnd()
{
    int n;
    node *temp, *p;

    printf("Enter number of node(s) to add:  ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter node {%d}: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (root == NULL)
            root = temp;
        else
        {
            p = root;

            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
}

int length()
{
    int c = 0;
    node *temp = root;

    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }

    return c;
}

void addAtAfter()
{
    node *temp, *p;
    int loc, i = 1;

    len = length();

    printf("Enter location to insert: ");
    scanf("%d", &loc);

    if (loc > len)
    {
        printf("\nInvalid input! currently list is having %d node(s\n", len);
    }
    else
    {
        // Move to location
        p = root;

        while (i < loc)
        {
            i++;
            p = p->link;
        }
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter node to insert: ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        temp->link = p->link;
        p->link = temp;
    }
    printf("\nNode insertion successfull\n");
}

void deleteNode()
{
    node *temp;
    int loc;

    len = length();

    printf("Enter location to insert: ");
    scanf("%d", &loc);

    if (loc > len)
        printf("\nInvalid input! currently list is having %d node(s\n", len);
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;

        free(temp);
    }
    else
    {
        node *q;
        int i = 1;

        temp = root;

        while (i < (loc - 1))
        {
            i++;
            temp = temp->link;
        }
        q = temp->link;
        temp->link = q->link;
        q->link = NULL;

        free(q);
    }
    printf("\nNode deleted sucessfully\n");
}

void display()
{
    node *temp = root;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void search()
{
    int n, flag = 0, i = 1;
    node *temp = root;

    printf("Enter node to search: ");
    scanf("%d", &n);

    len = length();

    while (i <= len)
    {

        if (temp->data == n)
        {
            printf("\n%d found at location %d\n", n, i);
            flag = 1;
            break;
        }
        i++;
        temp = temp->link;
    }

    if (!flag)
        printf("\n%d not found at any location\n", n);
}

void swap(node *x, node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void sortList()
{
    node *ptr, *lptr;

    lptr = NULL;

    int swapped;

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
                swap(ptr, ptr->link);
                swapped = 1;
            }
            ptr = ptr->link;
        }

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