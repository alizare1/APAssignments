CC = g++ -std=c++11

all: 1.out

1.out: main.o shape.o sphere.o
	$(CC) main.o shape.o sphere.o -o 1.out

main.o: main.cpp shape.h sphere.h
	$(CC) -c main.cpp

shape.o: shape.h shape.cpp
	$(CC) -c shape.cpp

sphere.o: sphere.h sphere.cpp shape.h
	$(CC) -c sphere.cpp


.PHONY: clean

clean:
	rm *.o
	rm *.out