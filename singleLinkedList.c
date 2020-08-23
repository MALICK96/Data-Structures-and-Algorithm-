/*
 Date: 15/08/2020
 Program: Implementation of Single Linked List (self referencial data structure)
 Author: Malick Diakite  
*/

#include <stdio.h>
#include <stdlib.h>

// Linked list
typedef struct node
{
    int data;
    struct node *link;
} node;

// Head of the linked list
node *root = NULL;

// Function prototypes
node *createLinkedList(int n);
int length();
void display();
void insertAtBeguin();

int main()
{
    int n;
    printf("How many node to create: ");
    scanf("%d", &n);

    root = createLinkedList(n);

    // Display the linked list
    display();

    // Print the number of node in the List
    printf("\nLinked list Length = %d\n", length());

    // Add a node at beguining
    insertAtBeguin();

    // Display the Linked list
    display();

    return 0;
}

// Create individual node
node *createLinkedList(int n)
{
    // Need node pointers variables
    node *root = NULL;
    node *temp = NULL;
    node *p = NULL;

    // Create n node
    for (int i = 0; i < n; i++)
    {
        // Allocate space for each i'th node
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Out of memory error\n");
            exit(1);
        }
        // read the i'th node in the data field
        printf("Enter node{%d}: ", i + 1);
        scanf("%d", &temp->data);

        // set the i'th node link field to null
        temp->link = NULL;

        // If there is no node yet
        if (root == NULL)
        {
            // Set root to point the temp as first node
            root = temp;
        }
        else
        {
            // Otherwise get the root address in p
            p = root;

            // Iterate as long as p link field is not NULL
            while (p->link != NULL)
            {
                // Set p to point p link field
                p = p->link;
            }
            // Set p to point to the newly created node
            p->link = temp;
        }
    }

    // Display the success message and return root
    printf("\nList Creation successful\n");
    return root;
}

// Display the Linked List node(s)
void display()
{
    // Get the root address into t
    node *t = root;

    // As long as t is not NULL
    while (t != NULL)
    {
        printf("%d ->\t", t->data);
        // Set t to point to next node
        t = t->link;
    }
    printf("NULL\n");
}

// Function to compute length of the Linked List
int length()
{
    node *t = root;
    int len = 0; // counter variable

    // As long as t is in end of Linked List
    while (t != NULL)
    {
        // increment len by 1
        len++;
        t = t->link; // Set t to point to the next node
    }

    // return length
    return len;
}

// Insert node at the start
void insertAtBeguin()
{
    // Allocate space for the node to be insert
    node *temp = (void *)malloc(sizeof(node));

    // Check if memory allocation failed
    if (temp == NULL)
    {
        printf("\nOut of memory");
        exit(2);
    }

    // Read data into node temp (data field)
    printf("\nEnter new node to insert: ");
    scanf("%d", &temp->data);

    // set the temp link to point first node
    temp->link = NULL;

    // If root is empty
    if (root == NULL)
        // Set root to the newly created node
        root = temp;
    else
    {
        // Otherwise assign to temp link field the root address
        temp->link = root; // right side connection
        // assign temp address to root
        root = temp; // left side connection
    }
    // Success message
    printf("\nInsertion successful\n");
}