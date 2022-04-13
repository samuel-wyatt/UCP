#include <stdio.h>
#include <stdlib.h>

char** createArray(int row_map, int col_map) {
    /* Initialise variables*/
    int i;
    int col = col_map + 2;
    int row = row_map + 2;

    /* Dynamically allocated array of char pointer pointers named gameArray*/
    char **gameArray = (char**)malloc(row * sizeof(char*));
    
    /* Allocate a char pointer array for each element of gameArray*/
    for (i = 0; i < row_map -1; i++) {
        gameArray[i] = (char*)malloc(col * sizeof(char));
    }

    /* Add top border*/
    for (i = 0; i < col - 1; i++) {
        gameArray[0][i] = '*';
    }

    /* Add border for all middle elements*/
    for (i = 1; i < row - 1; i++) {
        gameArray[i][0] = '*';
        gameArray[i][col - 1] = '*';
    }

    /* Add bottom border*/
    for (i = 0; i < col - 1; i++) {
        gameArray[row - 1][i] = '*';
    }
    return gameArray;
}
