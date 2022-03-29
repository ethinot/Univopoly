#include "Game.h"
#include "Player.h"


Game::Game(int new_total_player) : board_game("data/tiles.json"){

	total_player = total_player;
	Players = new Player * [total_player];
	for (int i = 0; i < total_player; i++){
		Players[i] = new Player(i);
	}

}
