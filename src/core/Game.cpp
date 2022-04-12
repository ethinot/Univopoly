#include "Game.h"
#include "Player.h"


Game::Game(int new_total_player){

	total_player = new_total_player;
	for (unsigned char i = 0; i < total_player; i++){
		players.push_back(new Player(i+1));
	}
	parc_money = 0;
}

Game::Game(int new_total_player, std::string filename) : board_game(){
	total_player = new_total_player;
		for (unsigned char i = 0; i < total_player; i++){
		players.push_back(new Player(i+1));
	}
	parc_money = 0;
}

Game::~Game() {
	players.clear();
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

unsigned int Game::firstDice() const{
	return dice.getFirstDice();
}

unsigned int Game::secondDice() const{
	return dice.getSecondDice();
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

bool Game::buyTile(int id, unsigned int property_id){ 
	Player * current_player = getPlayerById(id);
	if (current_player->buyProperty(property_id, board_game.getTile(property_id))){
		board_game.getTile(property_id)->bought(id);
		if (typeid(*board_game.getTile(property_id)).name() == typeid(Gare).name()) current_player->plusGare();
		return true;
	}else return false;
}

bool Game::sellTile(int id, unsigned int property_id){ 
	Player * current_player = getPlayerById(id);
	if (current_player->sellProperty(property_id)){
		board_game.getTile(property_id)->sold();
		if (typeid(*board_game.getTile(property_id)).name() == typeid(Property).name()) static_cast<Property*>(board_game.getTile(property_id))->emptyProperty();
		else if (typeid(*board_game.getTile(property_id)).name() == typeid(Gare).name()) current_player->minusGare();
		return true;
	}else return false;
}

Tile& Game::getTileById(int property_id){
	//assert(property_id<)
	return board_game.getTile(property_id);
}

bool Game::pay(int id, int amount, int id_reciever){
	Player * current_player = getPlayerById(id);
	if (current_player->transaction(-amount)){
		if (id_reciever == -1){
			parc_money += amount;
			return true;
		}else{
			Player * reciever_player = getPlayerById(id_reciever);
			reciever_player->transaction(+amount);
			return true;
		}
	}else return false;
}

void Game::printPlayerProperties(int id){
	//getPlayerById(id)->printProperties();
	player(0).printProperties();
}

int Game::getPlayerIndex(int id){
	for (int i = 0; i < players.size(); i++){
		if (player([i)->getId() == id){
			return i;
		}
	}
	return -1;
}

void Game::killPlayer(int id){
	int index = getPlayerIndex(id);
	players.erase(players.begin() + index);
}

bool Game::checkJail(int id){
	return getPlayerById(id)->checkJail();
}

void Game::sendJail(int id){
	getPlayerById(id)->goJail();
}

void Game::checkPropertiesToSell(int id){
	int input_property_id;
	Player * current_player = getPlayerById(id);
	current_player->printProperties();
	do
	{
		std::cout << "Entrez le id de la propriété que vous voulais vendre: ";
		std::cin >> input_property_id;

	}while(!sellTile(id, input_property_id));
}