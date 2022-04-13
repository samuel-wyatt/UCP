#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"

void createGame(int row, int col, int snakeLength, char **map, char *snake) {
    createBorder(row, col, map);
    placeFood(row, col, snakeLength, map);
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

void createSnake(int snakeLength, char **map, char *snake) {
    int i;
    map[1][snakeLength] = snake;
    snake[0] = '#';
    snake[snakeLength - 1] = '>';
    for (i = 1; i < snakeLength - 1; i++) {
        snake[i] = '-';
    }
}

