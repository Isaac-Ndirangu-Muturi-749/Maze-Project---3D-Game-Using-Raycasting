#include "../headers/collision.h"


/**
 * DetectCollision - Checks if there could be a collision
 * with the wall in the next player advance
 * @x: next x coordinate
 * @y: next y coordinate
 * Return: true if collision is detected, false otherwise
 */
bool DetectCollision(float x, float y) {
	// Check if the coordinates are within the map boundaries
	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE ||
		y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE) {
		return true;
	}

	// Calculate the map grid coordinates
	int mapGridX = floor(x / TILE_SIZE);
	int mapGridY = floor(y / TILE_SIZE);

	// Check if the next position contains a wall
	return map[mapGridY][mapGridX] != 0;
}
