#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "terminal.h"
#include "array.h"

int main(int args, char **argv) {
    /* Initiailise variables*/
    int row_map, col_map, snake_length, proceed, i;
    char **map = NULL;
    char *snake = NULL;

    /* Check for correct usage*/
    if (args < 4) {
        printf("USAGE: ./snake <row_map> <col_map> <snake_length>\n");
        return 1;
    }

    /* Call initRandom*/
    initRandom();

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

    /*Initialise 2d array*/
    map = malloc((row_map + 2) * sizeof(char *));
    for (i = 0; i < row_map + 2; i++) {
        map[i] = malloc((col_map + 2) * sizeof(char));
    }
    /* Check if memory allocation failed*/
    if (map == NULL) {
        printf("ERROR: Memory allocation failed");
        return 1;   
    }

    /*Initialise the snake*/
    snake = malloc(snake_length * sizeof(char));

    /* Check if memory allocation failed*/
    if (snake == NULL) {
        printf("ERROR: Memory allocation failed");
        return 1;
    }

    /* Create the map and place the food*/
    createGame(row_map, col_map, snake_length, map, snake);

    for (i = 0; i < snake_length; i++) {
        printf("%c", snake[i]);
    }
    
    /* Free entire 2d array*/
    for (i = 0; i < row_map + 2; i++) {
        free(map[i]);
    }
    free(map);

    return 0;   
}
