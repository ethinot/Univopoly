CCOPTIONS	= -Wall -g
CC			= g++ $(CCOPTIONS) 

all: bin/test

bin/test: obj/mainTest.o obj/Dice.o
	$(CC) obj/mainTest.o obj/Dice.o -o bin/test

obj/mainTest.o: src/mainTest.cpp src/Dice.h
	$(CC) -c src/mainTest.cpp -o obj/mainTest.o

obj/Dice.o: src/Dice.h src/Dice.cpp
	$(CC) -c src/Dice.cpp -o obj/Dice.o
	