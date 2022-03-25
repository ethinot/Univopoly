CCOPTIONS	= -Wall -g
CC			= g++ $(CCOPTIONS) 
OBJ			= obj/Board.o obj/Dice.o obj/Game.o obj/Gare.o obj/Inventory.o obj/Player.o obj/Property.o obj/Tile.o
HEADERS		= src/Board.h src/Dice.h src/Game.h src/Gare.h src/Inventory.h src/Player.h src/Property.h src/Tile.cpp


all: bin/test

bin/test: obj/mainTest.o obj/Dice.o
	$(CC) obj/mainTest.o obj/Dice.o -o bin/test

obj/mainTest.o: src/mainTest.cpp src/Dice.h
	$(CC) -c src/mainTest.cpp -o obj/mainTest.o

obj/Dice.o: src/Dice.h src/Dice.cpp
	$(CC) -c src/Dice.cpp -o obj/Dice.o


bin/test2: obj/test2.o $(OBJ)
	$(CC) obj/test2.o $(OBJ) -o bin/test2

obj/test2.o: src/test.cpp $(HEADERS)
	$(CC) -c src/test.cpp -o obj/test2.o

obj/Board.o: src/Board.h src/Board.cpp src/Tile.h
	$(CC) -c src/Board.cpp -o obj/Board.o

obj/Dice.o: src/Dice.h src/Dice.cpp
	$(CC) -c src/Dice.cpp -o obj/Dice.o

obj/Game.o: src/Game.h src/Game.cpp
	$(CC) -c src/Game.cpp -o obj/Game.o

obj/Gare.o: src/Gare.h src/Gare.cpp src/Tile.h
	$(CC) -c src/Gare.cpp -o obj/Gare.o

obj/Inventory.o: src/Inventory.h src/Inventory.cpp src/Property.h
	$(CC) -c src/Inventory.cpp -o obj/Inventory.o

obj/Player.o: src/Player.h src/Player.cpp src/Inventory.h
	$(CC) -c src/Player.cpp -o obj/Player.o

obj/Property.o: src/Property.h src/Property.cpp src/Tile.h
	$(CC) -c src/Property.cpp -o obj/Property.o

obj/Tile.o: src/Tile.h src/Tile.cpp
	$(CC) -c src/Tile.cpp -o obj/Tile.o
	

clean:
	rm obj/* bin/*