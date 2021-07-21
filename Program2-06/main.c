#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining what a 'node' is
struct node
{
    // satellite data
    int n;

    // pointer to next node
    struct node *next;
} typedef node;

node *createNode(int n);
node *insert (int n, node *prevPtr, node *headPtr);
void print(node *headPtr);
node *lookup(int n, node *headPtr);
node *delete (node *prevPtr, node *headPtr);

int main()
{
    int numElements = 0;
    printf("Enter number of elements: ");
    scanf("%d", &numElements);

    // if numElements is less than 1
    if (numElements < 1)
        return 0;

    int n = 0;

    printf("Enter element 1 (integer greater than 0): ");
    scanf("%d", &n);
    // Create first node of the list
    node *headPtr = createNode(n);

    // To keep track of where to append the nodes
    node *prevPtr = headPtr;

    for (int i = 0; i < numElements  - 1; i++)
    {
        printf("Enter element %d (integer greater than 0): ", i+2);
        scanf("%d", &n);

        headPtr = insert(n, prevPtr, headPtr);
        prevPtr = prevPtr->next;
    }
    print(headPtr);
    printf("\n");

    while (true)
    {
        printf("Enter 1 to print all elements\nEnter 2 to insert new element\nEnter 3 to delete an element\nEnter other integer to exit\n");
        int choice = 0;
        scanf("%d", &choice);

        if (choice == 1)
            print(headPtr);
        else if (choice == 2)
        {
            printf("Enter number you want to insert (integer greater than 0): ");
            scanf("%d", &n);
            printf("Enter after which element you want to insert (enter 0 to denote before the start): ");
            int prev = 0;
            scanf("%d", &prev);
            if (prev == 0)
                headPtr = insert(n, NULL, headPtr);
            else
            {
                prevPtr = lookup(prev, headPtr);
                if (prevPtr == NULL)
                    printf("not found in list\n");

                else {
                    prevPtr = lookup(prev, headPtr);
                    headPtr = insert(n, prevPtr, headPtr);
                }
            }
        }
        else if (choice == 3)
        {
            printf("Enter the element preceding the one you want to delete (enter 0 to delete the first element): ");
            scanf("%d", &n);
            if (n == 0)
                headPtr = delete (NULL, headPtr);
            else
            {
                prevPtr = lookup(n, headPtr);
                headPtr = delete(prevPtr, headPtr);
            }
        }
        else
            break;
    }

}

node *createNode(int n)
{
    // pointer to new node
    node *nptr = malloc(sizeof(node));

    // set value to n
    nptr->n = n;
    // default 'next' pointer to NULL
    nptr->next = NULL;

    return nptr;
}

// Insert function: takes in the number you want to insert, pointer to the previous node of where you want to insert it, and the pointer to the first node
// Returns a pointer to the first node (which can change if the node is inserted at the start). Function assumes first node if prevPtr is NULL
node *insert (int n, node *prevPtr, node *headPtr)
{
    // create node
    node *nptr = createNode(n);

    // to insert at the start of the list
    if (prevPtr == NULL)
    {
        nptr->next = headPtr;
        // you need to change the ptr to the first node
        return nptr;
    }

    // assign new node's next ptr
    nptr->next = prevPtr->next;

    // assign previous node's next ptr to the new node.
    prevPtr->next = nptr;

    return headPtr;
}

// Delete function: takes in the pointer to the previous node and the pointer to the head/first node
// Returns a pointer to the head (which can change if the head is deleted). Function assues first node if prevPtr is NULL
node *delete (node *prevPtr, node *headPtr)
{
    // if you want to delete the first element, pass in NULL
    if (prevPtr == NULL)
    {
        // second node will be the new head/first node
        node *newHeadPtr = headPtr->next;
        free(headPtr);
        return newHeadPtr;
    }
    // check if prevPtr is last element in the list. If so, exit this function by returning the headPtr
    if (prevPtr->next == NULL)
        return headPtr;

    // temporary variable
    node *temp = prevPtr->next->next;

    // delete the succeeding node
    free(prevPtr->next);

    // bridge the gap
    prevPtr->next = temp;
    return headPtr;

}

void print (node *headPtr)
{
    node *nptr = headPtr;
    // iterating over the linked list
    while (nptr != NULL)
    {
        printf("%d, ", nptr->n);
        nptr = nptr->next;
    }
    printf("\n");
}

// Lookup function: takes in a number n and the head ptr of a list and returns the location of the node storing n
// returns a pointer to the first node of the list or NULL if the number you want to delete doesn't exist
node *lookup(int n, node *headPtr)
{
    node *nptr = headPtr;
    while (nptr != NULL)
    {
        if (nptr->n == n)
            return nptr;
        nptr = nptr->next;

    }
    return NULL;
}

