#!/usr/bin/make -f
CC = g++
CFLAGS  = -Wall -g -O3
PROG = Breakout

SRCS = ./src/main.cpp ./src/Game.cpp ./src/Paddle.cpp

LIBS = -lglfw -lGLC -lGLU -lGL -lpng

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG) 

