#include <stdio.h>
#include "macros.h"
#include "powers.h"

int checkInt(int low, int high, int val);
int checkDbl(double low, double high, double val);
int checkChar(char low, char high, char val);
int power(int val);

int main(void)
{
    int lowInt, highInt, valInt, intBool, menu, answer;
    double lowDbl, highDbl, valDbl;
    char lowChar, highChar, valChar;
    
    printf("1. Integer\n2. Double\n3. Character\n4. Powers\nSelection:\t");
    scanf("%d", &menu);

    switch (menu)
    {
        case 1:
        /* Integer value entering and testing */
        printf("-----INTEGERS-----\n");
        printf("Please enter the lower bound:\t");
        scanf("%d", &lowInt);

        printf("\nPlease enter the upper bound:\t");
        scanf("%d", &highInt);

        printf("\nPlease enter the value to be checked:\t");
        scanf("%d", &valInt);

        intBool = checkInt(lowInt, highInt, valInt);
        printf("\n1 = True\n0 = False\ncheckInt is: %d\n", intBool);
        break;

        case 2:
        /* Double value entering and testing */
        printf("-----DOUBLE-----\n");
        printf("Please enter the lower bound:\t");
        scanf("%lf", &lowDbl);

        printf("\nPlease enter the upper bound:\t");
        scanf("%lf", &highDbl);

        printf("\nPlease enter the value to be checked:\t");
        scanf("%lf", &valDbl);

        intBool = checkDbl(lowDbl, highDbl, valDbl);
        printf("\n1 = True\n0 = False\ncheckDbl is: %d\n", intBool);
        break;

        case 3:
        /* Character value entering and testing */
        printf("-----Character-----\n");
        printf("Please enter the lower bound:\t");
        scanf(" %c", &lowChar);

        printf("\nPlease enter the upper bound:\t");
        scanf(" %c", &highChar);

        printf("\nPlease enter the value to be checked:\t");
        scanf(" %c", &valChar);

        intBool = checkChar(lowChar, highChar, valChar);
        printf("\n1 = True\n0 = False\ncheckChar is: %d\n", intBool);
        break;

        case 4:
        /* Value entering. */
        printf("------Powers-----\n");
        printf("Please enter the number between 1 and 31: ");
        scanf("%d", &valInt);
        answer = power(valInt);
        printf("The powers of 2 up to %d is %d\n", valInt,answer);
    }
}

int checkInt(int low, int high, int val)
{
    int bool = BETWEEN(low, high, val);
    return bool;
}

int checkDbl(double low, double high, double val)
{
    int bool = BETWEEN(low, high, val);
    return bool;
}

int checkChar(char low, char high, char val)
{
    int bool = BETWEEN(low, high, val);
    return bool;
}

int power(int val)
{
    int power = 0;
    if (BETWEEN(1, 31, val) == TRUE) {
        int i;
        for (i = 0; i < val; i ++) {
            power = powers();
        }
    } else {
        printf("Invalid Input: Integer was not between 1 and 31.");
    }
    return power;
}
