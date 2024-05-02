### README.md for C Files

This repository contains several C files, each corresponding to a header file, contributing to the implementation of a Maze 3D Game using raycasting. Below is a summary of each file:

#### main.c
- **Purpose**: Entry point of the program and orchestrates the game loop.
- **Functions**: `main`, `setupGame`, `updateGame`, `renderGame`, `destroyGame`.

#### window.h
- **Purpose**: Manages window initialization and destruction using SDL.
- **Functions**: `initializeWindow`, `destroyWindow`.

#### input.c
- **Purpose**: Handles user input, including keyboard events.
- **Functions**: `handleInput`, `handleKeyDown`, `handleKeyUp`.

#### walls.c
- **Purpose**: Handles rendering walls and managing wall textures.
- **Functions**: `loadWallTextures`, `freeWallTextures`, `renderWalls`, `changeColorIntensity`.

#### floor.c
- **Purpose**: Handles rendering the floor projection and managing floor textures.
- **Functions**: `loadFloorTextures`, `freeFloorTextures`, `renderFloor`.

#### ceiling.c
- **Purpose**: Handles rendering the ceiling projection and managing ceiling textures.
- **Functions**: `loadCeilingTextures`, `freeCeilingTextures`, `renderCeiling`.

#### color_buffer.c
- **Purpose**: Manages the color buffer for rendering.
- **Functions**: `clearColorBuffer`, `renderColorBuffer`.

#### draw.c
- **Purpose**: Provides drawing functions like drawing pixels, lines, and rectangles.
- **Functions**: `drawPixel`, `drawLine`, `drawRect`.

#### player.c
- **Purpose**: Manages the player's position, movement, and rotation.
- **Functions**: `initializePlayer`, `renderPlayer`, `movePlayer`.

#### rays.c
- **Purpose**: Handles raycasting for rendering 3D environments in 2D. These functions work together to cast rays, detect intersections with walls, and calculate distances, allowing for accurate rendering of the game environment.
- **Functions**: `castRay`, `castAllRays`, `distanceBetweenPoints`, `renderRays`, `vertIntersection`, `horzIntersection`, `isRayFacingDown`, `isRayFacingUp`, `isRayFacingRight`, `isRayFacingLeft`.

#### rain.c
- **Purpose**: Manages rendering raindrops and updating their positions.
- **Functions**: `initializeRaindrops`, `updateRaindrops`, `renderRaindrops`.

#### upng.h
- **Purpose**: Provides functionality for handling PNG image files.
- **Functions**: Various functions for loading PNG images.

#### collision.h
- **Purpose**: Provides collision detection functionality.
- **Functions**: `DetectCollision`.

#### map.h
- **Purpose**: Handles rendering and managing the game map.
- **Functions**: `isInsideMap`, `getMapValue`, `renderMap`.

#### weapon.h
- **Purpose**: Manages weapon textures and rendering.
- **Functions**: `loadWeaponTextures`, `freeWeaponTextures`, `renderWeapon`.

Feel free to explore and contribute to this Maze 3D Game project! If you have any questions or suggestions, please don't hesitate to reach out. Happy coding!
