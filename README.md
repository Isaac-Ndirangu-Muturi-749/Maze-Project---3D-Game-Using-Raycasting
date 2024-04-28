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
