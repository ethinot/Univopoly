#include "Board.h"
#include "Dice.h"
#include "Gare.h"
#include "Inventory.h"
#include "Player.h"
#include "Property.h"
#include "Tile.h"
#include <string>


int main (void){
	Player me(0);
	Property * braconnier = new Property("braconnier",1, 100, 50, 75, 10, 20, 40, 50, 100, 200);
	Gare gare_1("condorcet", 5, 200, 150, 25);

	me.buyProperty(1, braconnier);
	
	std::cout << me.getProperty(1)->getName() << std::endl;
	
	return 0;
}