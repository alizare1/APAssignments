all: Scheduler.out

Scheduler.out: main.o Core.o CPU.o Process.o Thread.o
	g++ -o Scheduler.out main.o Core.o CPU.o Process.o Thread.o
main.o: main.cpp Core.h CPU.h Process.h Thread.h
	g++ -c main.cpp
CPU.o: CPU.cpp CPU.h Core.h Thread.h
	g++ -c CPU.cpp
Core.o: Core.cpp Core.h
	g++ -c Core.cpp
Process.o: Process.cpp Process.h CPU.h Thread.h
	g++ -c Process.cpp
Thread.o: Thread.cpp Thread.h
	g++ -c Thread.cpp

.PHONY: clean
clean:
	rm *.o
	rm Scheduler.out
