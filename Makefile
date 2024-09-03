CC 	= gcc
CFLAGS	= -Wall -Wextra -Werror -pedantic $(shell sdl2-config --cflags) -Iinc
LDFLAGS	= $(shell sdl2-config --libs) -lSDL2_ttf

TARGET	= maze
SRCDIR	= src
OBJDIR	= obj

SRCS	= maze.c $(wildcard $(SRCDIR)/*.c)
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))


.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR) $(TARGET)
