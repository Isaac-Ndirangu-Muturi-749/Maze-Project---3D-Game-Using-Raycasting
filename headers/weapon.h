#ifndef WEAPON_H
#define WEAPON_H

#include "textures.h" // Assuming you have a textures.h header

#define NUM_WEAPONS 2 // Update this with the number of weapons

typedef struct {
    texture_t texture;
    int width;
    int height;
} weapon_texture_t;

extern weapon_texture_t weaponTextures[NUM_WEAPONS];

void loadWeaponTextures(void);
void freeWeaponTextures(void);

#endif /* WEAPON_H */
