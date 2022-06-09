/*********
 * Author: Samuel Wyatt
 * Date: 09/06/2022
 * File Name: game.c
 * Purpose: To run the game for the specfied amount of cycles.
 * *******/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"

/*
SUBMODULE: playGame
IMPORT: gameState (int**), cycleNum (int), row (int), col (int)
EXPORT: None
PURPOSE: To loop the game a specific amount of times, and make cells alive/dead.
*/
void playGame(int **gameState, int cycleNum, int row, int col)
{
    int i, ii, jj, currAlive;

    /* Another 2d array, which will hold the game state for the next cycle*/
    int **gameNext = malloc(row * sizeof(int*));
    for (i = 0; i < row; i++)
    {
        gameNext[i] = malloc(col * sizeof(int));
    }

    /* Run the game for the specified amount of cycles*/
    for (i = 0; i < cycleNum; i++)
    {
        /* Copy the array on every cycle except the first*/
        if (i != 0)
        {
            copyArray(gameState, gameNext, row, col);
        }
        /* Print the state of the game*/
        printGame(gameState, row, col);

        /* Loop through every element of the array*/
        for (ii = 0; ii < row; ii++)
        {
            for (jj = 0; jj < col; jj++)
            {
                /* Get the amount of alive neighbours the cell has*/
                currAlive = getNeighbours(gameState, ii, jj, row - 1, col - 1);
                /*If the current cell is alive*/
                if (gameState[ii][jj] == 1)
                {
                    /* If there are 2 or 3 alive neighbours, make the cell alive next cycle*/
                    if (currAlive == 2 || currAlive == 3)
                    {
                        gameNext[ii][jj] = 1;
                    /* Else make the cell dead next cycle*/
                    } else 
                    {
                        gameNext[ii][jj] = 0;
                    }
                /* If the current cell is dead*/
                } else 
                {
                    /* If there are 3 alive neighbours, make the cell alive next cycle*/
                    if (currAlive == 3)
                    {
                        gameNext[ii][jj] = 1;
                    /* Else make the cell dead next cycle*/
                    } else 
                    {
                        gameNext[ii][jj] = 0;
                    }
                }
            }
        }
        /* Sleep the program for one second before next cycle*/
        sleep(1);
    }

    /* Free the 2d array*/
    for (i = 0; i < row; i++)
    {
        free(gameNext[i]);
    }
    free(gameNext);
}

/*
SUBMODULE: printGame
IMPORT: gameState (int**), row (int), col (int)
EXPORT: None
PURPOSE: To print the current state of the game onto the terminal using white and black colours.
*/
void printGame(int **gameState, int row, int col)
{
    int i, j;
    /* Clear the terminal*/
    system("clear");
    /* Loop through every element of the array*/
    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {
            /* If the cell is alive, set background to black*/
            if (gameState[i][j] == 1) 
            {
                printf("\033[0;100m"); 
            /* The cell must be dead, set the background to white*/
            } else 
            {
                printf("\033[0;107m");
            }
            /* Print a blank character which will be black or white*/
            printf("%c", ' ');
            /* Reset the background colour to default*/
            printf("\033[0m");
        }
        printf("\n");
    }
}

