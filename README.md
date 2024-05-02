# Maze Project: 3D Game Using Raycasting

![Maze 3D Game](./images/maze_game_screenshot.png)

### Overview
Welcome to the Maze 3D Game project! This project is a simple 3D maze game built using raycasting techniques. It allows you to navigate through a maze in a first-person perspective, using keyboard controls to move around and explore the environment.

### Project Structure
The project follows a simple directory structure:

- **src**: Contains all the source code files.
- **headers**: Contains header files with function declarations and constants.
- **images**: Holds image assets used in the game.

### Dependencies
This project relies on the following dependencies:
- **SDL2**: A cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware.
- **SDL2_image**: An extension library that enables loading and saving images in various formats.

### Introducing SDL2 and Raycasting for Understanding

`Simple DirectMedia Layer (SDL)` is a cross-platform software development library designed to provide a hardware abstraction layer for computer multimedia hardware components. Software developers can use it to write high-performance computer games and other multimedia applications that can run on many operating systems such as Android, iOS, Linux, macOS, and Windows. SDL manages video, audio, input devices, CD-ROM, threads, shared object loading, networking and timers.

- **SDL2**: SDL2 is a powerful library that simplifies the process of creating graphical applications. It provides functions for handling windows, rendering graphics, and capturing user input.
- **Raycasting**: Raycasting is a rendering technique used to create a 3D perspective effect in 2D environments. It involves casting rays from the player's viewpoint and calculating intersections with objects in the scene to determine what is visible.

### Installing Libraries and Compiling Guide
Before compiling the project, make sure you have SDL2 and SDL2_image installed on your system. You can install them using your package manager:

```bash
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
```

Once the dependencies are installed, you can compile the project using GCC:

```bash
gcc -g src/*.c -lm -lSDL2 -lSDL2_image -o maze_game
```

### Running the Game
After compiling the project, you can run the executable:

```bash
./maze_game
```

### Features Implemented
- First-person perspective navigation.
- Rendering of a 3D maze using raycasting techniques.
- Keyboard controls for movement (WASD for navigation).
- Make it rain (stop / start the rain with SPACEBAR)

### How to Control or Activate Features

- Use the **W** key to move forward.
- Use the **S** key to move backward.
- Use the **A** key to turn left.
- Use the **D** key to turn right.

- Press and hold the **Up Arrow** key to move forward continuously.
- Press and hold the **Down Arrow** key to move backward continuously.
- Press and hold the **Left Arrow** key to turn left continuously.
- Press and hold the **Right Arrow** key to turn right continuously.

- Press the **Spacebar** to toggle rain effects on and off.

## Game Demo

<iframe width="560" height="315" src="https://www.youtube.com/embed/ZXjm-hveqRM?si=wP6MoSgsBu7Igr1Z" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

### About Me
Follow me on Twitter 🐦, connect with me on LinkedIn 🔗, and check out my GitHub 🐙. You won't be disappointed!

👉 Twitter: https://twitter.com/NdiranguMuturi1
👉 LinkedIn: https://www.linkedin.com/in/isaac-muturi-3b6b2b237
👉 GitHub: https://github.com/Isaac-Ndirangu-Muturi-749

So, what are you waiting for? Join me on my tech journey and learn something new today! 🚀🌟

### Thanks
Thank you for checking out the Maze 3D Game project! Feel free to explore the code, make modifications, and have fun navigating through the maze.

**!HAPPY GAMING!**
