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
		Inventory();
		Inventory(unsigned int start_balance);
		unsigned int getBalance() const;
		friend std::ostream& operator<< (std::ostream& out, const Inventory& inventory);
		void changeBalance(unsigned int amount);
		int getNetWorth() const;
		std::map<unsigned int, Property> getProperties() const;
		bool collectionEmpty() const;
		void addProperty(unsigned int property_id, Property& new_property);
		void removeProperty(unsigned int property_id);

};


#endif