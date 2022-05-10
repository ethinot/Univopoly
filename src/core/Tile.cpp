#include "Tile.h"

Tile::Tile(){};

Tile::Tile(std::string new_name, std::string new_color, unsigned int new_id, unsigned int new_price, unsigned int new_sell_price){
    name = new_name;
    color = new_color;
    id = new_id;
    price = new_price;
    sell_price = -1;
    owner = -2;
}

Tile::~Tile(){}

void Tile::getType(){}

int Tile::getId() const{ return id;}

std::string Tile::getName() const{return name;};

std::string Tile::getColor() const{return color;};

unsigned int Tile::getPrice() const { return price;}

unsigned int Tile::getSellPrice() const {return sell_price;}

int Tile::getOwner() const {return owner;}

void Tile::sold() {owner = -1;}

void Tile::bought(unsigned int buyer_id) {owner = buyer_id;}

std::ostream & operator << (std::ostream &out, const Tile &t){
    out << "Case numero: " << t.getId() << std::endl;
    out << " Nom: " << t.getName() << std::endl;
    if (t.getOwner() > 0){
        out << "Cette case appartient au joueur numero: " << t.getOwner()<<std::endl;
    }
    else if (t.getOwner() == -1){
        out << "La propriété est achetable vous pevez l'acheter pour " << t.getPrice() << "€" << std::endl;
    }

    return out;
}
