#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void usage();

int main(int args, char* argv[]) {

    int i, count = 0; 
    int length = atoi(argv[2]);
    char *argument = argv[1];
    int *array = (int*)malloc(length*sizeof(1));

    do {
        for (i = 0; i < args; i++) {
        argv[i] = argv[i + 1];
        }
        count += 1;
    } while (count != 3);

    if (args < 4) {
        usage();
    } else {
        strToInt(argv, array, length);
        lowerUpper(argument);

        if (strcmp(argument, "SUM") == 0) {
            printf("Sum = %d\n", sum(array, length));

        } else if (strcmp(argument, "MAX") == 0) {
            printf("Index of largest element = %d\n", max(array, length));

        } else if (strcmp(argument, "REVERSE") == 0) {
            reverse(array, length);
            printArr(array, length);

        } else {
            printf("Invalid argument(s).\n");
        }    
    }
    free(array);
    return 1;
}

void usage() {
    printf("USAGE: ./program <function name> <length of array> n n1 n2 n3 n4 n5 n6 ...");
    printf("\n\t--n being the integers to use, seperated by spaces.\n");
}
