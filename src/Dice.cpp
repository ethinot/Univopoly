#include <iostream>
#include <stdlib.h>
#include "Dice.h"
#include <assert.h>


Dice::Dice(){ values = new unsigned int [2];}

Dice::~Dice(){
	delete [] values;
	values = nullptr;
}

void Dice::roll(){
	values[0] = (unsigned int)(rand()%6)+1; 
	values[1] = (unsigned int)(rand()%6)+1;
}

bool Dice::checkDouble(){
	return values[0] == values[1];
}

unsigned int Dice::getTotal() const{
	return values[0] + values[1];
}

void Dice::regressionTestDice() {
	
	//Test de la procédure roll
	roll();
	assert(values[0] > 0 && values[0] <= 6);
	assert(values[1] > 0 && values[1] <= 6);

}
