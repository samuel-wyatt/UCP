#include <stdio.h>

int powers(void);

int main(void)
{
    int i, answer;
    for (i = 0; i < 8; i++)
    {
        answer = powers();
        printf("%d\n", answer);
    }
    return 0;
}

int powers(void)
{
     static int answer = 1;
     answer = answer * 2;
     return answer;
}
