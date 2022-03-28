#include <stdio.h>

int main(void)
{
    int a = 2;
    int *x;
    x = &a;
    int **s;
    s = &x;

    printf("&p", &s);
    
    return 0;

}