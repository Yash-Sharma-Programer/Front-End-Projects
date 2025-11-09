#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode, *prev;
    int i, pos;

    // Create 3 nodes using loop
    for(i = 1; i <= 3; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data");
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

    // Delete node
    printf("\nEnter Pos: ");
    scanf("%d", &pos);

    temp = head;

    if(pos == 1)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        for(i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

    // Display modified list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
