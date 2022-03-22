#ifndef _PROPERTY
#define _PROPERTY

#include <string>


class Property {

	private:
	
		unsigned int id;
		std::string name;
		unsigned int price;
		unsigned int sell_price;
		unsigned int upgrade_price;
		unsigned int * rent;
		unsigned int rent_count;

	public:

		Property(std::string name, unsigned int id, char price, unsigned int sell_price, 
		unsigned int upgrade_price, unsigned int rent_0, unsigned int rent_1,
		unsigned int rent_2, unsigned int rent_3,
		unsigned int rent_4, unsigned int rent_5);

		// Getters and Setters with no logic involved
		unsigned int getId() const;
		unsigned int setId(unsigned int new_id);
		unsigned int getPrice() const;
		unsigned int setPrice(unsigned int new_price);
		unsigned int getSellPrice() const;
		unsigned int setSellPrice(unsigned int new_sell_price);
		unsigned int getUpgradePrice() const;
		unsigned int setUpgradePrice(unsigned int new_upgrade_price);
		unsigned int getRentCount() const;

		unsigned int getRent() const;

		void rentUpgrade();
		void emptyProperty();

};




#endif