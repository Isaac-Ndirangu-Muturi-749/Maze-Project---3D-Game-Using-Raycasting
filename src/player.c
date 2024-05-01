#include "../headers/player.h"

player_t player;

void initializePlayer(void) {
    player.x = WINDOW_WIDTH / 2;
    player.y = WINDOW_HEIGHT / 2;
    player.width = 1;
    player.height = 30;
    player.walkDirection = 0;
    player.walkSpeed = 100;
    player.turnDirection = 0;
    player.turnSpeed = 45 * (PI / 180);
    player.rotationAngle = PI / 2;
}


/**
 * renderPlayer - render the player
 *
*/
void renderPlayer(void)
{
	drawRect(
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF
	);
}


/**
 * movePlayer - set the next position of the player
 * @DeltaTime: time elapsed since the last frame
*/
void movePlayer(float DeltaTime)
{
	float moveStep, newPlayerX, newPlayerY;

	player.rotationAngle += player.turnDirection * player.turnSpeed * DeltaTime;
	moveStep = player.walkDirection * player.walkSpeed * DeltaTime;

	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

	if (!DetectCollision(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}
