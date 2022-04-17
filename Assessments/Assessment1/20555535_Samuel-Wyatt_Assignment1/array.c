/*********************************************************************
 * Author: Samuel Wyatt                                              *
 * Date: 16/04/2022                                                  *
 * File Name: array.c                                                *
 * Purpose: To intialise the map and snake array, and place the food *
 * *******************************************************************/
#include "random.h"
#include "array.h"

/*
SUBMODULE : createGame
IMPORT : row (int), col (int), snakeLength (int), map (char**), snake (int**)
EXPORT : None
PURPOSE : To run the subsequent methods for array initialisation and food placement.
*/
void createGame(int row, int col, int snakeLength, char **map, int **snake) {
    createBorder(row, col, map);
    placeFood(row, col, snakeLength, map);
    createSnake(snakeLength, map, snake);
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
IMPORT : row (int), col (int), snakeLength (int), map (char**)
EXPORT : None
PURPOSE : To utilise random.c to create two random integers, the row and col elements for the food.
*/
void placeFood(int row, int col, int snakeLength, char** map) {
    /* Initialise variables*/
    int randR, randC;

    /* Generates coordinates for food placement, ensuring it is not placed on a border, or the snake*/
    randR = random(1, row);
    if (randR == 1) {
        randC = random((snakeLength + 1), col);
    } else {
        randC = random(1, col);
    }
    /*Replace that coordinate with @*/
    map[randR][randC] = FOOD;
}

void createSnake(int snakeLength, char **map, int **snake) {
    int i;
    int number = 1;

    /* Fills each element of snake with the coordinates for the snake on the map array in its initial location*/
    for (i = snakeLength - 1; i > -1; i--) {
        snake[i][0] = 1;
        snake[i][1] = number;
        number++;
    }
    /*Fills the elements of column 3, which contain an integer representation of the character type of that section of snake*/
    snake[0][2] = 62;
    for (i = 1; i < snakeLength - 1; i++) {
        snake[i][2] = 45;
    }
    snake[snakeLength - 1][2] = 35;
}
