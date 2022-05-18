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
#include "input.h"

/*
SUBMODULE : main
IMPORT : args (int), argv (char**)
EXPORT : (int)
PURPOSE : The main function of the program. Takes command line input and malloc's arrays.
*/
int main(int args, char **argv) {

    /* Row and column int pointers, to hold the information from the input file*/
    int *col_map = 0;
    int *row_map = 0;

    /* Variable to hold the amount of food needed to win*/
    int foodNum;

    /* Variable to hold to file name from the command line input*/
    char *fileName;

    /* LinkedList to hold the information about the snake*/
    LinkedList *snake;

    /* 2d char array to hold the map*/
    char **map = NULL;

    /* Print usage message if not enough arguments are provided*/
    if (args < 3) {
        printf("USAGE: ./snake <fileName.txt> <foodAmount>\n");
    } else {

        /* Extract the file name and food amount from the command line arguments*/
        fileName = argv[1];
        foodNum = atoi(argv[2]);

        /* If food amount is below two, print message and skip file input*/
        if (foodNum < 2) {
            printf("ERROR: Food amount must be two or greater\n");
        } else {
        
            /* Recieve a linked list from the readFile function, which has been filled with the starting data*/
            snake = readFile(fileName, row_map, col_map);

            /* Call the createGame function, which will initialise the map, and add the borders*/
            createGame(*row_map, *col_map, map, snake);

            /* Call the logic function, which controls all of the game movement and logic*/
            logic(map, snake, *row_map, *col_map, foodNum);

            /* Free the map array*/
            freeMap(map, *row_map);

            /* Free the snake linked list*/
            freeLinkedList(snake, &freeList);
        }
    }
    /* Set all pointers to NULL*/
    fileName = NULL;
    snake = NULL;
    col_map = NULL;
    row_map = NULL;
    map = NULL;

    return 1;
}

void freeList(void *data) {}