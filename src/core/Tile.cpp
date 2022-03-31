#include "Tile.h"

<<<<<<< HEAD

void Tile::getType(){}

Tile::Tile(){};
Tile::~Tile(){};

=======
Tile::Tile(){};
Tile::~Tile(){};

void Tile::getType(){}

>>>>>>> 608542780c26bd288eb47a1e8df163544e0f2c1f
unsigned int Tile::getId() const{ return id;}

std::string Tile::getName() const{return name;};

unsigned int Tile::getPrice() const { return price;}

unsigned int Tile::getSellPrice() const {return sell_price;}

int Tile::getOwner() const {return owner;}

void Tile::sold() {owner = -1;}

void Tile::bought(unsigned int buyer_id) {owner = buyer_id;}

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
