#include <stdio.h>

int main(void)
{
        int intOne, intTwo, answer;
        printf("Integer One: \t");
        scanf("%d", &intOne);

        printf("\nInteger Two: \t");
        scanf("%d", &intTwo);

        answer = intOne % intTwo;

        if (answer != 0)
        {
            printf("Not Divisible\n");
        } else {
            printf("Divisible\n");
        }
    return 0;
}
