/******************************************************
 * Author: Samuel Wyatt                               *
 * Date: 16/04/2022                                   *
 * File Name: game.c                                  *
 * Purpose: To run the input and logic of the program *
 * ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "game.h"
#include "LinkedList.h"
#include "main.h"

/**********************************
* ASCII Values for the characters *
*   # = 35                        *
*   < = 60                        *
*   > = 62                        *
*   ^ = 94                        *
*   v = 118                       *
*   | = 124                       *
*   - = 45                        *
***********************************/

/*
SUBMODULE : logic
IMPORT : map (char**), snake (int**), row (int), col (int), snakeLength (int)
EXPORT : None
PURPOSE : Controls the movement of the snake.
*/
void logic(char **map, LinkedList *snake, int row, int col, int foodNum) {
    /*Initialise variables*/
    char direction;
    int msgNum = 0;
    int *msg = &msgNum;
    int gameOver = 0;
    int tailIdx = size(snake) - 1;
    int i;

    /* Start loop for gameplay*/
    do {
        /* Replaces the areas on the map with the new snake*/
        ListNode *currentNode = snake->head;
        do {
            snakeBody *bodyElement = currentNode->value;
            map[bodyElement->row][bodyElement->col] = bodyElement->body;
            currentNode = currentNode->next;
        }
        
        /* Prints the map*/
        printMap(map, row, col);

        /* Print the message from the previous movement*/
        if (*msg == 1) {
            printf("Cannot go outside the map!");
        } else if (*msg == 2) {
            printf("Cannot go backwards!");
        }
        /* Reset the pointer to no message*/
        *msg = 0;

        /* Gets user input for direction*/
        direction = input();
       
        /* Switch case for the direction. Checks if user is attempting to move backwards, and calls relevant function if not*/
        ListNode *headNode = snake->head;
        snakeBody *headElement = headNode->value;
        char headChar = headElement->body;
        switch(direction) {
            case 'w':
                if (snake[0][2] != 118) {
                    gameOver = move(map, snake, tailIdx, direction, msg, row, col);
                } else {
                    *msg = 2;
                }
            break;
            case 'a':
                if (snake[0][2] != 62) {
                    gameOver = move(map, snake, tailIdx, direction, msg, row, col);
                } else {
                    *msg = 2;
                }
            break;
            case 's':
                if (snake[0][2] != 94) {
                    gameOver = move(map, snake, tailIdx, direction, msg, row, col);
                } else {
                    *msg = 2;
                }
            break;
            case 'd':
                if (snake[0][2] != 60) {
                    gameOver = move(map, snake, tailIdx, direction, msg, row, col);
                } else {
                    *msg = 2;
                }
            break;
        }

    } while (gameOver == 0);

 
    msg = NULL;

    /*Win/Lose messages*/
    if (gameOver == 1) {
        printf("You Win!\n");
    } else {
        printf("You Lose!\n");
    }
}

/*
SUBMODULE : input
IMPORT : None
EXPORT : direction (char)
PURPOSE : To receive input from the user, check if valid, and return if true.
*/
char input() {
    char direction;
    int exit;

    /* Loops until correct user input is provided*/
    do {
        exit = 0;
        /* Buffer disabled so that key is input as soon as it is entered*/
        disableBuffer();
        scanf("%c", &direction);
        enableBuffer();

        /* Checks if input is valid*/
        if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd') {
            printf("Invalid Key\n");
            exit = -1;
        }
    } while (exit != 0);
    return direction;
}

