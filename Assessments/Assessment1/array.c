#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "random.h"

char** createMap(int row_map, int col_map) {
    /* Initialise variables*/
    int i;
    int col = col_map + 2;
    int row = row_map + 2;

    /* Dynamically allocated array of char pointer pointers named map*/
    char **map = (char**)malloc(row * sizeof(char *));
    
    /* Allocate a char pointer array for each element of map*/
    for (i = 0; i < row_map; i++) {
        map[i] = (char*)malloc(col * sizeof(char));
    }

    /* Check if memory allocation failed*/
    if (map == NULL) {
        printf("ERROR: Memory allocation failed");
    }

    /* Add top border*/
    for (i = 0; i < col - 1; i++) {
        map[0][i] = WALL;
    }

    /* Add border for all middle elements*/
    for (i = 1; i < row - 1; i++) {
        map[i][0] = '*';
        map[i][col - 1] = WALL;
    }

    /* Add bottom border*/
    for (i = 0; i < col - 1; i++) {
        map[row - 1][i] = WALL;
    }
    return map;
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
