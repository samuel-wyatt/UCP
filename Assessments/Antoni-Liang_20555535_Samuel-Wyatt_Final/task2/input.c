/*********
 * Author: Samuel Wyatt
 * Date: 09/06/2022
 * File Name: input.c
 * Purpose: To read the input file and create the relevant array.
 * *******/
#include <stdio.h>
#include <stdlib.h>

/*
SUBMODULE: readFile
IMPORT: fileName (char*), rowPtr (int*), colPtr (int*)
EXPORT: gameState (int**)
PURPOSE: To read an inut file, and store the contents in a 2d int array.
*/
int** readFile(char *fileName, int *rowPtr, int *colPtr)
{
    /* 2d array of ints to hold the game state*/
    int **gameState;
    /* FILE pointer*/
    FILE *fPtr;
    /* Number of rows and columns*/
    int i, ii, jj;

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
        if (fscanf(fPtr, "%d %d", rowPtr, colPtr) == 2)
        {
            /* Allocate the 2d array*/
            gameState = malloc(*rowPtr * sizeof(int*));
            for (i = 0; i < *rowPtr; i++)
            {
                gameState[i] = malloc(*colPtr * sizeof(int));
            }

            /* Read each number from the file*/
            for (ii = 0; ii < *rowPtr; ii++)
            {
                for (jj = 0; jj < *colPtr; jj++)
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