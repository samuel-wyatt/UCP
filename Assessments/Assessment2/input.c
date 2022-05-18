#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "main.h"

LinkedList* readFile(char *fileName, int *row_map, int *col_map) {
    /* Initialise file pointer, row and col for each snake body, and character for snake body*/
    FILE *fPtr;
    int row, col;
    char body;

    snakeBody *snakeBody;

    /* Initialise the linked list*/
    LinkedList *snake;

    /* Open the file with the file name provided, in read mode*/
    fPtr = fopen(fileName, "r");

    /* Check if the file pointer is NULL, to check if file was opened correctly*/
    if (fPtr == NULL) {
        /* Print error message if file could not be opened*/
        printf("ERROR: File \"%s\" could not be opened\n", fileName);
        snake = NULL;
    } else {
        /* File has been successfully opened*/

        /* Create the linked list, which mallocs the memory*/
        snake = createLinkedList();

        /* Read the first line of the file, the row and column for the map*/
        if (fscanf(fPtr, "%d %d", row_map, col_map) == 2) {
            /* Until EOF is reached, read each value of the line*/
            while (fscanf(fPtr, "%d %d %c", &row, &col, &body) != EOF) {

                /* Malloc the structS*/
                snakeBody = malloc(sizeof(*snakeBody));
                /* Insert the values into the struct*/
                snakeBody->row = row + 1;
                snakeBody->col = col + 1;
                snakeBody->body = body;
                /* Insert the struct into the linked list*/
                insertStart(snake, (void*)snakeBody);
            }
        } else {
            /* Row and column couldn't be found, so throw error*/
            printf("ERROR: File format incorrect\n");
            snake = NULL;
        }
        fclose(fPtr);
    }
    /* Close the file and set the file pointer to NULL*/
    fPtr = NULL;

    return snake;
}