#ifndef _PLAYER
#define _PLAYER

#include "Inventory.h"
#include <map>
class Player{

	private:
		unsigned int id;
		Inventory goods;
		unsigned int position;
		int jail_count;
		unsigned int number_gare;

	public:
		Player();
		Player(unsigned int _id);
		unsigned int getId() const;
		unsigned int getPosition() const;
		void changePostion(unsigned int how_much);
		bool transaction(unsigned int amout);
		void goJail();
		bool checkJail();
		bool isDead() const;
		void plusGare();
		void minusGare();
		unsigned int getGareCount() const;
		Tile& getProperty(unsigned int property_id);
		bool buyProperty(unsigned int property_id, Tile& property);
		bool sellProperty(unsigned int property_id);
		void printProperties();
		int getNetWorth();
		int getBalance();



};

#endif