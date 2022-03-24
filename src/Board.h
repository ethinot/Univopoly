#ifndef _BOARD
#define _BOARD

#include <map>
#include "Property.h"
#include "Gare.h"


class Board{

	private:
		std::map<unsigned int, Property> properties;
		std::map<unsigned int, Gare> properties;
		std::map<unsigned int, std::string> properties;
};



#endif