#include "Player.h"




Player::Player(unsigned int new_id){
	id = new_id;
	position = 0;
	in_jail = false;
	number_gare = 0;
}

unsigned int Player::getId() const{ return id;}
unsigned int Player::getPosition() const{ return position;}
void Player::changePostion(unsigned int how_much) {position += position;}

void Player::transaction(unsigned int amount){
	goods.changeBalance(amount);
}

bool Player::onJail() const{return position == 10;}
bool Player::isDead() const{ return goods.getNetWorth() == 0;}
void Player::plusGare() {number_gare ++;}
void Player::minusGare() {number_gare --;}
unsigned int Player::getGareCount() const{return number_gare;}

Property* Player::getProperty(unsigned int property_id) { 
	return goods.getProperty(property_id);
}

void Player::buyProperty(unsigned int property_id, Property *property){
	transaction(- (property->getPrice()));
	goods.addProperty(property_id, property);
}

void Player::sellProperty(unsigned int property_id){
	transaction(goods.getProperty(property_id)->getSellPrice());
	goods.removeProperty(property_id);
}