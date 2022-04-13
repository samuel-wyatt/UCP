#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"

void createGame(int row, int col, int snakeLength, char **map) {
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
    placeFood(row, col, snakeLength, map);
}

void placeFood(int nRow, int nCol, int snakeLength, char** map) {
    /* Initialise variables*/
    int randR, randC;

    /* Generates coordinates for food placement, ensuring it is not placed on a border, or the snake*/
    randR = random(1, nRow);
    if (randR == 1) {
        randC = random((snakeLength + 1), nCol);
    } else {
        randC = random(1, nCol);
    }

    /*Replace that coordinate with @*/
    map[randR][randC] = FOOD;
}

