#include "Game.h"
#include "Player.h"


Game::Game(int new_total_player) : board_game("data/tiles.json"){

	total_player = new_total_player;
	for (unsigned char i = 0; i < total_player; i++){
		players.push_back(new Player(i+1));
	}
}

Game::~Game() {

}

int Game::getGameSize() const{return total_player;}

int Game::checkWinner(){
	if (players.size() == 1) return players[0]->getId();
	else return -1;
}

int Game::rollDice(){
	dice.roll();
	return dice.getTotal();
}

bool Game::checkDouble(){
	return dice.checkDouble();
}

unsigned int Game::getId(int index) const{return players[index]->getId();}

Player * Game::getPlayerById(int id){
	for (int i = 0; i < players.size(); i++){
		if (players[i]->getId() == id) return players[i];
	}
}

int Game::getPlayerPosition(int id){
	return getPlayerById(id)->getPosition();
}

void Game::movePlayer(int id, int how_much){
	Player * current_player = getPlayerById(id);	
	current_player->changePostion(how_much);
}

void Game::buyTile(int id, unsigned int property_id){ 
	Player * current_player = getPlayerById(id);
	current_player->buyProperty(property_id, board_game.getTile(property_id));
}

void Game::buyTile(int id, unsigned int property_id){ 
	Player * current_player = getPlayerById(id);
	current_player->sellProperty(property_id);
}

Tile * Game::getTileById(int property_id){
	return board_game.getTile(property_id);
}

void Game::pay(int id, int amount){
	Player * current_player = getPlayerById(id);
	current_player->transaction(-amount);
}