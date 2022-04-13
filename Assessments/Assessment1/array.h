#ifndef FOOD
#define FOOD '@'
#endif

#ifndef WALL
#define WALL '*'
#endif

void createGame(int row, int col, int snakeLength, char **map, char *snake);
void placeFood(int row, int col, int snakeLength, char **map);
void createBorder(int row, int col, char **map);
void createSnake(int snakeLength, char **map, char *snake);