/*
SUBMODULE: getNeighbours
IMPORT: gameState (int**), currRow (int), currCol (int)
EXPORT: currAlive (int)
PURPOSE: To find the amount of alive and dead neighbors of a single element.
*/
int getNeighbours(int **gameState, int currRow, int currCol, int maxRow, int maxCol)
{
    int topLeft, topMiddle, topRight, middleLeft, middleRight, bottomLeft, bottomMiddle, bottomRight, totalAlive;
    /* There are 8 base cases for getting the neighbors. One for each corner, and one per edge (not in corner but still on edge)*/
    if (currRow == 0 && currCol == 0)
    {
        /* Top left corner*/
        middleRight = gameState[0][1];
        bottomMiddle = gameState[1][0];
        bottomRight = gameState[1][1];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = middleRight + bottomMiddle + bottomRight;
    } else if (currRow == 0 && currCol == maxCol)
    {
        /* Top right corner*/
        middleLeft = gameState[0][maxCol - 1];
        bottomLeft = gameState[1][maxCol - 1];
        bottomMiddle = gameState[1][maxCol];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = middleLeft + bottomLeft + bottomMiddle;
    } else if (currRow == maxRow && currCol == 0)
    {
        /* Bottom left corner*/
        topMiddle = gameState[maxRow - 1][0];
        topRight = gameState[maxRow - 1][1];
        middleRight = gameState[maxRow][1];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = topMiddle + topRight + middleRight;
    } else if (currRow == maxRow && currCol == maxCol)
    {
        /* Bottom right corner*/
        middleLeft = gameState[maxRow][maxCol - 1];
        topLeft = gameState[maxRow - 1][maxCol - 1];
        topMiddle = gameState[maxRow - 1][maxCol];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = middleLeft + topLeft + topMiddle;
    } else if (currRow == 0)
    {
        /* Anywhere on top row*/
        middleLeft = gameState[0][currCol - 1];
        bottomLeft = gameState[1][currCol - 1];
        bottomMiddle = gameState[1][currCol];
        bottomRight = gameState[1][currCol + 1];
        middleRight = gameState[0][currCol + 1];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = middleLeft + bottomLeft + bottomMiddle + bottomRight + middleRight;
    } else if (currRow == maxRow)
    {
        /* Anywhere on bottom row*/
        middleLeft = gameState[maxRow][currCol - 1];
        topLeft = gameState[maxRow - 1][currCol - 1];
        topMiddle = gameState[maxRow - 1][currCol];
        topRight = gameState[maxRow - 1][currCol + 1];
        middleRight = gameState[maxRow][currCol + 1];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = middleLeft + topLeft + topMiddle + topRight + middleRight;
    } else if (currCol == 0) 
    {
        /* Anywhere on left column*/
        topMiddle = gameState[currRow - 1][0];
        topRight = gameState[currRow - 1][1];
        middleRight = gameState[currRow][1];
        bottomRight = gameState[currRow + 1][1];
        bottomMiddle = gameState[currRow + 1][0];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = topMiddle + topRight + middleRight + bottomRight + bottomMiddle;
    } else if (currCol == maxCol)
    {
        /* Anywhere of right column*/
        topMiddle = gameState[currRow - 1][maxCol];
        topLeft = gameState[currRow - 1][maxCol - 1];
        middleLeft = gameState[currRow][maxCol - 1];
        bottomLeft = gameState[currRow + 1][maxCol - 1];
        bottomMiddle = gameState[currRow + 1][maxCol];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = topMiddle + topLeft + middleLeft + bottomLeft + bottomMiddle;
    } else 
    {
        /* Anywhere else in the map*/
        topLeft = gameState[currRow - 1][currCol - 1];
        topMiddle = gameState[currRow - 1][currCol];
        topRight = gameState[currRow - 1][currCol + 1];
        middleLeft = gameState[currRow][currCol - 1];
        middleRight = gameState[currRow][currCol + 1];
        bottomLeft = gameState[currRow + 1][currCol - 1];
        bottomMiddle = gameState[currRow + 1][currCol];
        bottomRight = gameState[currRow + 1][currCol + 1];

        /* Adding up the neighbours will give us the total amount of alive cells*/
        totalAlive = topLeft + topMiddle +  topRight + middleLeft + middleRight + bottomLeft + bottomMiddle + bottomRight;
    }
    return totalAlive;
}

/*
SUBMODULE: copyArray
IMPORT: gameState (int**), gameNext (int**)
EXPORT: None
PURPOSE: To copy the state of the next cycle into the array holding the current cycle.
*/
void copyArray(int **gameState, int **gameNext, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            /* Copy each element from the next cycle into the current*/
            gameState[i][j] = gameNext[i][j];
        }
    }
}   