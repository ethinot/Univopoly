#include "Game.h"
#include "Player.h"


Game::Game(int new_total_player) : board_game("data/tiles.json"){

	total_player = new_total_player;
	for (unsigned char i = 0; i < total_player; i++){
		Players.push_back(new Player(i));
	}
}

Game::~Game() {

}

int Game::checkWinner(){
	if (Players.size() == 1) return Players[0]->getId();
	else return -1;
}

