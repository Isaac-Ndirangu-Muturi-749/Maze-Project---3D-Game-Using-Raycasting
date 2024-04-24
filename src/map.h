#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

// Constants
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define TILE_SIZE 50

extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS]; // Declaration


// Function prototypes
bool isInsideMap(float x, float y);
int getMapValue(int row, int col);

#endif /* MAP_H */
