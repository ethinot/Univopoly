#include "Tile.h"

<<<<<<< HEAD
=======

void Tile::getType(){}

Tile::Tile(){};
Tile::~Tile(){};

>>>>>>> a11f19620b73b5a7bc5086feeab9387de7654fc2
unsigned int Tile::getId() const{ return id;}

std::string Tile::getName() const{return name;};

unsigned int Tile::getPrice() const { return price;}

unsigned int Tile::getSellPrice() const {return sell_price;}

int Tile::getOwner() const {return owner;}

void Tile::sold() {owner = -1;}

void Tile::bought(unsigned int buyer_id) {owner = buyer_id;}
<<<<<<< HEAD

std::ostream & operator << (std::ostream &out, const Tile &t){
    out<< "Vous venez de tomber sur la case: "<<t.id<< " dont le nom est ";
    out<<t.name<<"."<<std::endl;
    if (t.owner != -1){
        out<<"Cette case appartient au joueur avec l'id = "<<t.owner<<std::endl;
        out<<"Vous ne pouvez donc pas l'acheter."<<std::endl;
    }
    else {
        out<<"La propriété est achetable vous pevez l'acheter pour "<<t.price<<"€"<<std::endl;
    }

    return out;
}
=======
>>>>>>> a11f19620b73b5a7bc5086feeab9387de7654fc2
