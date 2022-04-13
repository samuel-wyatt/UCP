#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"

void createArray(int row, int col, char ***map) {
    /* Initialise variables*/
    int i;

    /* Dynamically allocated array of char pointer pointers named map*/
    map = malloc((row + 2) * sizeof(char*));
    
    /* Allocate a char pointer array for each element of map*/
    for (i = 0; i < row -1; i++) {
        map[i] = malloc((col + 2) * sizeof(char));
    }

    /* Account for borders*/
    col += 2;
    row += 2;

    /* Add top border*/
    for (i = 0; i < col - 1; i++) {
        map[0][i] = '*';
    }

    /* Add border for all middle elements*/
    for (i = 1; i < row - 1; i++) {
        map[i][0] = '*';
        map[i][col - 1] = '*';
    }

    /* Add bottom border*/
    for (i = 0; i < col - 1; i++) {
        map[row - 1][i] = '*';
    }
}

void placeFood(int nRow, int nCol, char** map) {
    /* Initialise variables*/
    int row, col;
    
    /* Call initRandom*/
    initRandom();

    /*Assign random numbers to row and col, which will land on the playing area*/
    row = random(0, nRow);
    col = random(0, nCol);

    /*Replace that coordinate with @*/
    map[row][col] = FOOD;
}
