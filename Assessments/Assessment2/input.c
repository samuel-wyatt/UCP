#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "main.h"

LinkedList* readFile(char *fileName, int *row_map, int *col_map) {
    /* Initialise file pointer, row and col for each snake body, and character for snake body*/
    FILE *fPtr;
    int row, col;
    char body;

    /* Initialise the linked list*/
    LinkedList *snake;

    /* Open the file with the file name provided, in read mode*/
    fPtr = fopen(fileName, "r");

    /* Check if the file pointer is NULL, to check if file was opened correctly*/
    if (fPtr == NULL) {
        /* Print error message if file could not be opened*/
        printf("ERROR: File \"%s\" could not be opened\n", fileName);
    } else {
        /* File has been successfully opened*/

        /* Create the linked list, which mallocs the memory*/
        list = createLinkedList();

        /* Read the first line of the file, the row and column for the map*/
        if (fscanf(fPtr, "%d %d", row_map, col_map) == 2) {
            /* Until EOF is reached, read each value of the line*/
            while (fscanf(fPtr, "%d %d %c", &row, &col, &body) != EOF) {
                /* Create a new struct pointer*/
                snakeBody *snakeBody = malloc(sizeof(snakeBody));
                /* Insert the values into the struct*/
                snakeBody->row = row;
                snakeBody->col = col;
                snakeBody->body = body;
                /* Insert the struct into the linked list*/
                insertLast(snake, (void*)snakeBody);
            }
        } else {
            /* Row and column couldn't be found, so throw error*/
            printf("ERROR: File format incorrect\n");
            list = NULL:
        }
    }
    /* Close the file and set the file pointer to NULL*/
    fclose(fPtr);
    fPtr = NULL;

    return list;
}