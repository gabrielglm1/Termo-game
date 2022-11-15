CC=g++
gcc -W -Wall -Werror -Wextra -I./Includes/. -o Sources/NCurses/ncurses_init.o -c Sources/NCurses/ncurses_init.c -lncurses

all: main

main.o: main.cpp
	$(CC) main.cpp -lncurses -o main
