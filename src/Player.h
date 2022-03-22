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
		Player(unsigned int id);
		unsigned int getId() const;
		void setId(unsigned int new_id);
		unsigned int getPosition() const;
		void setPosition(unsigned int new_position);
		void changePostion(unsigned int how_much);
		void transaction(unsigned int amout);
		bool onJail() const;
		bool isDead() const;
		void plusGare();
		void minusGare();
		unsigned int getGareCount() const;
		void buyProperty(unsigned int property_id);
		void sellProperty(unsigned int property_id);




};

#endif