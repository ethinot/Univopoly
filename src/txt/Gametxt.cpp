#include "Gametxt.h"

Game txtInit(int nb_player){
    Game game(nb_player);
	return game;
	// check operator = 
}


void txtLoop(Game & game)
{
	int current_player_id, dice_total, current_position;
	Tile * current_tile;
	char anwser;
	do {
			for(unsigned char i = 0 ; i < game.getGameSize(); i++){ // boucle de jeu pour les différents joeurs

				current_player_id = game.getId(i);
				std::cout << "C'est au tour du joueur " << current_player_id << "!"<<std::endl;
				std::cout << "Le joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Vous êtes sur la case " << current_position << "." << std::endl;
				game.movePlayer(current_player_id, dice_total);
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Votre pion se déplace a la casse " << current_position << std::endl;
				/*
				if (game.checkDouble() == 1) {
					
				}*/
				current_tile = game.getTileById(current_position);
				if (current_tile->getOwner() == -1){
					std::cout << "Tu vien d'aterrire sur " << current_tile->getName() << " c'est ton jour de chance." << std::endl;
					std::cout << "Voudrai-tu l'acheter ? (o/n)";
					do {std::cin >> anwser;}while(anwser != 'y' or anwser != 'n');
					switch(anwser){
						case 'y':
							game.buyTile(current_player_id, current_position);
							std::cout << "Joueur " << current_player_id << " a acheter" << current_tile->getName() << std::endl;
							break;
						case 'n':
							std::cout << "La prochaine fois peutetre" << std::endl;
							break;
					}
				}else if(current_tile->getOwner() != current_player_id){
					if (typeid(*current_tile).name() == "Property"){
						std::cout << "Property" << std::endl;
						game.pay(current_player_id, static_cast<Property*>(current_tile)->getRent());
					}
					else if (typeid(*current_tile).name() == "8Gare"){
						std::cout << "Property" << std::endl;
						game.pay(current_player_id, static_cast<Property*>(current_tile)->getRent());
					}
				}
			}
		} while(game.checkWinner() == -1);
}





void txtEnd(){

}