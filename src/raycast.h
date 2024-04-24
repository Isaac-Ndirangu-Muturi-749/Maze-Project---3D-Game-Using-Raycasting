#ifndef RAYCAST_H
#define RAYCAST_H

#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "main.h"
#include "map.h"

#include "utilities.h"

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)

#define NUM_RAYS SCREEN_WIDTH
#define PI 3.14159265
#define TWO_PI 6.28318530

#define FOV_ANGLE (60 * (PI / 180))
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))


// Function prototypes
void castRay(float rayAngle, int stripId);
void castAllRays(void);
bool isRayFacingDown(float angle);
bool isRayFacingUp(float angle);
bool isRayFacingRight(float angle);
bool isRayFacingLeft(float angle);

/**
 * struct ray_s - struct for the textures
 * @rayAngle: ray angle
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit x coordinate
 * @distance: ditance to the wall
 * @wasHitVertical: verify hit vertical
 * @wallHitContent: wall hit content
 */
typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

extern bool foundHorzWallHit, foundVertWallHit;
extern float horzWallHitX, horzWallHitY, vertWallHitX, vertWallHitY;
extern int horzWallContent, vertWallContent;

#endif /* RAYCAST_H */
