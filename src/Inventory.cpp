#include "Inventory.h"
#include "Property.h"
#include <map>


Inventory::Inventory() : collection() {
	wallet = 5000;
	//collection = std::map<unsigned int, Property>();
}

Inventory::Inventory(unsigned int start_balance){
	wallet = start_balance;
	collection = std::map<unsigned int, Property>();
}


unsigned int Inventory::getBalance() const{ return wallet;}

std::ostream& operator<< (std::ostream& out, const Inventory& inventory){
	out << inventory.getBalance() << std::endl;
	return out;
}

void Inventory::changeBalance(int amount) {wallet += amount;}

int Inventory::getNetWorth() const{
	int total = wallet;

	for (auto const & [k, v] : collection){
		total += v.getSellPrice();
	}
	return total;
}

std::map<unsigned int, Property> Inventory::getProperties() const{return  collection;}
bool Inventory::collectionEmpty() const{ return collection.empty();}

void Inventory::addProperty(unsigned int property_id, Property& new_property) {collection.insert(std::pair<unsigned int,Property>(property_id, new_property));}
void Inventory::removeProperty(unsigned int property_id){collection.erase(property_id);}
