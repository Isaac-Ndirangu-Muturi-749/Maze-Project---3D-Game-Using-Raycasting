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


