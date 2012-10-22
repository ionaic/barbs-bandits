CC=g++
CFLAGS+=-g -Wall -Wextra
LDFLAGS+=-lGL -lGLEW -lglfw -lIL -lILU -lILUT
INCLUDEFLAGS=-I/usr/include/eigen3
CFILES=*.cpp resman/*.cpp
OFILES=*.o resman/*.o
NAME=OpenGL_Viewer

all:
	$(CC) $(CFLAGS) $(INCLUDEFLAGS) $(LDFLAGS) -o $(NAME) $(CFILES)