#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"

void createGame(int row, int col, int snakeLength, char **map, int **snake) {
    createBorder(row, col, map);
    placeFood(row, col, snakeLength, map);
    createSnake(snakeLength, map, snake);
}

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

    /* Fills each element of snake with the coordinates for the snake on the map array initally, and the ASCII value for the starting characters*/
    for (i = snakeLength - 1; i > -1; i--) {
        snake[i][0] = 1;
        snake[i][1] = number;
        number++;
    }
    /* 
    # = 35
    < = 60
    > = 62
    ^ = 94
    v = 118
    | = 124
    - = 45 */
    snake[0][2] = 62;
    for (i = 1; i < snakeLength - 1; i++) {
        snake[i][2] = 45;
    }
    snake[snakeLength - 1][2] = 35;
}
