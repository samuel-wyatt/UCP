#include <stdio.h>

int factorial(int n);

int main()
{
    int userIn, total;
    do 
    {
        printf("\nEnter an integer: ");
        scanf("%d", &userIn);
        if (userIn > 0)
        {
            total = factorial(userIn);
            printf("The total is: %d", total);
        }
    } while (userIn > 0);
    
    return 0;
}


int factorial(int n)
{
    int total = n; 
    int i = n - 1;
    for (i = n - 1; i > 0; i--)
    {
        total = total * i;
    }
    return total;
}
