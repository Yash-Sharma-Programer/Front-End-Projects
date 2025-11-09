#include <stdio.h>

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int low = 0, high = 4, mid, item;
    int flag = 0;

    printf("Enter searching item: ");
    scanf("%d", &item);

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == item)
        {
            flag = 1;
            break;
        }
        else if(item < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(flag == 1)
        printf("Item found at %d ",  mid);
    else
        printf("Item not found\n");

    return 0;
}
