#include "Tile.h"



Tile::Tile(){};
Tile::~Tile(){};

void Tile::getType(){}

unsigned int Tile::getId() const{ return id;}

std::string Tile::getName() const{return name;};

unsigned int Tile::getPrice() const { return price;}
unsigned int Tile::getSellPrice() const {return sell_price;}
int Tile::getOwner() const {return owner;}

void Tile::sold() {owner = -1;}

void Tile::bought(unsigned int buyer_id) {owner = buyer_id;}
