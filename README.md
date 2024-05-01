# Maze-Project---3D-Game-Using-Raycasting

To set up the dimensions and parameters for the projection plane in a raycasting application, follow these steps:

1. **Dimension of the Projection Plane**: Set the width and height of the projection plane. In this case, the width is 320 units and the height is 200 units.

2. **Center of the Projection Plane**: Determine the center coordinates of the projection plane. For example, if the width is 320 units and the height is 200 units, the center would be at coordinates (160, 100).

3. **Distance to the Projection Plane**: Define the distance from the player's viewpoint (camera) to the projection plane. In this case, the distance is 277 units.

4. **Angle between Subsequent Rays**: Calculate the angle between each subsequent ray cast from the camera. Since the projection plane has a width of 320 units and an angle of view of 60 degrees, the angle between each subsequent ray can be calculated as 60 degrees divided by 320 (the number of horizontal units). This angle will determine the field of view and the accuracy of the raycasting.

Here's a summary of the parameters:

- Dimension of the Projection Plane: 320 x 200 units
- Center of the Projection Plane: (160, 100)
- Distance to the Projection Plane: 277 units
- Angle between subsequent rays: 60/320 degrees

With these parameters, you can set up the projection plane in your raycasting application and cast rays to simulate the 3D environment. Adjusting these parameters will affect the field of view, resolution, and perspective of the rendered scene.


Sure, let's start by organizing the code into separate modules. We'll create header files for declarations and source files for implementations. Here's a breakdown of how we can organize the code:

1. **player.c** and **player.h**: These files will contain the code related to player movement and properties.

2. **raycasting.c** and **raycasting.h**: Here, we'll put the functions related to ray casting, such as casting rays, finding intersections, and rendering walls.

3. **input.c** and **input.h**: This module will handle input processing, including keyboard events.

4. **map.c** and **map.h**: Functions for map rendering and collision detection will reside here.

5. **textures.c** and **textures.h**: Manage the loading and freeing of textures.

6. **window.c** and **window.h**: Code for window initialization, destruction, and color buffer management will be placed here.

7. **utilities.c** and **utilities.h**: This module will contain helper functions like drawing lines, rectangles, and calculating distances.

8. **main.c**: The main function will stay here, orchestrating the game loop.

Let's start by creating header files for each module and move the function prototypes accordingly. Then, we'll create the corresponding source files and implement the functions. Does that sound good?



