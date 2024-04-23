#ifndef PLAYER_H
#define PLAYER_H

// Function prototypes
void movePlayer(int *playerX, int *playerY, double playerAngle);

#endif /* PLAYER_H */



#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include "collision.h" // Assuming DetectCollision is defined here

/**
 * struct player_s - struct for the textures
 * @x: x coordinate
 * @y: y coordinate
 * @width: player width
 * @height: player height
 * @turnDirection: Turn Direction
 * @walkDirection: Walk Direction
 * @rotationAngle: player rotation angle
 * @walkSpeed: walk speed
 * @turnSpeed: turn speed
 */
typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

// Function prototypes
void movePlayer(float DeltaTime);

// External variable declaration
extern player_t player;

#endif /* PLAYER_H */
