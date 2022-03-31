#include "core/Board.h"
#include "core/Dice.h"
#include "core/Gare.h"
#include "core/Inventory.h"
#include "core/Player.h"
#include "core/Property.h"
#include "core/Tile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
//#include "rapidjson/document.h"


//using namespace rapidjson;

int main (void){

    Property * my_property = new Property("Property1", 7, 200, 100, 50, 25, 30, 35, 40, 45, 60);
    Property * my_property2 = new Property("Property1", 9, 200, 100, 50, 25, 30, 35, 40, 45, 60);

    Tile * current_tile = my_property;
    Tile * current_tile2 = my_property2;

    std::cout << typeid(*current_tile).name() << std::endl; 
    std::cout << typeid(*current_tile2).name() << std::endl; 
	return 0;
}