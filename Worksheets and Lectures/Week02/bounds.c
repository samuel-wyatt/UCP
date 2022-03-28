#include <stdio.h>
#include "macros.h"
#define BETWEEN(a, b, c)  (((a) > (b)) && ((a) < (c)))

int checkInt(int low, int high, int val);
int checkDbl(double low, double high, double val);
int checkChar(char low, char high, char val);

int main(void)
{
    int lowInt, highInt, valInt, intBool, menu;
    double lowDbl, highDbl, valDbl;
    char lowChar, highChar, valChar;
    
    printf("1. Integer\n2. Double\n3. Character\nSelection:\t");
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
    }
}

int checkInt(int low, int high, int val)
{
    int bool = BETWEEN(high, low, val);
    return bool;
}

int checkDbl(double low, double high, double val)
{
    int bool = BETWEEN(high, low, val);
    return bool;
}

int checkChar(char low, char high, char val)
{
    int bool = BETWEEN(high, low, val);
    return bool;
}
