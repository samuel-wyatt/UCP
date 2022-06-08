/*********
 * Author: Samuel Wyatt
 * Date: 14/06/2022
 * File Name: input.c
 * Purpose: To read the input file and create the relevant array.
 * *******/
#include <stdio.h>
#include <stdlib.h>

int** readFile(char *fileName, int *rowPtr, int *colPtr)
{
    /* 2d array of ints to hold the game state*/
    int **gameState;
    /* FILE pointer*/
    FILE *fPtr;
    /* Number of rows and columns*/
    int row = 0, col = 0;
    int i, ii, jj;

    rowPtr = &row;
    colPtr = &col;

    /* Open the file in read mode*/
    fPtr = fopen(fileName, "r");

    /* Check if the FILE pointer is NULL*/
    if (fPtr == NULL)
    {
        printf("ERROR: File \"%s\" could not be opened\n", fileName);
        gameState = NULL;
    } else
    {
        /* Scan the first two numbers in the file, the row and column size of the matrix*/
        if (fscanf(fPtr, "%d %d", &row, &col) == 2)
        {
            /* Allocate the 2d array*/
            gameState = malloc(row * sizeof(int*));
            for (i = 0; i < row; i++)
            {
                gameState[i] = malloc(col * sizeof(int));
            }

            /* Read each number from the file*/
            for (ii = 0; ii < row; ii++)
            {
                for (jj = 0; jj < col; jj++)
                {
                    fscanf(fPtr, "%d", &gameState[ii][jj]);
                }
            }   
        } else
        {
            printf("ERROR: Please provide <row> <column> on the first line of the file\n");
        }
        fclose(fPtr);
    }
    /* Set the FILE pointer to null*/
    fPtr = NULL;

    return gameState;
}