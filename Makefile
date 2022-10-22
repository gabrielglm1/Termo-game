CC=g++
CFLAGS=-std=c++14 -Wall -Iinclude/

all: main

main: main.cpp
	$(CC) main.cpp -lncurses -o main