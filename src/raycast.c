#include "raycast.h"

ray_t rays[NUM_RAYS];

static bool foundHorzWallHit, foundVertWallHit;
static float horzWallHitX, horzWallHitY, vertWallHitX, vertWallHitY;
static int horzWallContent, vertWallContent;

/**
 * castRay - casting of each ray
 * @rayAngle: current ray angle
 * @stripId: ray strip identifier
 */
void castRay(float rayAngle, int stripId)
{
	float horzHitDistance, vertHitDistance;

	rayAngle = remainder(rayAngle, TWO_PI);
	if (rayAngle < 0)
		rayAngle = TWO_PI + rayAngle;

	horzIntersection(rayAngle);

	vertIntersection(rayAngle);

	horzHitDistance = foundHorzWallHit
		? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY)
		: FLT_MAX;
	vertHitDistance = foundVertWallHit
		? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY)
		: FLT_MAX;

	if (vertHitDistance < horzHitDistance)
	{
		rays[stripId].distance = vertHitDistance;
		rays[stripId].wallHitX = vertWallHitX;
		rays[stripId].wallHitY = vertWallHitY;
		rays[stripId].wallHitContent = vertWallContent;
		rays[stripId].wasHitVertical = true;
		rays[stripId].rayAngle = rayAngle;
	}
	else
	{
		rays[stripId].distance = horzHitDistance;
		rays[stripId].wallHitX = horzWallHitX;
		rays[stripId].wallHitY = horzWallHitY;
		rays[stripId].wallHitContent = horzWallContent;
		rays[stripId].wasHitVertical = false;
		rays[stripId].rayAngle = rayAngle;
	}

}


/**
 * castAllRays - cast of all rays
 *
 */

void castAllRays(void)
{
	int col;

	for (col = 0; col < NUM_RAYS; col++)
	{
		float rayAngle = player.rotationAngle +
							atan((col - NUM_RAYS / 2) / PROJ_PLANE);
		castRay(rayAngle, col);
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



/**
 * vertIntersection - Finds vertical intersection with the wall
 * @rayAngle: current ray angle
 *
 */
void vertIntersection(float rayAngle)
{
	float nextVertTouchX, nextVertTouchY;
	float xintercept, yintercept, xstep, ystep;

	foundVertWallHit = false;
	vertWallHitX = 0;
	vertWallHitY = 0;
	vertWallContent = 0;

	xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += isRayFacingRight(rayAngle) ? TILE_SIZE : 0;
	yintercept = player.y + (xintercept - player.x) * tan(rayAngle);

	xstep = TILE_SIZE;
	xstep *= isRayFacingLeft(rayAngle) ? -1 : 1;
	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (isRayFacingUp(rayAngle) && ystep > 0) ? -1 : 1;
	ystep *= (isRayFacingDown(rayAngle) && ystep < 0) ? -1 : 1;
	nextVertTouchX = xintercept;
	nextVertTouchY = yintercept;

	while (isInsideMap(nextVertTouchX, nextVertTouchY))
	{
		float xToCheck = nextVertTouchX + (isRayFacingLeft(rayAngle) ? -1 : 0);
		float yToCheck = nextVertTouchY;

		if (DetectCollision(xToCheck, yToCheck))
		{
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			vertWallContent = getMapValue((int)floor(yToCheck / TILE_SIZE),
									   (int)floor(xToCheck / TILE_SIZE));
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
void horzIntersection(float rayAngle)
{
	float nextHorzTouchX, nextHorzTouchY, xintercept, yintercept, xstep, ystep;

	foundHorzWallHit = false;
	horzWallHitX = horzWallHitY = horzWallContent = 0;

	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += isRayFacingDown(rayAngle) ? TILE_SIZE : 0;

	xintercept = player.x + (yintercept - player.y) / tan(rayAngle);

	ystep = TILE_SIZE;
	ystep *= isRayFacingUp(rayAngle) ? -1 : 1;
	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (isRayFacingLeft(rayAngle) && xstep > 0) ? -1 : 1;
	xstep *= (isRayFacingRight(rayAngle) && xstep < 0) ? -1 : 1;
	nextHorzTouchX = xintercept;
	nextHorzTouchY = yintercept;

	while (isInsideMap(nextHorzTouchX, nextHorzTouchY))
	{
		float xToCheck = nextHorzTouchX;
		float yToCheck = nextHorzTouchY + (isRayFacingUp(rayAngle) ? -1 : 0);

		if (DetectCollision(xToCheck, yToCheck))
		{
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = getMapValue((int)floor(yToCheck / TILE_SIZE),
									   (int)floor(xToCheck / TILE_SIZE));
			foundHorzWallHit = true;
			break;
		}
		nextHorzTouchX += xstep;
		nextHorzTouchY += ystep;
	}
}
