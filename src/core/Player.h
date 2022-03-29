#ifndef _PLAYER
#define _PLAYER

#include "Inventory.h"

class Player{

	private:
		unsigned int id;
		Inventory goods;
		unsigned int position;
		bool in_jail;
		unsigned int number_gare;

	public:
		Player();
		Player(unsigned int _id);
		unsigned int getId() const;
		unsigned int getPosition() const;
		void changePostion(unsigned int how_much);
		void transaction(unsigned int amout);
		bool onJail() const;
		bool isDead() const;
		void plusGare();
		void minusGare();
		unsigned int getGareCount() const;
		Property* getProperty(unsigned int property_id);
		void buyProperty(unsigned int property_id, Property* property);
		void sellProperty(unsigned int property_id);




};

#endif