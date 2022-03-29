#ifndef _GAME
#define _GAME


#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include <vector>
class Game{

	private:
		Board board_game;
		std::vector<Player *> players;
		int total_player;
		Dice dice;

	public:
		Game(int total_player);
		//Game(int total_player, std::string filename);
		~Game();
		int getGameSize() const;
		int checkWinner();
		int rollDice();
		bool checkDouble();
		unsigned int getId(int index) const;
		Player * getPlayerById(int id);
		Tile * getTileById(int tile_id);
		int getPlayerPosition(int id);
		void movePlayer(int id, int how_much);
		void buyTile(int id, unsigned int property_id);
		void sellTile(unsigned int property_id);
		void pay(int id, int amount);
};

#endif