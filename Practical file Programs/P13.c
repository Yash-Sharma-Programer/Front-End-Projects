#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int i, value, pos;

    // Create 3 nodes using loop
    for(i = 1; i <= 3; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Display original list
    printf("Original data:");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Insert new element at any position
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\n\nEnter value to insert: ");
    scanf("%d", &value);
    printf("Enter position (1-4): ");
    scanf("%d", &pos);

    newnode->data = value;

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Display modified list
    printf("Modified Linked data:");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
