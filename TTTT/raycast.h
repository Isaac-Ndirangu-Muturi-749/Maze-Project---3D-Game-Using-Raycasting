#ifndef RAYCAST_H
#define RAYCAST_H

// Function prototypes
void castRays();

#endif /* RAYCAST_H */



/* Functions-variables-structs for ray */

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

float distanceBetweenPoints(float x1, float y1, float x2, float y2);
bool isRayFacingUp(float angle);
bool isRayFacingDown(float angle);
bool isRayFacingLeft(float angle);
bool isRayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderRays(void);
void horzIntersection(float rayAngle);
void vertIntersection(float rayAngle);
