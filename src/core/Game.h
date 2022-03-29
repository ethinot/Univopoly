#ifndef _GAME
#define _GAME


#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include <vector>
class Game{

	private:
		Board board_game;
		std::vector<Player *> Players;
		int total_player;
		Dice dice;

	public:
		Game(int total_player);
		//Game(int total_player, std::string filename);
		~Game();
		int checkWinner();
		int rollDice();
		bool checkDouble();
		int getTotal();
		int getPlayerPosition();
		void movePlayer(int how_much);
		void buyTile();
		void sellTile(unsigned int property_id);
};

#endif