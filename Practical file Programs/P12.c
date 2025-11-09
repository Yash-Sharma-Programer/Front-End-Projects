#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int item)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = item;
        printf("%d item inserted", item);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("item deleted %d", stack[top]);
        top--;
    }
}

void dispaly(){
    if(top == -1)
    {
        printf("The stack is empty");
    }

    else{
        printf("stack element");
        for(int i = 0 ; i <= top ; i++){
            printf("%d", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    display();
    return 0;
}
