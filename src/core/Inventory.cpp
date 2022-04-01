#include "Inventory.h"
#include "Property.h"


Inventory::Inventory() : collection() {
	wallet = 1500;
	//collection = std::map<unsigned int, Property>();
}

Inventory::~Inventory(){}

unsigned int Inventory::getBalance() const{ return wallet;}

std::ostream& operator<< (std::ostream& out, const Inventory& inventory){
	out << "Tu as: " << inventory.getBalance() << '$' << std::endl;

	for (auto const &p : inventory.collection) {
    out << "Nom: " << p.second->getName() << std::endl;
}
	return out;
}

void Inventory::changeBalance(int amount) {wallet += amount;}

int Inventory::getNetWorth() const{
	int total = wallet;

	for (auto const & [k, v] : collection){
		total += v->getSellPrice();
	}
	return total;
}

std::map<unsigned int, Tile*> Inventory::getProperties() const{return collection;}
bool Inventory::collectionEmpty() const{ return collection.empty();}

Tile* Inventory::getProperty(unsigned int property_id) { return collection[property_id];}
void Inventory::addProperty(unsigned int property_id, Tile* new_property) {collection.insert(std::pair<unsigned int, Tile*>(property_id, new_property));}
void Inventory::removeProperty(unsigned int property_id){collection.erase(property_id);}
