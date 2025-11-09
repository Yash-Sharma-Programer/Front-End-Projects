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
    int i, pos;

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

    // Delete node
    printf("Enter Position:");
    scanf("%d", &pos);

    temp = head;

    if(pos == 1)   // Delete first node
    {
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else
    {
        for(i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }

    // Display modified list only
    printf("Modified Data ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
