#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdbool.h>
#include <math.h>
#include "map.h"
#include "player.h"
#include "collision.h"

// Function prototypes
void changeColorIntensity(color_t *color, float factor);
float distanceBetweenPoints(float x1, float y1, float x2, float y2);
void vertIntersection(float rayAngle);
void horzIntersection(float rayAngle);

// Extern declarations
extern bool foundHorzWallHit, foundVertWallHit;
extern float horzWallHitX, horzWallHitY, vertWallHitX, vertWallHitY;
extern int horzWallContent, vertWallContent;

#endif /* UTILITIES_H */
