#ifndef _TILE
#define _TILE

#include <string>

class Tile {

	protected:

		unsigned int id;
		std::string name;
		unsigned int price;
		unsigned int sell_price;
		int owner;

	public:

		unsigned int getId() const;
		std::string getName() const;
		unsigned int getPrice() const;
		unsigned int getSellPrice() const; 
		int getOwner() const;
		void sold();
		void bought(unsigned int); 

};


#endif