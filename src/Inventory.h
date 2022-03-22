#ifndef _INVENTORY
#define _INVENTORY


#include "Property.h"
#include <map>
class Inventory{

	private:
		int wallet;
		std::map<unsigned int, Property> collection;
	
	public:
		Inventory(unsigned int start_balance);
		unsigned int getBalance() const;
		void changeBalance(unsigned int amount);
		int getNetWorth() const;
		std::map<unsigned int, Property> getProperties() const;
		bool collectionEmpty() const;
		void addProperty(unsigned int property_id, Property& new_property);
		void removeProperty(unsigned int property_id);

};


#endif