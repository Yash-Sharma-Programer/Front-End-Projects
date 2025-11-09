#include <stdio.h>

int main() 
{
    int n = 5, loc = 2, item = 70;
    int a[10];
    int i;

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Check overflow
    if(n == 10)
    {
        printf("Overflow");
    }
    else
    {
        // Check valid location
        if(loc < 0 || loc > n)
        {
            printf("Invalid location");
        }
        else
        {
            // Shift elements
            for(i = n - 1; i >= loc; i--)
            {
                a[i + 1] = a[i];
            }

            a[loc] = item; // Insert item
            n++;

            printf("Array after insertion:\n");
            for(i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
        }
    }

    return 0;
}
