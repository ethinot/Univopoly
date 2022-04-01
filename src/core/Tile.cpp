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

std::ostream & operator << (std::ostream &out, const Tile* &t){
    out << "Vous venez de tomber sur la case: " << t->getId() << " dont le nom est ";
    out << t->getName() << "." << std::endl;
    if (t->getOwner() != -1){
        out << "Cette case appartient au joueur avec l'id = " << t->getOwner()<<std::endl;
        out << "Vous ne pouvez donc pas l'acheter."<<std::endl;
    }
    else {
        out << "La propriété est achetable vous pevez l'acheter pour " << t->getPrice() << "€" << std::endl;
    }

    return out;
}
