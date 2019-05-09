CC = g++ -std=c++11


all: 3.out

3.out: Player.o game_manager.o GoalKeeper.o Defender.o Striker.o defines.h main.o Field.o GameManager.o
	$(CC) Player.o game_manager.o GoalKeeper.o Defender.o Striker.o main.o Field.o GameManager.o -o 3.out

main.o: main.cpp game_manager.h

Player.o: Player.h Player.cpp
	$(CC) -c Player.cpp

game_manager.o: game_manager.h game_manager.cpp Player.h defines.h
	$(CC) -c game_manager.cpp

GoalKeeper.o: GoalKeeper.h GoalKeeper.cpp Player.h defines.h
	$(CC) -c GoalKeeper.cpp

Defender.o: Defender.h Defender.cpp Player.h defines.h
	$(CC) -c Defender.cpp

Striker.o: Striker.h Striker.cpp Player.h defines.h
	$(CC) -c Striker.cpp

Field.o: Field.h Field.cpp Player.h defines.h
	$(CC) -c Field.cpp

GameManager.o: GameManager.h GameManager.cpp Field.h GoalKeeper.h Defender.h Striker.h defines.h
	$(CC) -c GameManager.cpp

.PHONY: clean

clean:
	rm *.o
	rm *.out