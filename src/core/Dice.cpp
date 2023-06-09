#include <iostream>
#include <stdlib.h>
#include "Dice.h"
#include <assert.h>


Dice::Dice(){ values = new unsigned int[2];}

Dice::~Dice(){
	delete [] values;
	values = nullptr;
}

void Dice::roll(){
	values[0] = (unsigned char)(rand()%6)+1; 
	values[1] = (unsigned char)(rand()%6)+1;
}

unsigned int Dice::getFirstDice() const{
	return values[0];
}

unsigned int Dice::getSecondDice() const{
	return values[1];
}

bool Dice::checkDouble() const{
	return values[0] == values[1];
}

unsigned int Dice::getTotal() const{
	return values[0] + values[1];
}

void Dice::testRegDice() {
	
	//Test constructeur
	Dice unDes;
	
	//Test de la procédure roll 100 fois avec des nombres aléatoires differents
	for(unsigned char i=0; i<100; i++){
		unDes.roll();
		assert(unDes.values[0] > 0 && unDes.values[0] <= 6);
		assert(unDes.values[1] > 0 && unDes.values[1] <= 6);
	}

	//Test fonction getSecondDice & getFirstDice

	for(unsigned char i=0; i<100; i++){
		unDes.roll();
		assert(unDes.values[0] == unDes.getFirstDice());
		assert(unDes.values[1] == unDes.getSecondDice());
	}

	//Test fonction checkDouble
	for(unsigned char i=0; i<100; i++){
		unDes.roll();
		if(unDes.values[0] == unDes.values[1]) {assert(unDes.checkDouble() == true);}
		else assert(unDes.checkDouble() == false);
	}

	//Test fonction getTotal
	for(unsigned char i=0; i<100; i++){
		unDes.roll();
		assert(unDes.values[0] + unDes.values[1] == unDes.getTotal());
		assert(unDes.getTotal() > 1 && unDes.getTotal() <= 12);
	}
}
