#ifndef _GAME
#define _GAME


#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include "Gare.h"
#include <map>
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
		unsigned int firstDice() const;
		unsigned int secondeDice() const;
		bool checkDouble();
		unsigned int getId(int index) const;
		Player * getPlayerById(int id);
		Tile * getTileById(int tile_id);
		int getPlayerPosition(int id);
		void movePlayer(int id, int how_much);
		void buyTile(int id, unsigned int property_id);
		void sellTile(int id, unsigned int property_id);
		void pay(int id, int amount);
		void printPlayerProperties(int id);
};

#endif