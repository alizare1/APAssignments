CC = g++ -std=c++11

all: 2.out

2.out: main.o file_system_interface.o FileSystem.o Data.o Directory.o File.o Link.o
	$(CC) main.o FileSystem.o file_system_interface.o Data.o Directory.o File.o Link.o -o 2.out

main.o: main.cpp file_system_interface.h FileSystem.h Data.h Directory.h File.h Link.h
	$(CC) -c main.cpp

file_system_interface.o: file_system_interface.h file_system_interface.cpp FileSystem.h
	$(CC) -c file_system_interface.cpp

FileSystem.o: FileSystem.h FileSystem.cpp Data.h Directory.h File.h Link.h
	$(CC) -c FileSystem.cpp

Data.o: Data.h Data.cpp
	$(CC) -c Data.cpp

Directory.o: Directory.h Directory.cpp Data.h
	$(CC) -c Directory.cpp

File.o: File.h File.cpp Data.h Directory.h
	$(CC) -c File.cpp

Link.o: Link.cpp Link.h Data.h Directory.h
	$(CC) -c Link.cpp



.PHONY: clean

clean:
	rm *.o
	rm *.out