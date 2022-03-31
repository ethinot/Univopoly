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



int main (void){

    int **my_ints;
    int *my_int;
    *my_int = 10;
	my_ints = new int [10];
    *my_ints[0] = my_int;
    std::cout << my_ints[0] << std::endl;

	return 0;
}