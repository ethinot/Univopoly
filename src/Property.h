#ifndef _PROPERTY
#define _PROPERTY

#include <string>


class Property {

	private:
	
		unsigned int id;
		std::string name;
		unsigned int price;
		unsigned int sell_price;
		unsigned int build_price;
		unsigned int * rent;
		unsigned int rent_count;

	public:

		// Constructeur a utiliser avec un csv
		Property(std::string name, unsigned int id, char price, unsigned int sell_price, 
		unsigned int new_build_price, unsigned int rent_0, unsigned int rent_1,
		unsigned int rent_2, unsigned int rent_3,
		unsigned int rent_4, unsigned int rent_5);

		unsigned int getId() const; // reenvoie le id de la Propriete
		unsigned int getPrice() const; // reenvoie le prix de la Propriete
		unsigned int getSellPrice() const; // reenvoie le prix de vente de la Propriete
		unsigned int getBuildPrice() const;
		unsigned int getRentCount() const;

		unsigned int getRent() const;

		void rentUpgrade();
		void emptyProperty();

};




#endif