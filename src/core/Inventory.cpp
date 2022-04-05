#include "Inventory.h"
#include "Property.h"
#include "Gare.h"


Inventory::Inventory() : collection() {
	wallet = 1500;
	//collection = std::map<unsigned int, Property>();
}

Inventory::~Inventory(){}

int Inventory::getBalance() const{ return wallet;}

void Inventory::printInventory(int gare_count){
	std::cout << "Tu as: " << wallet << '$' << std::endl;
	std::cout << std::endl;
	for (auto const &p : collection) {
		std::cout << "--------------- Nom: " << p.second->getName() << " ----------------" << std::endl;
		std::cout << "Id de la propriete: " << p.second->getId() << std::endl;
		std::cout << "Prix de vente: " << p.second->getSellPrice() << '$' << std::endl;

		if (typeid(*p.second).name() == typeid(Property).name()){
			std::cout << "Prix d'une salle de classe: " << static_cast<Property*>(p.second)->getBuildPrice() << '$' << std::endl;
			std::cout << "Loyer actuelle: " << static_cast<Property*>(p.second)->getRent() << '$' << std::endl;

		}else if (typeid(*p.second).name() == typeid(Gare).name()){
			std::cout << "Loyer actuelle: " << static_cast<Gare*>(p.second)->getRent(gare_count) << '$' << std::endl;
		}

	}
	std::cout << "-------------------------------------------------" << std::endl;
}


std::ostream& operator<< (std::ostream& out, const Inventory& inventory){
	out << "Tu as: " << inventory.getBalance() << '$' << std::endl;
	out << std::endl;
	for (auto const &p : inventory.collection) {
		out << "--------------- Nom: " << p.second->getName() << "----------------" << std::endl;
		out << "Id de la propriete: " << p.second->getId() << std::endl;
		out << "Prix de vente: " << p.second->getSellPrice() << '$' << std::endl;
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
