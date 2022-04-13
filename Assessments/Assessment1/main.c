#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int args, char **argv) {
    /* Initiailise variables*/
    int row_map, col_map, snake_length, proceed;
    char **gameArray;
    int i, a;

    /* Check for correct usage*/
    if (args < 4) {
        printf("USAGE: ./snake <row_map> <col_map> <snake_length>\n");
        return 1;
    }

    /* Assign command line input to variables*/
    row_map = atoi(argv[1]);
    col_map = atoi(argv[2]);
    snake_length = atoi(argv[3]);
    
    /* Checks if col_map and row_map are within correct bounds*/
    if (row_map < 5) {
        printf("ERROR: Row length must be 5 or greater\n");
        proceed = -1;
    }
    if (col_map < 5) {
        printf("ERROR: Column length must be 5 or greater\n");
        proceed = -1;
    }
    /* Checks if snake_length is within correct bounds*/
    if (snake_length > col_map) {
        printf("ERROR: Snake length cannot be greater than column length\n");
        proceed = -1;
    }
    if (snake_length < 3) {
        printf("ERROR: Snake length cannot be less than 3\n");
        proceed = -1;
    }

    /* Exits the program if any errors have been encountered*/
    if (proceed == -1) {
        return 1;
    }

    /* Create array*/
    gameArray = createArray(row_map, col_map);
    
    for (i = 0; i < row_map; i++) {
        for (a = 0; a < col_map; a++) {
            printf(gameArray[i][a]);
        }
    }
    return 0;   
}
