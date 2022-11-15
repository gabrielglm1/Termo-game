all: teste.o

teste.o: teste.cpp
	g++ -c teste.cpp

clean:
	rm -rf *.o

vai:
	./teste