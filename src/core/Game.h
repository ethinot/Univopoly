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
		Game(int total_player, std::string filename);
		~Game();
		int parc_money;
		int getGameSize() const;
		int checkWinner();
		int rollDice();
		unsigned int firstDice() const;
		unsigned int secondDice() const;
		bool checkDouble();
		bool checkJail(int id);
		void sendJail(int id);
		unsigned int getId(int index) const;
		Player * getPlayerById(int id);
		Tile * getTileById(int tile_id);
		int getPlayerPosition(int id);
		void movePlayer(int id, int how_much);
		bool buyTile(int id, unsigned int property_id);
		bool sellTile(int id, unsigned int property_id);
		bool pay(int id, int amount, int reciever_id);
		void printPlayerProperties(int id);
		int getPlayerIndex(int id);
		void killPlayer(int id);
		void checkPropertiesToSell(int id);
};

#endif