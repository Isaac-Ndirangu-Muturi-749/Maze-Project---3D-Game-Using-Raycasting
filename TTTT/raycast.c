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
