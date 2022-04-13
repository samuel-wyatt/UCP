#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"

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

void placeFood(int nRow, int nCol, char** map) {
    /* Initialise variables*/
    int row = nRow - 2; 
    int col = nCol - 2;
    
    /*Replace that coordinate with @*/
    map[random(1, row)][random(1, col)] = FOOD;
}
