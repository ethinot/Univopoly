#include "Gare.h"


Gare::Gare(std::string new_name, std::string new_color, std::string new_background, unsigned int new_id, unsigned int new_price, unsigned int new_sell_price){
    name = new_name;
    color = new_color;
    background = new_background;
    id = new_id;
    price = new_price;
    sell_price = new_sell_price;
    basic_rent = 50;
    owner = -1;
}

Gare::~Gare(){
    
}

unsigned int Gare::getRent(unsigned int gare_number) const { return basic_rent * gare_number;}