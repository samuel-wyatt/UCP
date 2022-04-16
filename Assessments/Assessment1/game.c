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
                    gameOver = move(map, snake, tailIdx, direction);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 'a':
                if (snake[0][2] != 62) {
                    gameOver = move(map, snake, tailIdx, direction);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 's':
                if (snake[0][2] != 94) {
                    gameOver = move(map, snake, tailIdx, direction);
                } else {
                    printf("Cannot move backwards\n");
                }
            break;
            case 'd':
                if (snake[0][2] != 60) {
                    gameOver = move(map, snake, tailIdx, direction);
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

int move(char **map, int **snake, int tailIdx, char direction) {
    char newSpace;
    int gameOver, i, oldTailRow, oldTailCol;

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
        
        map[oldTailRow][oldTailCol] = ' ';
        gameOver = 0;
    
        /* Resets all characters to correct type*/
        switch (direction) {
        case 'w':
            snake[0][2] = 124;
            for (i = tailIdx - 1; i > 0; i--) {
                snake[i][2] = snake[i - 1][2];
            }
            snake[0][2] = 94;
            snake[tailIdx][2] = 35;
        break;
        case 's':
            snake[0][2] = 124;
            for (i = tailIdx - 1; i > 0; i--) {
                snake[i][2] = snake[i - 1][2];
            }
            snake[0][2] = 118;
            snake[tailIdx][2] = 35;
        break;
        case 'a':
            snake[0][2] = 45;
            for (i = tailIdx - 1; i > 0; i--) {
                snake[i][2] = snake[i - 1][2];
            }
            snake[0][2] = 60;
            snake[tailIdx][2] = 35;
        break;
        case 'd':
            snake[0][2] = 45;
            for (i = tailIdx - 1; i > 0; i--) {
                snake[i][2] = snake[i - 1][2];
            }   
            snake[0][2] = 62;
            snake[tailIdx][2] = 35;
        break;
    }

        /* Case for if the space that was moved to was the food, or its own body*/
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
