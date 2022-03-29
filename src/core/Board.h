#ifndef _BOARD
#define _BOARD


#include "Tile.h"
#include <vector>


class Board{

	private:
		std::vector<Tile *> game_board;
	public:
		Board();
		Board(std::string filename);
		Tile* getTile(unsigned int property_id);
};



#endif