CCOPTIONS	= -Wall -g
CC			= g++ $(CCOPTIONS) 
OBJ			= obj/Board.o obj/Dice.o obj/Game.o obj/Gare.o obj/Inventory.o obj/Player.o obj/Property.o obj/Tile.o
HEADERS		= src/core/Board.h src/core/Dice.h src/core/Game.h src/core/Gare.h src/core/Inventory.h src/core/Player.h src/core/Property.h src/core/Tile.cpp
INC			= -std=c++11

all: bin/test

bin/test: obj/mainTest.o obj/Dice.o
	$(CC) obj/mainTest.o obj/Dice.o -o bin/test

obj/mainTest.o: src/mainTest.cpp src/Dice.h
	$(CC) -c src/mainTest.cpp -o obj/mainTest.o

obj/Dice.o: src/core/Dice.h src/core/Dice.cpp
	$(CC) -c src/core/Dice.cpp -o obj/Dice.o


bin/test2: obj/test2.o $(OBJ)
	$(CC) obj/test2.o $(OBJ) -o bin/test2

obj/test2.o: src/test.cpp $(HEADERS)
	$(CC) -c src/test.cpp -o obj/test2.o

obj/Board.o: src/core/Board.h src/core/Board.cpp src/core/Tile.h
	$(CC) -c src/core/Board.cpp -o obj/Board.o

obj/Game.o: src/core/Game.h src/core/Game.cpp
	$(CC) -c src/core/Game.cpp -o obj/Game.o

obj/Gare.o: src/core/Gare.h src/core/Gare.cpp src/core/Tile.h
	$(CC) -c src/core/Gare.cpp -o obj/Gare.o

obj/Inventory.o: src/core/Inventory.h src/core/Inventory.cpp src/core/Property.h
	$(CC) -c src/core/Inventory.cpp -o obj/Inventory.o

obj/Player.o: src/core/Player.h src/core/Player.cpp src/core/Inventory.h
	$(CC) -c src/core/Player.cpp -o obj/Player.o

obj/Property.o: src/core/Property.h src/core/Property.cpp src/core/Tile.h
	$(CC) -c src/core/Property.cpp -o obj/Property.o

obj/Tile.o: src/core/Tile.h src/core/Tile.cpp
	$(CC) -c src/core/Tile.cpp -o obj/Tile.o
	

clean:
	rm obj/* bin/*