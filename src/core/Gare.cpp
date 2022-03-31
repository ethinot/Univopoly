#include "Gare.h"


Gare::Gare(std::string new_name, unsigned int new_id, unsigned int new_price, unsigned int new_sell_price, unsigned int new_basic_rent){
    name = new_name;
    id = new_id;
    price = new_price;
    sell_price = new_sell_price;
    basic_rent = new_basic_rent;
    owner = -1;
}
Gare::~Gare(){}

unsigned int Gare::getRent(unsigned int gare_number) const { return basic_rent * gare_number;}