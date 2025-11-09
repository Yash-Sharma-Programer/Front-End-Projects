#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int i;

    // Taking input using loop (3 nodes)
    for(i = 1; i <= 3; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Reverse doubly linked list (without function)
    struct node *current = head, *nextnode;
    while(current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }

    // Move head to new start (last node becomes first)
    while(head->prev != NULL)
        head = head->prev;

    // Print modified/reversed list only
    printf("\nModified data is : ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
