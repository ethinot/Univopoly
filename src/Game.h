#ifndef _GAME
#define _GAME


#include "Board.h"
#include "Player.h"
#include "Dice.h"

class Game{

	private:
		Board board_game;
		Player * Players;
		int total_player;
		Dice dice;

	public:
		Game();
		~Game();
		int checkWinner();
		int rollDice();
		bool checkDouble();
		int buyTile();
		int sellTile(unsigned int property_id);



};

#endif