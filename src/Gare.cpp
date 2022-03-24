#include "Gare.h"
#include <string>


Gare::Gare(std::string new_name, unsigned int new_id, unsigned int new_price, unsigned int new_sell_price, unsigned int new_basic_rent){
    name = new_name;
    id = new_id;
    price = new_price;
    sell_price = new_sell_price;
    basic_rent = new_basic_rent;
    owner = -1;
}
unsigned int Gare::getRent(unsigned int gare_number) const { return basic_rent * gare_number;}


unsigned int Gare::getId() const { return id;}
unsigned int Gare::getPrice() const { return price;}
unsigned int Gare::getSellPrice() const {return sell_price; }
int Gare::getOwner() const {return owner;}
void Gare::sold() {owner = -1;}
void Gare::bought(unsigned int buyer_id) {owner = buyer_id;}