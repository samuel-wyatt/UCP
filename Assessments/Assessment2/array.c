/*********************************************************************
 * Author: Samuel Wyatt                                              *
 * Date: 16/04/2022                                                  *
 * File Name: array.c                                                *
 * Purpose: To intialise the map, and place the food *
 * *******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "random.h"
#include "array.h"
#include "LinkedList.h"
#include "main.h"


/*
SUBMODULE : createGame
IMPORT : row (int), col (int), map (char**), snake (LinkedList*)
EXPORT : None
PURPOSE : To run the subsequent methods for array initialisation and food placement.
*/
void createGame(int row, int col, char **map, LinkedList *snake) {
    createBorder(row, col, map);
    placeFood(row, col, map, snake);
}

/*
SUBMODULE: freeMap
IMPORT: map (char**), row (int)
EXPORT: None
PURPOSE: To free the memory used by the map
*/
void freeMap(char **map, int row) {
    int i;
    for (i = 0; i < row + 2; i++) {
        free(map[i]);
    }
    free(map);
}

/*
SUBMODULE : createBorder
IMPORT : row (int), col (int), map (char**)
EXPORT : None
PURPOSE : To fill the outside elements of the array to create the border.
*/
void createBorder(int row, int col, char **map) {
    /* Initialise variables*/
    int i, ii;

    /* Account for borders*/
    col += 2;
    row += 2;

    /* Add top border*/
    for (i = 0; i < col; i++) {
        map[0][i] = WALL;
    }

    /* Add border for all middle elements*/
    for (i = 1; i < row - 1; i++) {
        map[i][0] = WALL;

       for (ii = 1; ii < col; ii++) {
            map[i][ii] = ' ';
        }
        map[i][col - 1] = WALL;
    }

    /* Add bottom border*/
    for (i = 0; i < col; i++) {
        map[row - 1][i] = WALL;
    }
}

/*
SUBMODULE : placeFood
IMPORT : row (int), col (int), map (char**)
EXPORT : None
PURPOSE : To utilise random.c to create two random integers, the row and col elements for the food.
*/
void placeFood(int row, int col, char** map, LinkedList *snake) {
    /* Initialise variables*/
    int randR, randC; 
    
    /* Exit variable for do-while loop. 0 = don't exit, 1 = exit*/
    int exit = 1;

    /* Temporary list node and snake body to hold data*/
    ListNode *currentNode;
    snakeBody *bodyNode;

    /* Generates coordinates for food placement, ensuring it is not placed on a border, or the snake*/
    do {
        randR = random(1, row);
        randC = random(1, col);

        /*  Extracts the current node from the snake, starting at the head*/
        currentNode = snake->head;
        /* Loop until end of snake is reached*/
        while (currentNode != NULL || exit == 0) {

            /* Create a temporary struct to manipulate the data in the value of the current node*/
            bodyNode = currentNode->value;

            /* Check if the randomly generated row and column clash with snake coordinates*/
            if (randR == bodyNode->row || randC == bodyNode->col) {
                /* If yes, do not exit the do-while, and the row and col will be re-calulated*/
                exit = 0;
            } else {
                /* If no, exit both loops*/
                exit = 1;
            }
            currentNode = currentNode->next;
        }
    } while (exit == 0);

    /*Replace that coordinate with @*/
    map[randR][randC] = FOOD;
}