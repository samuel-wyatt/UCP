#include <stdio.h>
#include <string.h>
#include "question2.h"
#define MAXLENGTH 10

int main(int args, char* argv[]) {

    int i, count = 0, length;
    int array[MAXLENGTH];
    char *argument = argv[1];

    if (args < 3) {
        printf("ERROR: No/not enough argument(s) were provided.\n");

    } else {
        do {

            for (i = 0; i < args; i++) {
            argv[i] = argv[i + 1];
            }
            count += 1;
        } while (count != 2);
        length = args - 2;

        strToInt(argv, array, length);

        if (strcmp(argument, "sum") == 0) {
            printf("%d\n", sum(array, length));

        } else if (strcmp(argument, "max") == 0) {
            printf("%d\n", max(array, length));

        } else if (strcmp(argument, "reverse") == 0) {
            reverse(array, length);
            printArr(array, length);

        } else {
            printf("Invalid argument.\n");
        }    
    }
    return 1;
}
