#ifndef RAYS_H
#define RAYS_H

#include <stdbool.h>
#include <math.h>
#include <float.h>

#include "map.h"
#include "window.h"
#include "collision.h"
#include "draw.h"
#include "player.h"


#define NUM_RAYS WINDOW_WIDTH
#define PI 3.14159265
#define TWO_PI 6.28318530
#define FOV_ANGLE (60 * (PI / 180))
#define PROJECTION_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2))

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


// Function prototypes
void castRay(float rayAngle, int stripId);
void castAllRays(void);
float distanceBetweenPoints(float x1, float y1, float x2, float y2);

void renderRays(void);

void vertIntersection(float rayAngle);
void horzIntersection(float rayAngle);

bool isRayFacingDown(float angle);
bool isRayFacingUp(float angle);
bool isRayFacingRight(float angle);
bool isRayFacingLeft(float angle);


extern ray_t rays[NUM_RAYS];

#endif /* RAYS_H */
