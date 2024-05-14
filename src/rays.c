#include "../headers/rays.h"

// Array to store information about each ray
ray_t rays[NUM_RAYS];

// Variables to track if wall hits are found and their positions
static bool foundHorzWallHit, foundVertWallHit;
static float horzWallHitX, horzWallHitY, vertWallHitX, vertWallHitY;
static int horzWallContent, vertWallContent;

// Function to cast a single ray
void castRay(float rayAngle, int stripId) {
    // Normalize ray angle to be within [0, 2*PI)
    rayAngle = fmodf(rayAngle, TWO_PI);
    if (rayAngle < 0)
        rayAngle = TWO_PI + rayAngle;

    // Cast rays horizontally and vertically to find intersections
    horzIntersection(rayAngle);
    vertIntersection(rayAngle);

    // Calculate distances to wall hits
    float horzHitDistance = foundHorzWallHit
                                ? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY)
                                : FLT_MAX;
    float vertHitDistance = foundVertWallHit
                                ? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY)
                                : FLT_MAX;

    // Store ray information based on which wall hit is closer
    if (vertHitDistance < horzHitDistance) {
        rays[stripId] = (ray_t){
            .distance = vertHitDistance,
            .wallHitX = vertWallHitX,
            .wallHitY = vertWallHitY,
            .wallHitContent = vertWallContent,
            .wasHitVertical = true,
            .rayAngle = rayAngle
        };
    } else {
        rays[stripId] = (ray_t){
            .distance = horzHitDistance,
            .wallHitX = horzWallHitX,
            .wallHitY = horzWallHitY,
            .wallHitContent = horzWallContent,
            .wasHitVertical = false,
            .rayAngle = rayAngle
        };
    }
}

// Function to cast all rays
void castAllRays(void) {
    // Loop through each column and cast a ray
    for (int col = 0; col < NUM_RAYS; col++) {
        // Calculate ray angle for current column
        float rayAngle = player.rotationAngle + atan((col - NUM_RAYS / 2) / PROJECTION_PLANE);
        // Cast the ray and store the result
        castRay(rayAngle, col);
    }
}



/**
 * distanceBetweenPoints - Finds horizontal intersection with the wall
 * @x1: x coordinate of the starting point
 * @y1: y coordinate oh the starting point
 * @x2: x coordinate of the end point
 * @y2: y coordinate of the end point
 * Return: the distance between two points
 */
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

/**
 * renderRays - draw all the rays
 *
 */
void renderRays(void)
{
	int i;

	for (i = 0; i < NUM_RAYS; i += 50)
	{
		drawLine(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			rays[i].wallHitX * MINIMAP_SCALE_FACTOR,
			rays[i].wallHitY * MINIMAP_SCALE_FACTOR,
			0xFF0000FF
		);
	}
}


/**
 * vertIntersection - Finds vertical intersection with the wall
 * @rayAngle: current ray angle
 *
 */
void vertIntersection(float rayAngle) {
    float nextVertTouchX, nextVertTouchY, xintercept, yintercept, xstep, ystep;

    foundVertWallHit = false;
    vertWallHitX = vertWallHitY = vertWallContent = 0;

    calculateVerticalIntercept(rayAngle, &xintercept, &yintercept, &xstep, &ystep);

    nextVertTouchX = xintercept;
    nextVertTouchY = yintercept;

    while (isInsideMap(nextVertTouchX, nextVertTouchY)) {
        if (checkVerticalWallCollision(nextVertTouchX, nextVertTouchY, rayAngle)) {
            foundVertWallHit = true;
            break;
        }
        nextVertTouchX += xstep;
        nextVertTouchY += ystep;
    }
}


/**
 * horzIntersection - Finds horizontal intersection with the wall
 * @rayAngle: current ray angle
 *
 */
void horzIntersection(float rayAngle) {
    float nextHorzTouchX, nextHorzTouchY, xintercept, yintercept, xstep, ystep;

    foundHorzWallHit = false;
    horzWallHitX = horzWallHitY = horzWallContent = 0;

    calculateHorizontalIntercept(rayAngle, &xintercept, &yintercept, &xstep, &ystep);

    nextHorzTouchX = xintercept;
    nextHorzTouchY = yintercept;

    while (isInsideMap(nextHorzTouchX, nextHorzTouchY)) {
        if (checkHorizontalWallCollision(nextHorzTouchX, nextHorzTouchY, rayAngle)) {
            foundHorzWallHit = true;
            break;
        }
        nextHorzTouchX += xstep;
        nextHorzTouchY += ystep;
    }
}



/**
 * isRayFacingDown - check if the ray is facing down
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}


/**
 * isRayFacingUp - check if the ray is facing up
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}


/**
 * isRayFacingRight - check if the ray is facing to the right
 * @angle: current ray angle
 * Return: true or false
 */
bool isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}


/**
 * isRayFacingLeft - check if the ray is facing to the right
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}


void calculateHorizontalIntercept(float rayAngle, float *xintercept, float *yintercept, float *xstep, float *ystep) {
    *yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
    *yintercept += isRayFacingDown(rayAngle) ? TILE_SIZE : 0;

    *xintercept = player.x + (*yintercept - player.y) / tan(rayAngle);

    *ystep = TILE_SIZE;
    *ystep *= isRayFacingUp(rayAngle) ? -1 : 1;
    *xstep = TILE_SIZE / tan(rayAngle);
    *xstep *= (isRayFacingLeft(rayAngle) && *xstep > 0) ? -1 : 1;
    *xstep *= (isRayFacingRight(rayAngle) && *xstep < 0) ? -1 : 1;
}

bool checkHorizontalWallCollision(float xToCheck, float yToCheck, float rayAngle) {
    float wallX = xToCheck;
    float wallY = yToCheck + (isRayFacingUp(rayAngle) ? -1 : 0);

    if (DetectCollision(wallX, wallY)) {
        horzWallHitX = xToCheck;
        horzWallHitY = yToCheck;
        horzWallContent = getMapValue((int)floor(wallY / TILE_SIZE), (int)floor(wallX / TILE_SIZE));
        return true;
    }
    return false;
}


void calculateVerticalIntercept(float rayAngle, float *xintercept, float *yintercept, float *xstep, float *ystep) {
    *xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
    *xintercept += isRayFacingRight(rayAngle) ? TILE_SIZE : 0;
    *yintercept = player.y + (*xintercept - player.x) * tan(rayAngle);

    *xstep = TILE_SIZE;
    *xstep *= isRayFacingLeft(rayAngle) ? -1 : 1;
    *ystep = TILE_SIZE * tan(rayAngle);
    *ystep *= (isRayFacingUp(rayAngle) && *ystep > 0) ? -1 : 1;
    *ystep *= (isRayFacingDown(rayAngle) && *ystep < 0) ? -1 : 1;
}


bool checkVerticalWallCollision(float xToCheck, float yToCheck, float rayAngle) {
    float wallX = xToCheck + (isRayFacingLeft(rayAngle) ? -1 : 0);
    float wallY = yToCheck;

    if (DetectCollision(wallX, wallY)) {
        vertWallHitX = xToCheck;
        vertWallHitY = yToCheck;
        vertWallContent = getMapValue((int)floor(wallY / TILE_SIZE), (int)floor(wallX / TILE_SIZE));
        return true;
    }
    return false;
}
