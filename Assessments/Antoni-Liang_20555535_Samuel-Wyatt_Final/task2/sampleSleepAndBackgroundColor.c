#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> /* this is the library to use sleep() function */

/*
In this example, you will see a demonstration on how to use sleep() function
to halt the program by some amount of seconds, and also a way manipulate background color.
*/

/*
The provided example to change background color should be sufficient to assist the final assessment.
However, if you need more explanation, please google "Ansi color in C" (the first 2 links should suffice).
*/

int main()
{
    int amount = 10;
    int i;

    /* I will loop 10 times, and for each iteration, the program will sleep for 1 second and print the number with alternating background color */

    for(i = 1 ; i <= amount ; i++)
    {
        system("clear"); /* clearing terminal screen */

        if( i%2 == 0)
        {
            printf("\033[0;100m"); /* toggle DARK/BLACK background color if i is even number */
        }
        else
        {
            printf("\033[0;107m"); /* toggle BRIGHT/WHITE background color if i is odd number */
        }

        printf("%d", i); /* this number will have various background color */

        printf("\033[0m"); /* this toggle the RESET functionality. This will revert back to default state (which is no background color)
                              If you forgot to RESET, the effect of background color change will affect the whole terminal. */

        printf("\n"); /* the reason I print a new line here is because I need to RESET before printing new line.
                         Otherwise, the background color change might affect more area than intended. */

        sleep(1); /* program sleep for 1 second. Keep in mind that sleep function only accepts integer.
                     So, something like 0.5 second sleep cannot be done with sleep() function. */


    }

    return 0;
}