#include "Player.h"
#include "Tile.h"
#include <assert.h>

Player::Player(){
	id = -1;
	position = 0;
	jail_count = -1;
	number_gare = 0;
	bot = false;
}

Player::Player(int new_id){
	id = new_id;
	position = 0;
	jail_count = -1;
	number_gare = 0;
	bot = false;
}

int Player::getId() const {return id;}

int Player::getBalance(){
	return goods.getBalance();
}

int Player::getNetWorth(){
	return goods.getNetWorth();
}

bool Player::transaction(unsigned int amount){
	if (goods.changeBalance(amount) == true) return true;
	return false;
}

Tile* Player::getProperty(unsigned int property_id) { 
	return goods.getProperty(property_id);
}

bool Player::buyProperty(unsigned int property_id, Tile*property){
	if (transaction(-(property->getPrice()))){
		goods.addProperty(property_id, property);
		return true;
	}else return false;
}

bool Player::sellProperty(unsigned int property_id){
	int selling_price = goods.getProperty(property_id)->getSellPrice();
	if (goods.removeProperty(property_id)){
		return transaction(selling_price);
	}else return false;
}

void Player::printProperties(){
	goods.printInventory(number_gare);
}

unsigned int Player::getPosition() const {return position;}

bool Player::changePostion(unsigned int how_much) {
	unsigned int avancement = 0;
	if ((position + how_much) > 39){
		avancement = (position + how_much) - 39;
		position = avancement - 1; // décallage de -1 car la case départ est la case 0
		std::cout<< "Vous avez atterie sur la case Start !! Recuperer 200€ !!!" << std::endl;
		goods.changeBalance(200);
		return true;
	}
	else {
		position += how_much;
		return false;
	}
}

void Player::goJail(){
	position = 10;
	jail_count = 0;
}

bool Player::checkJail(){
	if (jail_count>-1 && jail_count<3) {
		jail_count ++;
		return true;
	}
	else {
		jail_count = -1;
		return false;
	}
}


bool Player::isDead() const {return goods.getNetWorth() == 0;}

void Player::plusGare() {number_gare ++;}

void Player::minusGare() {number_gare --;}

unsigned int Player::getGareCount() const{return number_gare;}

bool Player::checkBot() const{return bot;}

void Player::testRegPlayer(){
	
	//test constucteur par défault
	Player void_player;
	assert(void_player.id == -1);
	assert(void_player.position == 0);
	assert(void_player.jail_count == -1);
	assert(void_player.number_gare == 0);

	//test constructeur avec paramètre
	Player player2(2); 
	assert(player2.id == 2);
	assert(player2.position == 0);
	assert(player2.jail_count == -1);
	assert(player2.number_gare == 0);

	//test getId
	assert(player2.getId() == player2.id);

	//getBalance déja tester dans le module Inventory
	//getNetWorth déja tester dans le module Inventory
	//transaction déja tester dans le module Inventory
	//getProperty déja tester dans property/gare

	//test buyProperty
	Tile p1 = Property("Braconnier", "green", "LightGreen",1, 60, 30, 50, 2, 10, 30, 90, 160, 250);
	//assert(player2.buyProperty(&p1) == true);
	assert(player2.getBalance() == 1000-60);
	assert(player2.getNetWorth() == 940+30);

	//test printProperties
	std::cout<<"Test affichage des propriétés:"<<std::endl;
	player2.printProperties();

	//test sellProperty
	assert(player2.sellProperty(1) == true);
	assert(player2.getBalance() == 940+30);

	//test position
	assert(player2.getPosition() == 0);
	player2.changePostion(30);
	assert(player2.getPosition() == 30);
	player2.changePostion(10);
	assert(player2.getBalance() == 970+200); //passe par le case départ

	//test prison
	player2.goJail();
	assert(player2.getPosition() == 10);
	for (int i=0; i<3; i++){
		assert(player2.jail_count == i);
		assert(player2.checkJail() == true);
	}
	assert(player2.checkJail() == false);
	assert(player2.jail_count == -1);

	//test gare
	player2.plusGare();
	player2.plusGare();
	assert(player2.getGareCount() == 2);
	player2.minusGare();
	assert(player2.getGareCount() == 1);
}