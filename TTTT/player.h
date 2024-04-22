#ifndef PLAYER_H
#define PLAYER_H

// Function prototypes
void movePlayer(int *playerX, int *playerY, double playerAngle);

#endif /* PLAYER_H */



/* Functions-variables-structs for player */

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

extern player_t player;

void movePlayer(float DeltaTime);

bool DetectCollision(float x, float y);
