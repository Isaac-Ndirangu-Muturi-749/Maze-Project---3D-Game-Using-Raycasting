#ifndef RAIN_H
#define RAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "main.h"

#define MAX_RAIN_DROPS 1000

typedef struct {
    float x, y;     // Position
    float velocity; // Speed
} Raindrop;

extern Raindrop raindrops[MAX_RAIN_DROPS];
extern bool isRaining;

void initializeRaindrops(void);
void updateRaindrops(void);
void renderRaindrops(void);

#endif /* RAIN_H */
