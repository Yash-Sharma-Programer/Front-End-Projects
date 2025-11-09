#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int i;

    // Input 3 nodes using loop
    for(i = 1; i <= 3; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
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

    // Making the list circular
    temp->next = head;

    // Display circular linked list

    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}
