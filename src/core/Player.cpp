#include "Player.h"

Player::Player(){
	id = -1;
	position = 0;
	jail_count = -1;
	number_gare = 0;
}

Player::Player(unsigned int new_id){
	id = new_id;
	position = 0;
	jail_count = -1;
	number_gare = 0;
}

unsigned int Player::getId() const{ return id;}

unsigned int Player::getPosition() const{ return position;}

void Player::changePostion(unsigned int how_much) {
	unsigned int avancement = 0;
	if ((position + how_much) > 39){
		avancement = (position + how_much) - 39;
		position = avancement - 1; // décallage de -1 car la case départ est la case 0
		// version Qt fair eun pop
		std::cout<< "Vous avez atterie sur la case Start !! Recuperer 200€ !!!" << std::endl;
		goods.changeBalance(200);
	}
	else {
		position += how_much;
	}
}

int Player::getBalance(){
	return goods.getBalance();
}

bool Player::transaction(unsigned int amount){
	if (goods.changeBalance(amount) >= 0) return true;
	return false;
}

void Player::goJail(){
	position = 10;
	jail_count = 0;
}

bool Player::checkJail() {
	if (jail_count>-1 && jail_count<3) {
		jail_count ++;
		return true;
	}
	else {
		jail_count = -1;
		return false;
	}
}

bool Player::isDead() const{ return goods.getNetWorth() == 0;}

void Player::plusGare() {number_gare ++;}

void Player::minusGare() {number_gare --;}

unsigned int Player::getGareCount() const{return number_gare;}

Tile& Player::getProperty(unsigned int property_id) { 
	return goods.getProperty(property_id);
}

bool Player::buyProperty(unsigned int property_id, Tile& property){
	if (transaction(- (property.getPrice()))){
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

int Player::getNetWorth(){
	return goods.getNetWorth();
}