#include <stdio.h>
#include <stdlib.h>

char** createArray(int row_map, int col_map) {
    /* Initialise variables*/
    int i;

    /* Accounts for border size*/
    row_map += 2;
    col_map += 2;

    /* Dynamically allocated array of char pointer pointers named gameArray*/
    char **gameArray = (char**)malloc(row_map * sizeOf('c'));
    
    /* Allocate a char pointer array for each element of gameArray*/
    for (i = 0; i < row_map; i++) {
        *gameArray[i] = (char*)malloc(col_map * sizeOf('c'));
    }

    /* Add top border*/
    for (i = 0; i < col_map; i++) {
        gameArray[0][i] = '*';
    }

    /* Add border for all middle elements*/
    for (i = 1; i < row_map - 2; i++) {
        gameArray[i][0] = '*';
        gameArray[i][col_map -1];
    }

    /* Add bottom border*/
    for (i = 0; i < col_map; i++) {
        gameArray[row_map - 1][i] = '*';
    }
    return gameArray;
}
