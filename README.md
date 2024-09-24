# Portfolio project: The Maze project

This game uses Ray casting to render 2D textures: walls, floor, ceiling; into a 3D world, where the user controls the player i.e. the camera to navigate through the maze

## Tools and APIs:

### SDL2:

SDL2 is most cross-platfrom used library for game developements, it's designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

### UPNG:

`upng` is a lightweight, fast, and simple PNG encoder and decoder library written in C. It is designed to be easy to use and integrate into various projects, providing a straightforward way to handle PNG images. The library is particularly useful for applications that require efficient PNG image processing without the overhead of more complex libraries.

`upng` is used instead of `SDL2_image` for lightweight, and fast use.

## Compilation

### CMAKE:

in unix systems: Linux, and MacOs, you need only to download either the binary files of SDL2 library, or compile, following this link <a href="https://wiki.libsdl.org/SDL2/SourceCode"></a>

copy past:

```
mkdir build && cd build && cmake .. && make
```

### Makefile:

Only in Linux machines i.e. Ubuntu:

```
make build && make run
```

or:

```
gcc -Wall -Wextra -Werror -pedantic -lm src/*c -Iinclude/ -o Maze `sdl2-config --cflags` `sdl2-config --libs`
```
