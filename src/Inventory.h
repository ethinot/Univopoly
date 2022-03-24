#ifndef _INVENTORY
#define _INVENTORY

#include <iostream>
#include <map>
#include "Property.h"
class Inventory{

	private:
		int wallet;
		std::map<unsigned int, Property> collection;
	
	public:
		// Constructer with a default balance.
		Inventory();
		// Constructer with a custom balance.
		Inventory(unsigned int start_balance);
		// returns the value in wallet (it represents the amount of money that the player have).
		unsigned int getBalance() const;
		friend std::ostream& operator<< (std::ostream& out, const Inventory& inventory);
		// modify wallet by adding amount to the wallet (amount can be negative).
		void changeBalance(int amount);
		// returns wallet + the sell_price of each property (in collecition) owned by the player.
		int getNetWorth() const;
		// returns a map, containing respectively the id of a property and a pointer on the Property
		std::map<unsigned int, Property> getProperties() const;
		bool collectionEmpty() const;
		void addProperty(unsigned int property_id, Property& new_property);
		void removeProperty(unsigned int property_id);

};

#endif