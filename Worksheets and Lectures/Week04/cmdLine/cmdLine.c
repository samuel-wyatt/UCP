#include <stdio.h>
#include <string.h>
#include "question2.h"
#define MAXLENGTH 10

int main(int args, char* argv[]) {

    int i, count = 0, length;
    int array[MAXLENGTH];
    char *argument = argv[1];

    if (args < 3) {
        printf("ERROR: No/not enough argument(s) were provided.");

    } else {
        do {

            for (i = 0; i < args; i++) {
            argv[i] = argv[i + 1];
            }
            count += 1;
        } while (count != 2);
        length = args - 2;
        printf("%d\n", length);

        strToInt(argv, array, length);

        if (strcmp(argument, "sum") == 0) {
            printf("%d\n", sum(array, MAXLENGTH));

        } else if (strcmp(argument, "max") == 0) {
            printf("%d\n", max(array, MAXLENGTH));

        } else if (strcmp(argument, "reverse") == 0) {
            reverse(array, MAXLENGTH);
            printArr(array, MAXLENGTH);

        } else {
            printf("Invlaid argument.");
        }    
    }
}
