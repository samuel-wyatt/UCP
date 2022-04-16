#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "game.h"

void logic(char **map, int **snake, int row, int col, int snakeLength) {
    /*Initialise variables*/
    char direction;

    int gameOver = 0;
    int i, ii, a;
    int tail = snakeLength - 1;

    /* Start loop for gameplay*/
    do {
        /* Replaces the areas on the map with the new snake*/
        for (a = 0; a < snakeLength; a++) {
            map[snake[a][0]][snake[a][1]] = (char)snake[a][3];
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

        switch(direction) {
            case 'w':
                gameOver = moveUp(map, snake, tail);
            break;
            case 'a':
                
            break;
            case 's':
                gameOver = moveDown(map, snake, tail);
            break;
            case 'd':
                
            break;
        }

    } while (direction != 'x');
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
        if (direction != 'w' && direction != 'a' && direction != 's' && direction != 'd' && direction != 'x') {
            printf("Invalid Key\n");
            exit = -1;
        }
    } while (exit != 0);
    return direction;
}

int moveUp(char **map, int **snake, int tail) {
    /* Create variables*/
    int headRow, headCol, newRow, oldHeadRow, oldTailRow, gameOver, i;
    char newSpace;

    /* Initialise variables*/
    headRow = snake[0][0];
    headCol = snake[0][1];
    newRow = headRow - 1;
    newSpace = map[newRow][headCol];

    /* Base cases*/
    if (newSpace == '*') {
        gameOver = 0;
    } else if (newSpace == '@') {
        gameOver = 1;
    } else if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
        gameOver = -1;
    /* Main case*/
    } else {
        oldHeadRow = snake[0][0];
        oldTailRow = snake[tail][0];
        snake[0][0] = newRow;
        for (i = tail; i > 1; i--) {
            snake[i][0] = snake[i - 1][0];
        }
        snake[1][0] = oldHeadRow;
        map[oldTailRow][headCol] = ' ';
        gameOver = 0;
    }
    /* Resets all characters to correct type*/
    snake[0][2] = 94;
    
    snake[1][2] = 124;
    
    snake[tail][2] = 35;

    return gameOver;
}

int moveDown(char **map, int **snake, int tail) {
    /* Create variables*/
    int headRow, headCol, newRow, oldHeadRow, oldTailRow, gameOver, i;
    char newSpace;

    /* Initialise variables*/
    headRow = snake[0][0];
    headCol = snake[0][1];
    newRow = headRow + 1;
    newSpace = map[newRow][headCol];

    /* Base cases*/
    if (newSpace == '*') {
        gameOver = 0;
    } else if (newSpace == '@') {
        gameOver = 1;
    } else if (newSpace == '-' || newSpace == '|' || newSpace == '#') {
        gameOver = -1;
    /* Main case*/
    } else {
        oldHeadRow = snake[0][0];
        oldTailRow = snake[tail][0];
        snake[0][0] = newRow;
        for (i = tail; i > 1; i--) {
            snake[i][0] = snake[i - 1][0];
        }
        snake[1][0] = oldHeadRow;
        map[oldTailRow][headCol] = ' ';
        gameOver = 0;
    }
    /* Resets all characters to correct type*/
    snake[0][2] = 76;
    
    snake[1][2] = 124;
    
    snake[tail][2] = 35;

    return gameOver;
}

