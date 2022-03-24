#ifndef _PROPERTY
#define _PROPERTY

#include <string>


class Gare {

	private:

		Gare(std::string name, unsigned int id, unsigned int price, unsigned int sell_price, unsigned int basic_rent);
		unsigned int getRent(unsigned int gare_number) const;
		unsigned int basic_rent;


	protected:
	
		unsigned int id;
		std::string name;
		unsigned int price;
		unsigned int sell_price;
		int owner;

	public:
		Gare(); // contructeur par defaut a voir !!
		unsigned int getId() const;
		unsigned int getPrice() const;
		unsigned int getSellPrice() const; 
		int getOwner() const;
		void sold();
		void bought(unsigned int); 

};




#endif