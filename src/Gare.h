#ifndef _GARE
#define _GARE

#include "Tile.h"

class Gare : public Tile{

	private:
		unsigned int basic_rent;

	public:
		Gare(std::string name, unsigned int id, unsigned int price, unsigned int sell_price, unsigned int basic_rent);
		unsigned int getRent(unsigned int gare_number) const;

};


#endif