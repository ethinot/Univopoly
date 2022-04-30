#include "Inventory.h"
#include "Property.h"
#include "Gare.h"
#include "Tile.h"
#include <assert.h>

Inventory::Inventory() : collection() {
	wallet = 1000;
}

Inventory::~Inventory(){}

int Inventory::getBalance() const{ return wallet;}

bool Inventory::changeBalance(int amount) {
	if ( (getBalance() + amount) <= 0){
		return false;
	} else {
		wallet += amount;
		return true;
	}
}

int Inventory::getNetWorth() const{
	
	int total = wallet;
	
	for (auto & element : collection){
		total += element->getSellPrice();
	}
	assert(total > -1);
	return total;
}

Tile* Inventory::getProperty(int property_id) const{
	
	assert(property_id >=0 && property_id < 40);
	
	Tile* res;
	for (auto & element : collection){
		if (element->getId() == property_id) {res = element;}
	}
	return res;
}

void Inventory::addProperty(Tile *new_property) {
	collection.push_back(new_property);
}

bool Inventory::removeProperty(unsigned int property_id){
	
	assert(property_id >=0 && property_id < 40);
	
	std::vector<Tile *>::iterator it; //declaration of a iterator
	it = collection.begin(); // initialisation 
	
	for(auto & element : collection)    {
    	if((unsigned int)element->getId() == property_id){
			collection.erase(it);
			return true;
		}
		it++;
	}	
	return false;
}

std::vector<Tile*> Inventory::getProperties() const {return collection;}

bool Inventory::collectionEmpty() const{ return collection.empty();}

std::ostream& operator<< (std::ostream& out, const Inventory& inventory){
	
	out << "Tu as: " << inventory.getBalance() << 'e' << std::endl;
	out << std::endl;
	
	for (auto const &element : inventory.collection) {
		out << "-------------- Nom: " << element->getName() << " --------------" << std::endl;
		out << " Id de la propriete: " << element->getId() << std::endl;
		out << " Prix de vente: " << element->getSellPrice() << 'e' << std::endl;
	}
	return out;
	std::cout << "---------------------------------------------" << std::endl;
}

void Inventory::printInventory(int gare_count){
	std::cout << "Tu as: " << wallet << 'e' << std::endl;
	std::cout << std::endl;
	
	for (auto const &element : collection) {
		std::cout << "-------------- Nom: " << element->getName() << " --------------" << std::endl;
		std::cout << "Id de la propriete: " << element->getId() << std::endl;
		std::cout << "Prix de vente: " << element->getSellPrice() << 'e' << std::endl;

		if (typeid(element).name() == typeid(Property).name()){
			std::cout << "Prix d'une salle de classe: " << static_cast<Property*>(element)->getBuildPrice() << 'e' << std::endl;
			std::cout << "Loyer actuelle: " << static_cast<Property*>(element)->getRent() << 'e' << std::endl;

		}else if (typeid(element).name() == typeid(Gare).name()){
			std::cout << "Loyer actuelle: " << static_cast<Gare*>(element)->getRent(gare_count) << 'e' << std::endl;
		}
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void Inventory::testRegInventory(){
	Inventory invent;
	assert(invent.collection.empty() == true);
	assert(invent.wallet == 1000);

	//Test collectionEmpty
	assert(invent.collectionEmpty() == true);

	//Test getBalance
	assert(invent.getBalance() == 1000);

	//Test changeBalance
	assert(invent.changeBalance(100) == true);
	assert(invent.getBalance() == 1100);
	assert(invent.changeBalance(-1200) == false);
	assert(invent.getBalance() == 1100);

	//Test addProperty
	Tile p1 = Property("Braconnier", 1, 60, 30, 50, 2, 10, 30, 90, 160, 250);
	Tile g1 = Gare("Condorcet", 5, 200, 100);
	invent.addProperty(&p1);
	invent.addProperty(&g1);
	assert(invent.collection.size() == 2);
	assert(invent.collection[0] == &p1);
	assert(invent.collection[1] == &g1);

	//Test surcharge cout
	std::cout<<"Test affichage:"<<std::endl;
	std::cout<<invent<<std::endl;
	std::cout<<std::endl;
	
	//Test printInventory
	invent.printInventory(1);

	//Test getProperty
	assert(invent.getProperty(5) == &g1);

	//Test getNetWorth
	int net_worth = invent.getNetWorth();
	assert(net_worth == (invent.wallet + 30 + 100));

	//Test removeProperty
	invent.removeProperty(5);
	assert(invent.collection.size() == 1);
}


