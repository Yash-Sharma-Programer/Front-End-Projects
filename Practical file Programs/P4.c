#include <stdio.h>

int main()
{
    int i, item, flag = 0;
  int  a[5] = {10 , 20 , 30 , 40 , 50};
  printf("Enter Searching item :");
  scanf("%d" , &item);

    for(i = 0; i < 5; i++)
    {
        if(a[i] == item)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        
        printf("Element %d found at position %d\n", item, i + 1);
    }
    else{
            printf("Element not found\n");
        }
    return 0;
}
