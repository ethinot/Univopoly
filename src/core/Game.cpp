#include "Game.h"
#include "Player.h"

/*
Game::Game(int new_total_player) : board_game("data/tiles.json"){

	total_player = total_player;
	Players = new Player * [total_player];
	for (unsigned char i = 0; i < total_player; i++){
		Players[i] = new Player(i);
	}
}
*/

Game::~Game() {
	for (unsigned char i = 0; i < total_player; i++ ){
		delete Players[i];
	}
	delete [] Players;
}

int Game::checkWinner(){
	if (sizeof(Players) == 1) return Players[0]->getId();
	else return -1;
}

