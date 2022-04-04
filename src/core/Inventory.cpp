#include "Inventory.h"
#include "Property.h"


Inventory::Inventory() : collection() {
	wallet = 1500;
	//collection = std::map<unsigned int, Property>();
}

Inventory::~Inventory(){}

int Inventory::getBalance() const{ return wallet;}

std::ostream& operator<< (std::ostream& out, const Inventory& inventory){
	out << "Tu as: " << inventory.getBalance() << '$' << std::endl;
	out << std::endl;
	for (auto const &p : inventory.collection) {
		out << "-----------------------------------------------------------" << std::endl;
		out << "Id de la propriete: " << p.second->getId() << std::endl;
		out << "Nom de la propriete: " << p.second->getName() << std::endl;
		out << "Prix de vente: " << p.second->getSellPrice() << '$' << std::endl;
		out << "-----------------------------------------------------------" << std::endl;
	}
	return out;
}

int Inventory::changeBalance(int amount) {
	return wallet += amount;
}

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

bool Inventory::removeProperty(unsigned int property_id){
	if (collection.count(property_id) > 0){
		collection.erase(property_id);
		return true;
	}
	else return false;
}
