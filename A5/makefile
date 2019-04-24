FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: game.out

game.out: Game.o Map.o main.o Mario.o QuestionBlock.o NormalBlock.o Flag.o Objects.o Pipe.o
	g++ Game.o Map.o main.o Mario.o QuestionBlock.o NormalBlock.o Flag.o Objects.o Pipe.o rsdl.cpp $(FLAGS) -o game.out

main.o: Game.h main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h Map.h Objects.h blockSize.h
	g++ -c Game.cpp $(FLAGS)

Map.o: Map.h Map.cpp QuestionBlock.h Game.h Objects.h Mario.h blockSize.h
	g++ -c Map.cpp $(FLAGS)

Mario.o: Mario.h Mario.cpp blockSize.h
	g++ -c Mario.cpp $(FLAGS)

NormalBlock.o: NormalBlock.h NormalBlock.cpp blockSize.h
	g++ -c NormalBlock.cpp $(FLAGS)

QuestionBlock.o: QuestionBlock.cpp QuestionBlock.h blockSize.h
	g++ -c QuestionBlock.cpp $(FLAGS)

Flag.o: Flag.h Flag.cpp blockSize.h
	g++ -c Flag.cpp $(FLAGS)

Objects.o: Objects.h Objects.cpp Flag.h Pipe.h NormalBlock.h blockSize.h
	g++ -c Objects.cpp

Pipe.o: Pipe.h Pipe.cpp blockSize.h
	g++ -c Pipe.cpp $(FLAGS)

.PHONY: clean

clean:
	rm *.o
