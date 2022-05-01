#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomarray.h"
int main(int argc, char **argv) {
    FILE *fPtr;
    int rows, cols, i, j;
    double **array;
    char *fileName;

    fileName = argv[1];
    rows = atoi(argv[2]);
    cols = atoi(argv[3]);

    if (argc < 4) {
        printf("Usage : ./generate <filename> <rows> <columns>\n");
        
    } else {
        if (strcmp(fileName, "-") != 0) {
            if ((fPtr = fopen(fileName, "w")) == NULL) {
                printf("Error : Could not open file. Aborting\n");
                return 1;
            }

            array = (double**)malloc(rows * sizeof(double*));
            for (i = 0; i < rows; i++) {
                array[i] = (double*)malloc(cols * sizeof(double));
            }
            if (array == NULL) {
                printf("Failed to allocate array. Aborting\n");
                return 1;
            }
        
            randomArray(array, rows, cols, 0);
            
            fprintf(fPtr, "%d %d\n", rows, cols);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    fprintf(fPtr, "%f ", array[i][j]);
                }
                    fprintf(fPtr, "\n");
            }

            fclose(fPtr);
        } else {
            array = (double**)malloc(rows * sizeof(double*));
            for (i = 0; i < rows; i++) {
                array[i] = (double*)malloc(cols * sizeof(double));
            }
            if (array == NULL) {
                printf("Failed to allocate array. Aborting\n");
                return 1;
            }
        
            randomArray(array, rows, cols, 0);
            
            fprintf(stdout, "%d %d\n", rows, cols);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    fprintf(stdout, "%f ", array[i][j]);
                }
                    fprintf(stdout, "\n");
            }
        }

            for (i = 0; i < rows; i++) {
                free(array[i]);
            }
            free(array);
            array = NULL;
            fPtr = NULL;

    }
    return 0;
}