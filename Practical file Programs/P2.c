#include <stdio.h>

int main() 
{
    int n = 5, loc = 2, item = 70;
    int a[n];
    for(int i = 0 ; i < n - 1; i++)
    {
        scanf("%d" , &a[i]);
    }
    for(int i = loc - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d " , a[i]);
    }
    return 0 ;
}