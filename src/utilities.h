#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#include "map.h"
#include "player.h"
#include "collision.h"
#include "raycast.h"
#include "main.h"

#include <stdint.h>

typedef uint32_t color_t;

// Function prototypes
void changeColorIntensity(color_t *color, float factor);
float distanceBetweenPoints(float x1, float y1, float x2, float y2);
void vertIntersection(float rayAngle);
void horzIntersection(float rayAngle);

// Extern declarations


#endif /* UTILITIES_H */
