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
#include "rapidjson/document.h"


using namespace rapidjson;

int main (void){

    int **my_ints;
	my_ints = new int * [10];
	for (unsigned char i = 0; i < 10; i++){
		my_ints[i] = new int;
	}
    std::cout << my_ints[0] << std::endl;
    int *ptr = my_ints;
    std::cout << sizeof(ptr) << std::endl;


	return 0;
}