$ gcc -g src/*.c headers/*.h -lm -lSDL2


The `window.h` header file contains functions for initializing and destroying the SDL window used to display the maze game.

Here's a summary of each function:

1. **initializeWindow**: This function initializes the SDL window, renderer, color buffer, and color buffer texture. It first initializes SDL and creates a window with the specified dimensions. Then, it creates a renderer for the window and sets the render draw blend mode to blend. After that, it allocates memory for the color buffer and creates an SDL texture to display the color buffer.

2. **destroyWindow**: This function is responsible for cleaning up resources used by the window when the game is over. It frees the memory allocated for the color buffer, destroys the color buffer texture, renderer, and window, and finally quits SDL.

These functions ensure proper initialization and cleanup of SDL resources related to window management. If you have any questions or need further clarification, feel free to ask!


The `utilities.h` file contains two utility functions used in the game:

1. **changeColorIntensity**: This function adjusts the intensity of a color based on a given factor between 0 and 1. It takes a pointer to a color (`color_t`) and a factor value. It decomposes the color into its RGBA components, multiplies each component by the factor, and then reassembles the color. This allows for adjusting the brightness of a color.

2. **distanceBetweenPoints**: This function calculates the Euclidean distance between two points in 2D space. Given the coordinates of two points `(x1, y1)` and `(x2, y2)`, it computes the distance using the distance formula `sqrt((x2 - x1)^2 + (y2 - y1)^2)`.

These utility functions are essential for various tasks within the game, such as adjusting color intensity and calculating distances between points. If you have any questions or need further explanation, feel free to ask!



The `textures.c` file contains functions related to loading and freeing texture resources for walls in the game. Let's break down each function:

1. **WallTexturesready**: This function loads texture files from disk and prepares them for rendering. It iterates over the array of texture file names, loads each texture using the UPNG library, and stores the texture information in the `wallTextures` array. For each texture, it stores the UPNG texture object, width, height, and texture buffer containing pixel data.

2. **freeWallTextures**: This function frees the memory allocated for the wall textures. It iterates over the `wallTextures` array and frees the UPNG texture object for each texture.

These functions are crucial for loading textures and preparing them for rendering on walls in the game. If you have any questions or need further clarification on any part, feel free to ask!



Your `render.c` file contains functions responsible for rendering the game scene onto the screen. Here's an overview of each function:

1. **render_game**: This function is the entry point for rendering the game scene. It calls other rendering functions in the appropriate order to render walls, the map, rays, and the player onto the screen.

2. **renderColorBuffer**: This function updates the color buffer texture with the contents of the color buffer array and renders it onto the screen using SDL functions.

3. **clearColorBuffer**: This function clears the color buffer by setting all pixels to a specified color.

4. **renderMap**: This function renders the game map onto the screen. It iterates over each tile in the map, determines its color based on the map value, and draws a rectangle representing the tile.

5. **renderRays**: This function renders the rays onto the screen. It draws lines from the player's position to the wall hit points of selected rays. This visualization helps debug raycasting.

6. **renderPlayer**: This function renders the player's position onto the screen. It draws a rectangle representing the player at its current position.

7. **renderFloor**: This function renders the floor projection based on the raycasting results. It calculates the floor texture coordinates for each pixel and draws the corresponding texel onto the screen.

8. **renderCeil**: This function renders the ceiling projection based on the raycasting results. Similar to `renderFloor`, it calculates the ceiling texture coordinates for each pixel and draws the corresponding texel onto the screen.

9. **renderWall**: This function renders the wall projection based on the raycasting results. It calculates the height of the wall strip, determines the texture offset for the wall texture, and draws each texel onto the screen for the wall strip.

These functions work together to render the game scene, including walls, the map, rays, and the player, providing visual feedback to the player and enhancing the gaming experience. If you have any questions or need further clarification on any part, feel free to ask!






Your `raycast.c` file contains functions responsible for casting rays in the game world to detect intersections with walls. Here's an overview of the functions and their roles:

1. **castRay**: This function casts a single ray given its angle (`rayAngle`) and the identifier of the ray strip (`stripId`). It determines whether the ray intersects with a horizontal or vertical wall, calculates the distances to those intersections, and updates the ray's properties accordingly.

2. **castAllRays**: This function casts rays for the entire field of view. It iterates over all the ray strips and calculates the angle of each ray relative to the player's viewing direction. Then, it calls `castRay` for each ray.

3. **isRayFacingDown, isRayFacingUp, isRayFacingRight, isRayFacingLeft**: These functions determine the direction in which a ray is facing based on its angle. They are used in the ray intersection calculations to determine the step direction for traversing the grid.

4. **vertIntersection, horzIntersection**: These functions handle the vertical and horizontal intersections of rays with walls, respectively. They calculate the coordinates of the potential intersection points and step through the grid to find the actual intersection points. They also handle collision detection with map boundaries.

Overall, these functions work together to cast rays and detect intersections with walls, providing the foundation for implementing raycasting rendering in your game. If you have any questions or need further clarification on any part, feel free to ask!






The `movePlayer` function in your `player.c` file is responsible for updating the position of the player based on the current direction and speed of movement. Here's a breakdown of how it works:

1. **Calculating Movement Step**:
   - The function calculates the distance the player should move in each frame based on the current movement speed (`player.walkSpeed`) and the elapsed time since the last frame (`DeltaTime`).

2. **Calculating New Position**:
   - Using trigonometric functions (`cos` and `sin`), the function calculates the new position (`newPlayerX` and `newPlayerY`) of the player based on the current rotation angle (`player.rotationAngle`) and the calculated movement step.

3. **Collision Detection**:
   - The function checks if the new position of the player would result in a collision with any obstacles on the map using the `DetectCollision` function.
   - If no collision is detected (`!DetectCollision`), the player's position is updated to the new position (`newPlayerX` and `newPlayerY`).

Overall, this function handles the movement of the player in the game world, ensuring that the player moves smoothly without intersecting with any obstacles. If you have any further questions or need additional assistance, feel free to ask!




Your `map.c` file contains functions related to the game map. Here's an overview:

1. **`map` Array**:
   - This array represents the game map, where each element corresponds to a specific tile in the game world.
   - Each tile is represented by an integer value, where different values may indicate different types of tiles or objects in the game.

2. **`isInsideMap` Function**:
   - This function checks if a given coordinate `(x, y)` is within the bounds of the map.
   - It returns `true` if the coordinates are within the map boundaries and `false` otherwise.

3. **`getMapValue` Function**:
   - This function retrieves the value of a specific tile in the map, given its row and column indices.
   - It returns the value of the tile at the specified position in the map array.

Overall, your `map.c` file provides basic functionality to interact with the game map, including boundary checking and retrieving tile values. It's essential for managing the game world and handling collisions and interactions with the environment. If you have any specific questions or need further assistance with this code, feel free to ask!





Your main function and game setup functions look solid. Here's a brief overview:

1. **Main Function (`main`)**:
   - Initializes the game window.
   - Calls `setup_game()` to initialize player variables and load wall textures.
   - Enters the game loop, where it continuously:
     - Handles input.
     - Updates the game state.
     - Renders the game.
   - Exits the game loop when `GameRunning` is set to false.
   - Calls `destroy_game()` to free wall textures and destroy the window before exiting.

2. **Game Setup Function (`setup_game`)**:
   - Initializes player variables such as position, size, and movement speed.
   - Calls `WallTexturesready()` to load wall textures.

3. **Update Game Function (`update_game`)**:
   - Calculates the delta time to ensure smooth movement regardless of frame rate.
   - Updates the player's movement based on input and delta time.
   - Calls `castAllRays()` to perform ray casting for rendering.

4. **Destroy Game Function (`destroy_game`)**:
   - Frees wall textures.
   - Destroys the game window.

Overall, your game loop structure and setup functions seem well-organized and clear. Remember to handle error cases gracefully and ensure proper resource management throughout your game's development. If you encounter any specific issues or have further questions, feel free to ask!





Your code handles keyboard input using SDL events. Here's a breakdown of the functions:

1. `handleInput`: This function polls for SDL events and processes them. If the event is a quit event (`SDL_QUIT`), it sets `GameRunning` to false, indicating that the game should stop. If the event is a key press (`SDL_KEYDOWN`), it calls `SDL_KEYDOWN_FUNC` to handle the key press. If the event is a key release (`SDL_KEYUP`), it calls `SDL_KEYUP_FUNC` to handle the key release.

2. `SDL_KEYDOWN_FUNC`: This function handles key presses. It checks which key was pressed using `event.key.keysym.sym` and sets the player's walk and turn directions accordingly. For example, pressing the up arrow key or 'w' key sets the walk direction to +1, indicating forward movement.

3. `SDL_KEYUP_FUNC`: This function handles key releases. It checks which key was released and sets the corresponding player direction to 0, indicating no movement in that direction.

These functions effectively map keyboard input to player movement in the game. However, you may want to add additional error checking to ensure that `player.walkDirection` and `player.turnDirection` are properly handled within the game loop and that they do not exceed predefined limits. Additionally, you might consider adding support for other keys or input devices depending on your game's requirements.




Your code defines functions for drawing pixels, lines, and rectangles. Here's a summary of each function:

1. `drawPixel`: This function assigns a color to a specific pixel at coordinates `(x, y)` on the screen.

2. `drawLine`: This function draws a line from `(x0, y0)` to `(x1, y1)` using Bresenham's line drawing algorithm. It calculates the incremental changes in x and y and then iterates over the longest side of the line, drawing pixels along the way.

3. `drawRect`: This function draws a rectangle with the top-left corner at `(x, y)`, the specified `width`, and `height`. It iterates over each pixel within the rectangle and sets its color.

These functions seem well-defined for basic 2D drawing operations. However, it's essential to ensure that the `drawPixel` function correctly accesses the `colorBuffer` array and that it handles out-of-bounds coordinates properly to avoid memory access violations. Additionally, you might want to consider using more efficient algorithms for line drawing, especially if you're dealing with larger images or complex scenes.




Your `DetectCollision` function appears to check for collisions with the game map based on the player's next coordinates (`x` and `y`). Here's a breakdown of what it does:

1. It first checks if the next coordinates are outside the boundaries of the map. If so, it returns `true` to indicate a collision.

2. Then, it calculates the grid coordinates (`mapGridX` and `mapGridY`) corresponding to the player's next position on the map.

3. Finally, it checks if the tile at the calculated grid coordinates on the map is a wall (`map[mapGridY][mapGridX] != 0`). If it is, it returns `true` to indicate a collision.

This function seems fine at a glance. However, ensure that the `map` array is correctly defined and initialized elsewhere in your code, and that the constants `MAP_NUM_COLS` and `MAP_NUM_ROWS` are accurate representations of your map's dimensions.

If you're encountering issues with collisions, you might want to inspect how the player's coordinates are updated and whether they're being passed correctly to this function. Additionally, debugging collision detection using print statements or a debugger like `gdb` can help identify any issues in the logic or data being used.






gcc src/*.c -lm -lSDL2 -lSDL2_image
