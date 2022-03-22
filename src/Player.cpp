#include "Player.h"




Player::Player(unsigned int new_id){
	id = new_id;
	position = 0;
	in_jail = false;
	number_gare = 0;
}

unsigned int Player::getId() const{ return id;}
unsigned int Player::getPosition() const{ return position;}
void Player::changePostion(unsigned int how_much){position += position;}
void Player::transaction(unsigned int amount){
	goods.changeBalance(amount);
}

bool Player::onJail() const{return position == 10;}
bool Player::isDead() const;
void Player::plusGare();
void Player::minusGare();
unsigned int Player::getGareCount() const;
void Player::buyProperty(unsigned int property_id){
	transaction()
}
void Player::sellProperty(unsigned int property_id);