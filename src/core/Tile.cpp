#include "Tile.h"

unsigned char Tile::getId() const{ return id;}

std::string Tile::getName() const{return name;};

unsigned int Tile::getPrice() const { return price;}
unsigned int Tile::getSellPrice() const {return sell_price;}
int Tile::getOwner() const {return owner;}

void Tile::sold() {owner = -1;}

void Tile::bought(unsigned int buyer_id) {owner = buyer_id;}

void Tile::regressionTestTile() {
    
}