# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hwy!, I am comment no.2. I want to say that CFLAGS will be the
#options I'll pass to the compiler
CFLAGS=-c -Wall

all:hello

main.o:main.cpp
  $(CC) $(CFLAGS) main.cpp

clean:
  rm -rf *o 

.phony: all clean