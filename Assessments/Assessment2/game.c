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
#include "array.h"
/*
SUBMODULE : logic
IMPORT : map (char**), snake (int**), row (int), col (int), snakeLength (int)
EXPORT : None
PURPOSE : Controls the movement of the snake.
*/
void logic(char **map, LinkedList *snake, int row, int col, int foodNum) {
    /*Initialise variables*/
    char direction, headChar;
    int msgNum = 0, foodCounter = 0, tmpFood;
    int *msg = &msgNum, *foodCountPtr = &foodCounter;
    ListNode *currentNode;
    snakeBody *bodyElement;

    /* Start loop for gameplay*/
    do {
        /* Replaces the areas on the map with the new snake*/
        currentNode = snake->head;
        while (currentNode != NULL) {
            bodyElement = (snakeBody*)currentNode->value;
            map[bodyElement->row][bodyElement->col] = bodyElement->body;
            currentNode = currentNode->next;
        } 
        
        /* Prints the map*/
        printMap(map, row, col);

        /* Print the food counter*/
        printf("Food Collected: %d/%d", foodCounter, foodNum);
        tmpFood = foodCounter;


        /* Print the message from the previous movement*/
        if (*msg == 1) {
            printf("\nCannot go outside the map!");
        } else if (*msg == 2) {
            printf("\nCannot go backwards!");
        }

        /* Reset the pointer to no message*/
        *msg = 0;

        /* Gets user input for direction*/
        direction = input();
       
        /* Switch case for the direction. Checks if user is attempting to move backwards, and calls relevant function if not*/
        currentNode = snake->head;
        bodyElement = (snakeBody*)currentNode->value;
        headChar = bodyElement->body;

        switch(direction) {
            case 'w':
                if ((int)headChar != 118) {
                    move(map, snake, direction, msg, foodCountPtr);
                } else {
                    *msg = 2;
                }
            break;
            case 'a':
                if ((int)headChar != 62) {
                    move(map, snake, direction, msg, foodCountPtr);
                } else {
                    *msg = 2;
                }
            break;
            case 's':
                if ((int)headChar != 94) {
                    move(map, snake, direction, msg, foodCountPtr);
                } else {
                    *msg = 2;
                }
            break;
            case 'd':
                if ((int)headChar != 60) {
                    move(map, snake, direction, msg, foodCountPtr);
                } else {
                    *msg = 2;
                }
            break;
        }
        if (*foodCountPtr > tmpFood && *foodCountPtr != foodNum) {
            placeFood(row - 2, col - 2, map);
        }

    } while (foodCounter != foodNum);
    
    currentNode = snake->head;
    while (currentNode != NULL) {
        bodyElement = (snakeBody*)currentNode->value;
        map[bodyElement->row][bodyElement->col] = bodyElement->body;
        currentNode = currentNode->next;
    } 
    printMap(map, row, col);

    msg = NULL;
    /* Print a final food counter*/
    printf("Food Collected: %d/%d\n", foodCounter, foodNum);

    /*Win message*/
    printf("You Win!\n");
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
IMPORT : map (char**), snake (LinkedList*), direction (char), msg (int*)
EXPORT : foodCounter (int)
PURPOSE : To move the snake one element in the specified direction.
*/
void move(char **map, LinkedList *snake, char direction, int *msg, int* foodCountPtr) {
    /* Initialises variables*/
    char newSpace;
    int oldTailRow, oldTailCol, headRow, headCol;
    ListNode *headNode, *tailNode, *currentNode, *prevNode;
    snakeBody *headBody, *tailBody, *currentBody, *prevBody;
    snakeBody *newTail = NULL;

    headNode = snake->head;
    headBody = (snakeBody*)headNode->value;
    
    tailNode = snake->tail;
    tailBody = (snakeBody*)tailNode->value;
    
    headRow = headBody->row;
    headCol = headBody->col;

    /* Switch case for deciding where the next array element will be*/
    switch (direction) {
        case 'w':
            newSpace = map[headRow - 1][headCol];
        break;
        case 's':
            newSpace = map[headRow + 1][headCol];
        break;
        case 'a':
            newSpace = map[headRow][headCol - 1];
        break;
        case 'd':
            newSpace = map[headRow][headCol + 1];
        break;
    }


    /* Keeps the row and column of the old location of the tail*/
    oldTailRow = tailBody->row;
    oldTailCol = tailBody->col;

    /* Base cases*/
    if (newSpace == '*') {
        *msg = 1;

    /* Main case*/
    } else {
        /* Shuffles the row and column coordinates along the list*/
        currentNode = snake->tail;
        prevNode = currentNode;
        while (prevNode != NULL) {
            if (currentNode != snake->head) {
                currentBody = (snakeBody*)currentNode->value;
                        
                prevNode = currentNode->prev;
                prevBody = (snakeBody*)prevNode->value;

                currentBody->row = prevBody->row;
                currentBody->col = prevBody->col;

                currentNode = currentNode->prev;
            } else {
                prevNode = NULL;
            }
        }
        /* Moves the row or column of the head up or down, depending on direction*/
        switch (direction) {
            case 'w':
            headBody->row--;
            break;
            case 's':
            headBody->row++;
            break;
            case 'a':
            headBody->col--;
            break;
            case 'd':
            headBody->col++;
            break;
        }
        
        map[oldTailRow][oldTailCol] = ' ';

        /* Check if the space that was moved to was the food*/
        if (newSpace == '@') {

            newTail = malloc(sizeof(snakeBody*));
            newTail->row = oldTailRow;
            newTail->col = oldTailCol;
            newTail->body = '#';
            insertLast(snake, newTail);
            *foodCountPtr += 1;
        }

        /* Resets all characters to correct character type*/
        resetChar(snake, direction);
    }
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
void resetChar(LinkedList *snake, char direction) {
    ListNode *currentNode, *prevNode;
    snakeBody *currentBody, *prevBody;

    switch (direction) {
            case 'w':
                /* Temporary node at the head*/
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '|';         

                /* Reset the currentNode to the tail, to iterate backwards through the linkedlist*/
                currentNode = snake->tail;
                prevNode = currentNode;
                /* While loop to loop through the linked list*/ 
                while (prevNode != NULL) {
                    if (currentNode != snake->head) {
                        currentBody = (snakeBody*)currentNode->value;
                        
                        prevNode = currentNode->prev;
                        prevBody = (snakeBody*)prevNode->value;

                        currentBody->body = prevBody->body;

                        currentNode = currentNode->prev;
                    } else {
                        prevNode = NULL;
                    }
                }
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '^';

                currentNode = snake->tail;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '#';
            break;
            case 's':
                /* Temporary node at the head*/
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '|';         

                /* Reset the currentNode to the tail, to iterate backwards through the linkedlist*/
                currentNode = snake->tail;
                prevNode = currentNode;
                /* While loop to loop through the linked list*/ 
                while (prevNode != NULL) {
                    if (currentNode != snake->head) {
                        currentBody = (snakeBody*)currentNode->value;
                        
                        prevNode = currentNode->prev;
                        prevBody = (snakeBody*)prevNode->value;

                        currentBody->body = prevBody->body;

                        currentNode = currentNode->prev;
                    } else {
                        prevNode = NULL;
                    }
                }
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = 'v';

                currentNode = snake->tail;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '#';
            break;
            case 'a':
                /* Temporary node at the head*/
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '-';         

                /* Reset the currentNode to the tail, to iterate backwards through the linkedlist*/
                currentNode = snake->tail;
                prevNode = currentNode;
                /* While loop to loop through the linked list*/ 
                while (prevNode != NULL) {
                    if (currentNode != snake->head) {   
                        currentBody = (snakeBody*)currentNode->value;
                        
                        prevNode = currentNode->prev;
                        prevBody = (snakeBody*)prevNode->value;

                        currentBody->body = prevBody->body;

                        currentNode = currentNode->prev;
                    } else {
                        prevNode = NULL;
                    }
                }
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '<';

                currentNode = snake->tail;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '#';
            break;
            case 'd':
                /* Temporary node at the head*/
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '-';         

                /* Reset the currentNode to the tail, to iterate backwards through the linkedlist*/
                currentNode = snake->tail;
                prevNode = currentNode;
                /* While loop to loop through the linked list*/ 
                while (prevNode != NULL) {
                    if (currentNode != snake->head) {
                        currentBody = (snakeBody*)currentNode->value;
                        
                        prevNode = currentNode->prev;
                        prevBody = (snakeBody*)prevNode->value;

                        currentBody->body = prevBody->body;

                        currentNode = currentNode->prev;
                    } else {
                        prevNode = NULL;
                    }
                }
                currentNode = snake->head;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '>';

                currentNode = snake->tail;
                currentBody = (snakeBody*)currentNode->value;
                currentBody->body = '#';
            break;
    }
}
