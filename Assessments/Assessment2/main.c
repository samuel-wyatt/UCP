/*********************************************************************
 * Author: Samuel Wyatt                                              *
 * Date: 16/04/2022                                                  *
 * File Name: main.c                                                 * 
 * Purpose: To recieve command line arguments, create map and snake, *
 *          call the appropriate functions and free memory           *
 * *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "array.h"
#include "game.h"
#include "main.h"
#include "LinkedList.h"

/*
SUBMODULE : main
IMPORT : args (int), argv (char**)
EXPORT : (int)
PURPOSE : The main function of the program. Takes command line input and malloc's arrays.
*/
int main(int args, char **argv) {
    /* Initiailise variables*/
    LinkedList *list;
    FILE *fp;
    int row_map, col_map, proceed = 0, i, foodNum, snake_length = 4;
    int col_snake, row_snake;
    char bodyType;
    char *fileName;
    char **map = NULL;
    int **snake = NULL;


    /* Check for correct usage*/
    if (args < 4) {
        printf("USAGE: ./snake <row_map> <col_map> <snake_length>\n");
    } else {

        /* Call initRandom*/
        initRandom();

        /* Assign command line input to variables*/
        fileName = argv[1];
        foodNum = atoi(argv[2]);
        
        fp = fopen(fileName, "r");
        if (fp == NULL) {
            printf("ERROR: Failed to open %s", fileName);
        } else {
            fscanf(fp, "%d %d", &row_map, &col_map);
            while (fscanf(fp, "%d %d %c", &row_snake, &col_snake, &bodyType) > 0) {
                snakeBody *snakeBody = malloc(sizeof(snakeBody));
                snakeBody->col = col_snake;
                snakeBody->row = row_snake;
                snakeBody->body = bodyType;
                insertLast(list, snakeBody);
            }
        }
        printLinkedList(list, &printList);


        
        /* Checks if col_map and row_map are within correct bounds*/
        if (row_map < 5) {
            printf("ERROR: Row length must be 5 or greater\n");
            proceed = -1;
        }
        if (col_map < 5) {
            printf("ERROR: Column length must be 5 or greater\n");
            proceed = -1;
        }
        if (foodNum > 2) {
            printf("ERROR: Food amount to win must be 2 or greater\n");
            proceed = -1;
        }

        proceed = -1;
        /* Exits the program if any errors have been encountered*/
        if (proceed != -1) {

            /* Initialise the linked list*/
            list = createLinkedList();

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

            /* Create the map and place the food*/
            createGame(row_map, col_map, snake_length, map, snake);

            /*Begin the game logic*/
            logic(map, snake, row_map + 2, col_map + 2, snake_length);
            
            /* Free map array*/
            for (i = 0; i < row_map + 2; i++) {
                free(map[i]);
            }
            free(map);

            /* Free snake array*/
            for (i = 0; i < snake_length; i++) {
                free(snake[i]);
            }
            free(snake);

            /* Free Linked List*/
            freeLinkedList(list, &freeList);

            /* Set pointer to NULL*/
            map = NULL;
            snake = NULL;
        }
    }    
    return 0;   
}

void printList(void *data) {
    snakeBody *tmp = (snakeBody*)data;
    printf("Row: %d, Col: %d, Character: %c", tmp->row, tmp->col, tmp->body);
}

void freeList(void *data) {
    snakeBody *tmp = (snakeBody*)data;
    tmp->col = -1;
    tmp->row = -1;
    tmp->body = '~';
    tmp = NULL;
}
