CC=g++

all: main

main.o: main.cpp
	$(CC) main.cpp -lncurses -o main
