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
    int i, value, pos;

    // Create 3 nodes using loop
    for(i = 1; i <= 3; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data");
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

    // Insert new element
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter Position ");
    scanf("%d", &pos);

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(pos == 1)   // Insert at beginning
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        for(i = 1; i < pos - 1; i++)
            temp = temp->next;

        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next != NULL)
            temp->next->prev = newnode;
        
        temp->next = newnode;
    }

    // Display modified list only
    printf("Modified Data is :");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
