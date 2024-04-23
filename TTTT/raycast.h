#ifndef RAYCAST_H
#define RAYCAST_H

#include <stdbool.h>
#include <math.h>
#include <float.h>

#define NUM_RAYS 100
#define TWO_PI (2 * M_PI)
#define PI M_PI
#define PROJ_PLANE (NUM_COLS / 2 * tan(FOV_ANGLE / 2))

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

#endif /* RAYCAST_H */
