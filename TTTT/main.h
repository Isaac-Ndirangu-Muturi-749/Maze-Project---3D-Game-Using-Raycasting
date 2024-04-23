bool initializeWindow(void);
void destroyWindow(void);




#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "upng.h"


/* Constants */

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS SCREEN_WIDTH

#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 8

typedef uint32_t color_t;





#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include "input.h" // Assuming input.h is needed here

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FRAME_TIME_LENGTH 16 // Milliseconds per frame

// Data structures
typedef struct {
    float x;
    float y;
    float width;
    float height;
    int walkDirection;
    float walkSpeed;
    int turnDirection;
    float turnSpeed;
    float rotationAngle;
} player_t;

// Function prototypes
int initializeWindow(void); // Function declaration for initializeWindow
void setup_game(void);
void update_game(void);
void render_game(void);
void destroy_game(void);
void movePlayer(float deltaTime);
void castAllRays(void);
void freeWallTextures(void);
void destroyWindow(void);

// Global variables
extern bool GameRunning;
extern int TicksLastFrame;
extern player_t player;

#endif /* MAIN_H */
