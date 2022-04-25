#include <stdio.h>
#include <stdlib.h>
#include "plot.h"
int main(int args, char **argv) {
    FILE *fPtr;
    double **array, input;
    int row, col, i, j;
    if (args < 2) {
        printf("USAGE: ./display <fileName>\n");

    } else if ((fPtr = fopen(argv[1], "r")) == NULL) { 
        printf("Unable to open file \"%s\"\n", argv[1]);

    } else {
        fscanf(fPtr, "%d %d", &row, &col);
        array = malloc(row * sizeof(double*));

        for (i = 0; i < col; i++) {
            array[i] = malloc(col * sizeof(double));
        }

        if (array == NULL) {
            printf("Failed to allocate array\n");

        } else {

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                fscanf(fPtr, "%lf ", &input);
                array[i][j] = input;
            }
        }
        plot(array, row, col);
        }
    fclose(fPtr);
    fPtr = NULL;

    for (i = 0; i < row; i++) {
        free(array[i]);
    }
    free(array);
    array = NULL;
    }
}
