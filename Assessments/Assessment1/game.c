#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "game.h"
#include "array.h"

void logic(char **map, int **snake, int row, int col, int snakeLength) {
    /*Initialise variables*/
    char direction;
    int gameOver = 0;
    int i, ii;
    int tailIdx = snakeLength - 1;

    /* Start loop for gameplay*/
    do {
        /* Replaces the areas on the map with the new snake*/
        for (i = 0; i < snakeLength; i++) {
            map[snake[i][0]][snake[i][1]] = (char)snake[i][2];
        }
        /* Prints every element of the map, clearing the terminal beforehand*/
        system("clear");
        for (i = 0; i < row; i++) {
            for (ii = 0; ii < col; ii++) {
                printf("%c", map[i][ii]);
            }
            printf("\n");
        }

        /* Gets user input for direction*/
        direction = input();

        /* ASCII Values for the characters
            # = 35
            < = 60
            > = 62
            ^ = 94
            v = 118
            | = 124
            - = 45 */

        /* Switch case for the direction. Checks if user is attempting to move backwards, and calls relevant function if not*/
        switch(direction) {
            case 'w':
                if (snake[0][2] != 118) {
                    gameOver = moveUp(map, snake, tailIdx);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 'a':
                if (snake[0][2] != 62) {
                    gameOver = moveLeft(map, snake, tailIdx);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 's':
                if (snake[0][2] != 94) {
                    gameOver = moveDown(map, snake, tailIdx);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 'd':
                if (snake[0][2] != 60) {
                    gameOver = moveRight(map, snake, tailIdx);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
        }

    } while (gameOver == 0);
    /*Win/Lose messages*/
    if (gameOver == 1) {
        printf("You Win!\n");
    } else {
        printf("You Lose!\n");
    }
}

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
        if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd') {
            printf("Invalid Key\n");
            exit = -1;
        }
    } while (exit != 0);
    return direction;
}



int moveUp(char **map, int **snake, int tailIdx) {
    /* Create variables*/
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

    /* Initialise variables*/
    newSpace = map[snake[0][0] - 1][snake[0][1]];
    oldTailRow = snake[tailIdx][0];
    oldTailCol = snake[tailIdx][1];

    /* Do absolutely nothing if next space is a wall*/
    if (newSpace == '*') {
        gameOver = 0;
    /* Main case*/
    } else {
        /* Shuffles the row and column values up one*/
        for (i = tailIdx; i > 0; i--) {

            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        /* Decrease the value of the row of the head (index of the map)*/
        snake[0][0]--;
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;
    
        
        /* Resets all characters to correct type*/
        snake[0][2] = 124;
        for (i = tailIdx - 1; i > 0; i--) {
            snake[i][2] = snake[i - 1][2];
        }
        snake[0][2] = 94;
        snake[tailIdx][2] = 35;
        }

        if (newSpace == '@') {
            gameOver = 1;
        }
        #ifndef UNBEATABLE
        if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
            gameOver = -1;
        }
        #endif
    return gameOver;
}

int moveDown(char **map, int **snake, int tailIdx) {
    /* Create variables*/
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

    /* Initialise variables*/
    newSpace = map[snake[0][0] + 1][snake[0][1]];
    oldTailRow = snake[tailIdx][0];
    oldTailCol = snake[tailIdx][1];

    /* Base cases*/
    if (newSpace == '*') {
        gameOver = 0;
    /* Main case*/
    } else {
        for (i = tailIdx; i > 0; i--) {

            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][0]++;
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;

        
        /* Resets all characters to correct type*/
    
        snake[0][2] = 124;
        for (i = tailIdx - 1; i > 0; i--) {
            snake[i][2] = snake[i - 1][2];
        }
        snake[0][2] = 118;
        snake[tailIdx][2] = 35;

        if (newSpace == '@') {
            gameOver = 1;
        }
        #ifndef UNBEATABLE
        if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
            gameOver = -1;
        }
        #endif
    }
    return gameOver;
}

int moveRight(char **map, int **snake, int tailIdx) {
    /* Create variables*/
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

    /* Initialise variables*/
    newSpace = map[snake[0][0]][snake[0][1] + 1];
    oldTailRow = snake[tailIdx][0];
    oldTailCol = snake[tailIdx][1];

    /* Base cases*/
    if (newSpace == '*') {
        gameOver = 0;
    
    /* Main case*/
    } else {
        for (i = tailIdx; i > 0; i--) {

            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][1]++;
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;
        
        
        /* Resets all characters to correct type*/
        snake[0][2] = 45;
        for (i = tailIdx - 1; i > 0; i--) {
            snake[i][2] = snake[i - 1][2];
        }
        snake[0][2] = 62;
        snake[tailIdx][2] = 35;

        if (newSpace == '@') {
            gameOver = 1;
        }
        #ifndef UNBEATABLE
        if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
            gameOver = -1;
        }
        #endif
    }
    return gameOver;
}

int moveLeft(char **map, int **snake, int tailIdx) {
    /* Create variables*/
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

    /* Initialise variables*/
    newSpace = map[snake[0][0]][snake[0][1] - 1];
    oldTailRow = snake[tailIdx][0];
    oldTailCol = snake[tailIdx][1];

    /* Base cases*/
    if (newSpace == '*') {
        gameOver = 0;
    
    /* Main case*/
    } else {
        for (i = tailIdx; i > 0; i--) {

            snake[i][0] = snake[i - 1][0];
            snake[i][1] = snake[i - 1][1];
        }
        snake[0][1]--;
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;
    
        /* Resets all characters to correct type*/
        snake[0][2] = 45;
        for (i = tailIdx - 1; i > 0; i--) {
            snake[i][2] = snake[i - 1][2];
        }
        snake[0][2] = 60;
        snake[tailIdx][2] = 35;

        if (newSpace == '@') {
            gameOver = 1;
        }
        #ifndef UNBEATABLE
        if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
            gameOver = -1;
        }
        #endif
    }
    return gameOver;
}
