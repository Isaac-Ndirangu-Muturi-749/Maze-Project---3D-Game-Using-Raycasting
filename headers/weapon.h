#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL_image.h>

#include "upng.h"
#include "main.h"
#include "window.h"

#define NUM_WEAPONS 1

void loadWeaponTextures(void);
void freeWeaponTextures(void);
void renderWeapon(void);

#endif /* TEXTURES_H */
