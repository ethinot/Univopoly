#include "Gametxt.h"

void textInit(){

	int nb_player;
	std::cout << "Salut, on joue à combien ?" << std::endl;
    std::cin >> nb_player;
    Game game(nb_player);


}


void txtLoop(Game & game)
{
	int current_player_id, dice_total, current_position;
	do {
			for(unsigned char i = 0 ; i < game.getGameSize(); i++){ // boucle de jeu pour les différents joeurs

				current_player_id = game.getId(i);
				std::cout << "C'est au tour du joueur " << current_player_id << "!"<<std::endl;
				std::cout << "Le joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Vous êtes sur la case " << current_position << "." << std::endl;
				game.movePlayer(current_player_id, dice_total);
				std::cout << "Votre pion se déplace de la casse " << current_position << " à la case " << game.getPlayerPosition(current_player_id) << std::endl;
				
				if (game.checkDouble() == 1) {
					
				}

			}
		} while(game.checkWinner() == -1);
}