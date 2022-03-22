#include "Property.h"
#include <string>


Property::Property(std::string name, unsigned int id, char price, unsigned int sell_price, 
					unsigned int upgrade_price, unsigned int rent_0, unsigned int rent_1,
					unsigned int rent_2, unsigned int rent_3,
					unsigned int rent_4, unsigned int rent_5){
	name = name;
	id = id;
	price = price;
	sell_price = sell_price;
	upgrade_price = upgrade_price;
	rent = new unsigned int [6];
	rent[0] = rent_0; rent[1] = rent_1;
	rent[2] = rent_2; rent[3] = rent_3;
	rent[4] = rent_4; rent[5] = rent_5;
	rent_count = 0;

}

unsigned int Property::getId() const { return id; }
unsigned int Property::getPrice() const { return price; }
unsigned int Property::getSellPrice() const {return sell_price; }
unsigned int Property::getUpgradePrice() const { return upgrade_price; }
unsigned int Property::getRentCount() const { return rent_count; }


unsigned int Property::getRent() const {
    return rent[rent_count];}

void Property::rentUpgrade(){
	sell_price += rent_count * (0.3 * upgrade_price);
	rent_count += 1;
}

void Property::emptyProperty(){
	sell_price -= rent_count * (0.3 * upgrade_price);
	rent_count = 0;
}