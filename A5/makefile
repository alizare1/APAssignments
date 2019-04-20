FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: game.out

game.out: Game.o Map.o main.o Mario.o NormalBlock.o Flag.o Objects.o Pipe.o
	g++ Game.o Map.o main.o Mario.o NormalBlock.o Flag.o Objects.o Pipe.o rsdl.cpp $(FLAGS) -o game.out

main.o: Game.h main.cpp
	g++ -c main.cpp 

Game.o: Game.cpp Game.h Map.h Objects.h
	g++ -c Game.cpp $(FLAGS)

Map.o: Map.h Map.cpp Game.h Objects.h Mario.h
	g++ -c Map.cpp $(FLAGS)

Mario.o: Mario.h Mario.cpp
	g++ -c Mario.cpp $(FLAGS)

NormalBlock.o: NormalBlock.h NormalBlock.cpp
	g++ -c NormalBlock.cpp $(FLAGS)

Flag.o: Flag.h Flag.cpp
	g++ -c Flag.cpp $(FLAGS)

Objects.o: Objects.h Objects.cpp Flag.h Pipe.h NormalBlock.h
	g++ -c Objects.cpp 

Pipe.o: Pipe.h Pipe.cpp 
	g++ -c Pipe.cpp $(FLAGS)

.PHONY: clean

clean: 
	rm *.o

