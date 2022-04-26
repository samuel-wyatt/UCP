#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plot.h"
int main(int args, char **argv) {
    FILE *fPtr;
    double **array, input;
    int row, cols, i, j;
    char *fileName;
    if (args < 2) {
        printf("USAGE: ./display <fileName>\n");

    } else {
        fileName = argv[1];
        if (strcmp(fileName, "-") != 0) {
            if ((fPtr = fopen(fileName, "r")) == NULL) {
                printf("Unable to open file \"%s\"\n", argv[1]);
                return 1;
            }
        
            fscanf(fPtr, "%d %d", &row, &cols);
            
            array = malloc(row * sizeof(double*));
            for (i = 0; i < row; i++) {
                array[i] = malloc(cols * sizeof(double));
            }

            if (array == NULL) {
                printf("Failed to allocate array\n");

            } else {
                for (i = 0; i < row; i++) {
                    for (j = 0; j < cols; j++) {
                        fscanf(fPtr, "%lf ", &input);
                        array[i][j] = input;
                    }
                }
                plot(array, row, cols);
            }
        fclose(fPtr);
        } else {

            fscanf(fPtr, "%d %d", &row, &cols);
            array = malloc(row * sizeof(double*));

            for (i = 0; i < cols; i++) {
                array[i] = malloc(cols * sizeof(double));
            }

            if (array == NULL) {
                printf("Failed to allocate array\n");

            } else {

            for (i = 0; i < row; i++) {
                for (j = 0; j < cols; j++) {
                    fscanf(stdin, "%lf", &input);
                    array[i][j] = input;
                }
            }
            plot(array, row, cols);
            }
        }
        fPtr = NULL;
        for (i = 0; i < row; i++) {
            free(array[i]);
        }
        free(array);
        array = NULL;
    }
    return 0;
}
