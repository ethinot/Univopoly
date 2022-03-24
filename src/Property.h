#ifndef _PROPERTY
#define _PROPERY

#include "Tile.h"

class Property :  public Tile{

	private:
		unsigned int build_price;
		unsigned int * rent;
		unsigned int rent_count;
		int owner;

	public:
		Property(std::string name, unsigned int id, char price, unsigned int sell_price, 
		unsigned int new_build_price, unsigned int rent_0, 
		unsigned int rent_1, unsigned int rent_2, unsigned int rent_3,
		unsigned int rent_4, unsigned int rent_5);
		unsigned int getRent() const;
		unsigned int getBuildPrice() const;
		void rentUpgrade();
		void emptyProperty();

};


#endif