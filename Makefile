CC			= gcc
ALLFLAGS	= -Wall -Wextra -Werror -pedantic ./src/*.c -lm -Iinclude/ -o maze `sdl2-config --cflags` `sdl2-config --libs`

.PHONY: build run

build:
	${CC} ${ALLFLAGS}

run:
	./maze