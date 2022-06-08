/*********
 * Author: Samuel Wyatt
 * Date: 14/06/2022
 * File Name: main.c
 * Purpose: To receive command line arguments, call relevant functions.
 * *******/
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "game.h"
int main(int argc, char **argv)
{
    /* Name of the file*/
    char *fileName = NULL;
    /* Number of cycles the game should do*/
    int cycleNum = 0;
    /* 2d array to hold the state of the game*/
    int **gameState = NULL;
    int i, row = 0, col = 0;
    /* int pointers to hold the amount of rows and columns*/
    int *rowPtr = &row;
    int *colPtr = &col;

    /* Check if there are the correct amount of arguments*/
    if (argc < 3 || argc > 3 )
    {
        printf("USAGE: ./life <cell_file> <cycles>\n");
    } else 
    {
        /* Extract the file name and number of cycles from the command line*/
        fileName = argv[1];
        cycleNum = atoi(argv[2]);
        /*Check if cycleNum was a positive number*/
        if (cycleNum > 0)
        {
            gameState = readFile(fileName, rowPtr, colPtr);
            if (gameState != NULL)
            { 

                /* Call playGame, to begin*/
                playGame(gameState, cycleNum, *rowPtr, *colPtr);

                /* Free the 2d array*/
                for (i = 0; i < *rowPtr; i++)
                {
                    free(gameState[i]);
                }
                free(gameState);
            }
        } else 
        {
            printf("ERROR: <cycles> must be a positive integer\n");
        }
    }
    /* Set all pointers to NULL*/
    fileName = NULL;
    argv = NULL;
    gameState = NULL;

    return 0;
}