/*
SUBMODULE : move
IMPORT : map (char**), snake (int**), tailIdx (int), direction (char), msg (int*)
EXPORT : gameOver (int)
PURPOSE : To move the snake one element in the specified direction.
*/
int move(char **map, int **snake, int tailIdx, char direction, int *msg, int row, int col) {
    /* Initialises variables*/
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

    /* Switch case for deciding where the next array element will be*/
    switch (direction) {
        case 'w':
            newSpace = map[snake[0][0] - 1][snake[0][1]];
        break;
        case 's':
            newSpace = map[snake[0][0] + 1][snake[0][1]];
        break;
        case 'a':
            newSpace = map[snake[0][0]][snake[0][1] - 1];
        break;
        case 'd':
            newSpace = map[snake[0][0]][snake[0][1] + 1];
        break;
    }
    /* Keeps the row and column of the old location of the tail*/
    oldTailRow = snake[tailIdx][0];
    oldTailCol = snake[tailIdx][1];

    /* Base cases*/
    if (newSpace == '*') {
        *msg = 1;
        /* gameOver = 0 means that the game is still running*/
        gameOver = 0;

    /* Main case*/
    } else {
        /* Shuffles the row and column coordinates along the array*/
        for (i = tailIdx; i > 0; i--) {

            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        /* Moves the row or column of the head up or down, depending on direction*/
        switch (direction) {
            case 'w':
            snake[0][0]--;
            break;
            case 's':
            snake[0][0]++;
            break;
            case 'a':
            snake[0][1]--;
            break;
            case 'd':
            snake[0][1]++;
            break;
        }
        /* Sets the old location of the tail to whitespace*/
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;
    
        /* Resets all characters to correct character type*/
        resetChar(snake, direction, tailIdx);

        /* Check if the space that was moved to was the food*/
        if (newSpace == '@') {

            /* Replaces the areas on the map with the new snake*/
            for (i = tailIdx; i > -1; i--) {
                map[snake[i][0]][snake[i][1]] = (char)snake[i][2];
            }

            /* Reprints the map*/
            printMap(map, row, col);

            /* gameOver = 1 means that the player has won*/
            gameOver = 1;
        }

        /* If UNBEATABLE is compiled, then the ability to lose due to touching the snake is removed*/
        #ifndef UNBEATABLE
        /* Checks if the space that was moved to was the snakes body*/
        if (newSpace == '-' || newSpace == '|' || newSpace == '#') {

            /* Replaces the areas on the map with the new snake*/
            for (i = tailIdx; i > -1; i--) {
                map[snake[i][0]][snake[i][1]] = (char)snake[i][2];
            }

            /* Reprints the map*/
            printMap(map, row, col);

            /* gameOver = -1 means that the player has lost*/
            gameOver = -1;
        }
        #endif
    }
    return gameOver;
}

/*
SUBMODULE : printMap
IMPORT : map (char**), row (int), col (int)
EXPORT : None
PURPOSE : To print every element of the map.
*/
void printMap(char **map, int row, int col) {
    int i, ii;
    /* Clears the terminal before printing*/
    system("clear");
        for (i = 0; i < row; i++) {
            for (ii = 0; ii < col; ii++) {
                printf("%c", map[i][ii]);
            }
            printf("\n");
        }
}

/*
SUBMODULE : resetChar
IMPORT : snake (int**), direction (char)
EXPORT : None
PURPOSE : To reset the characters within the snake to the correct integer.
*/
void resetChar(int **snake, char direction, int tailIdx) {
    int i;
    switch (direction) {
            case 'w':
                /* Sets the first element of the array to '|' or '-', so that the subsequent elements can copy from it (useful if its the first turn)*/
                snake[0][2] = 124;
                /* Loops through the array, copying each character value to the previous one*/
                for (i = tailIdx - 1; i > 0; i--) {
                    snake[i][2] = snake[i - 1][2];
                }
                /* Resets head to '^' */
                snake[0][2] = 94;
                /* Resets tail to '#' */
                snake[tailIdx][2] = 35;
            break;
            case 's':
                snake[0][2] = 124;
                for (i = tailIdx - 1; i > 0; i--) {
                    snake[i][2] = snake[i - 1][2];
                }
                /* Resets head to 'v' */
                snake[0][2] = 118;
                snake[tailIdx][2] = 35;
            break;
            case 'a':
                snake[0][2] = 45;
                for (i = tailIdx - 1; i > 0; i--) {
                    snake[i][2] = snake[i - 1][2];
                }
                /* Resets head to '<' */
                snake[0][2] = 60;
                snake[tailIdx][2] = 35;
            break;
            case 'd':
                snake[0][2] = 45;
                for (i = tailIdx - 1; i > 0; i--) {
                    snake[i][2] = snake[i - 1][2];
                }   
                /* Resets head to '>' */
                snake[0][2] = 62;
                snake[tailIdx][2] = 35;
            break;
    }
}
