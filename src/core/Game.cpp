#include "Game.h"
#include "Player.h"
#include <assert.h>

Game::Game(int new_total_player){

	total_player = new_total_player;
	for (unsigned char i = 0; i < total_player; i++){
		players.push_back(Player(i+1));
	}
	parc_money = 0;
}

Game::Game(int new_total_player, std::string filename) : board_game(){
	total_player = new_total_player;
		for (unsigned char i = 0; i < total_player; i++){
		players.push_back(Player(i+1));
	}
	parc_money = 0;
}

Game::~Game() {
	players.clear();
}

Player & Game::getPlayerById(int player_id){
	assert(player_id > 0 && player_id <= getGameSize());
	int res;
	for (long unsigned int i = 0; i < players.size(); i++){
		if (players[i].getId() == player_id) res=i; 
	}
	return players[res];
}

Tile* Game::getTileById(int tile_id){
	assert(tile_id>=0 && tile_id<40);
	return board_game.getTile(tile_id);
}

int Game::getId(int indice) const{
	return players[indice].getId();
}

int Game::getPlayerIndex(int player_id) const{
	assert(player_id > 0 && player_id <= getGameSize());
	for (long unsigned int i = 0; i < players.size(); i++){
		if (players[i].getId() == player_id) {
			return i;
		}
		return -1;
	}
	return 0;
}

int Game::getGameSize() const{return total_player;}

int Game::getPlayerPosition(int player_id){
	return getPlayerById(player_id).getPosition();
}

int Game::rollDice(){
	dice.roll();
	return dice.getTotal();
}

unsigned int Game::firstDice() const{
	return dice.getFirstDice();
}

unsigned int Game::secondDice() const{
	return dice.getSecondDice();
}

bool Game::checkDouble() const{
	return dice.checkDouble();
}

void Game::movePlayer(int id, int how_much){
	getPlayerById(id).changePostion(how_much);
}

void Game::printPlayerProperties(int id){
	getPlayerById(id).printProperties();
}

bool Game::pay(int id, int amount, int id_reciever){
	if (getPlayerById(id).transaction(-amount)){
		if (id_reciever == -1){
			parc_money += amount;
			return true;
		}else{
			getPlayerById(id_reciever).transaction(+amount);
			return true;
		}
	}else return false;
}

bool Game::buyTile(int id, unsigned int property_id){ 
	if (getPlayerById(id).buyProperty(getTileById(property_id))){
		
		board_game.getTile(property_id)->bought(id);
		
		if (typeid(*board_game.getTile(property_id)).name() == typeid(Gare).name()) {
			getPlayerById(id).plusGare();
		}
		return true;
	
	}else return false;
}

bool Game::sellTile(int id, unsigned int property_id){ 
	if (getPlayerById(id).sellProperty(property_id)){
		
		board_game.getTile(property_id)->sold();
		
		if (typeid(*board_game.getTile(property_id)).name() == typeid(Property).name()) {
			static_cast<Property*>(board_game.getTile(property_id))->emptyProperty();
		} 
		else if (typeid(*board_game.getTile(property_id)).name() == typeid(Gare).name()) {
			getPlayerById(id).minusGare();
		}
		return true;
	
	}else return false;
}

void Game::checkPropertiesToSell(int id){
	int input_property_id;
	getPlayerById(id).printProperties();
	do
	{
		std::cout << "Entrez le id de la propriété que vous voulais vendre: ";
		std::cin >> input_property_id;

	}while(!sellTile(id, input_property_id));
}

bool Game::checkJail(int id){
	return getPlayerById(id).checkJail();
}

void Game::sendJail(int id){
	getPlayerById(id).goJail();
}

void Game::killPlayer(int id){
	int index = id-1;
	players.erase(players.begin() + index);
}

int Game::checkWinner(){
	if (players.size() == 1) return players[0].getId();
	else return -1;
}

Board* Game::getBoard(){
	return &board_game;
}

std::vector<Player> Game::getPlayers(){
	return players;
}
