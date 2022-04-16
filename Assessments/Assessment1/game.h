#ifndef GAME_H
#define GAME_H

void logic(char **map, int **snake, int row, int col, int snakeLength);
char input();
int move(char **map, int **snake, int tail, char direction, int *msg);

#endif
