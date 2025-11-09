#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("%d pushed to stack\n", x);
}

void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is: %d\n", top->data);
    }
}

void display()
{
    struct node *temp = top;

    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
  push(2);
  push(3);
  push(11);
  display();
  peek();
  pop();
  peek();
  display();

    return 0;
}
