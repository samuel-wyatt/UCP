#include <stdio.h>

void factorial(int n);

int main(void)
{
    int userIn;
    do 
    {
        printf("\nEnter an integer: ");
        scanf("%d", &userIn);
        if (userIn > 0)
        {
            factorial(userIn);
        }
    } while (userIn > 0);
}

void factorial(int n)
{
    int total = n; 
    int i = n - 1;
    for (i = n - 1; i > 0; i--)
    {
        total = total * i;
    }
    printf("The total is: %d", total);
}
