#include <iostream>
#include <stdlib.h>
#include "Dice.h"


Dice::Dice(){ values = new unsigned int [2];}

void Dice::roll(){
	values[0] = (unsigned int)(rand()%6)+1; values[1] = (unsigned int)(rand()%6)+1;
}

bool Dice::checkDouble(){
	return values[0] == values[1];
}

unsigned int Dice::getTotal() const{
	return values[0] + values[1];
}


