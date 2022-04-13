#ifndef FOOD
#define FOOD '@'
#endif

#ifndef WALL
#define WALL '*'
#endif

char** createMap(int row_map, int col_map);
void placeFood(int nRow, int nCol, char** map);
