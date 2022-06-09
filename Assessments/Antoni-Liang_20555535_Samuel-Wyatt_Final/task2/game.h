#ifndef GAME_H
#define GAME_H

void playGame(int **gameState, int cycleNum, int row, int col);
void printGame(int **gameState, int row, int col);
int getNeighbours(int **gameState, int currRow, int currCol, int maxRow, int maxCol);
void copyArray(int **gameState, int **gameNext, int row, int col);

#endif