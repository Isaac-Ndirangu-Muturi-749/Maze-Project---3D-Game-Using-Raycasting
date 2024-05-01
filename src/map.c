#include "../headers/map.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 6, 0, 0, 0, 6, 0, 0, 0, 6},
    {6, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 0, 7, 7, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 1, 0, 0, 0, 0, 7, 7, 0, 6},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 6},
    {6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};

// Function to check if a point is inside the map
bool isInsideMap(float x, float y) {
    return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
            y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

// Function to get the value of a cell in the map
int getMapValue(int row, int col) {
    return map[row][col];
}

// Function to render the map
void renderMap(void) {
    int i, j, tileX, tileY;
    color_t tileColor;

    for (i = 0; i < MAP_NUM_ROWS; i++) {
        for (j = 0; j < MAP_NUM_COLS; j++) {
            tileX = j * TILE_SIZE;
            tileY = i * TILE_SIZE;
            tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

            drawRect(
                tileX * MINIMAP_SCALE_FACTOR,
                tileY * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                TILE_SIZE * MINIMAP_SCALE_FACTOR,
                tileColor
            );
        }
    }
}
