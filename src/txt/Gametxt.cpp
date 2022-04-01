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
				std::cout << std::endl;
				std::cout << "C'est au tour du joueur " << current_player_id << "!" << std::endl;
				std::cout<<std::endl;

				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Case actuelle: " << current_position << "." << std::endl;
				
				std::cout << "Le joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
			
				game.movePlayer(current_player_id, dice_total);
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Pion se déplace a la casse " << current_position << std::endl;
				/*
				if (game.checkDouble() == 1) {
					
				}*/
				current_tile = game.getTileById(current_position);

				// Tile is a property and unowned
				if (current_tile->getOwner() == -1){

					std::cout << current_tile << std::endl;

					do {std::cout << "Voudrai-tu l'acheter ? (y/n): "; std::cin >> anwser;} while(anwser != 'y' and anwser != 'n');

					switch(anwser){

						case 'y':
							game.buyTile(current_player_id, current_position);
							std::cout << "Joueur " << current_player_id << " a acheter" << current_tile->getName() << std::endl << std::endl;
							break;

						case 'n':
							std::cout << "La prochaine fois peutetre" << std::endl << std::endl;
							break;
					}
				
				// Tile is owned (can be a Property or Gare)
				}else if(current_tile->getOwner() != current_player_id){
					if (typeid(*current_tile).name() == "Property"){
						std::cout << "Property" << std::endl;
						game.pay(current_player_id, static_cast<Property*>(current_tile)->getRent());
					}
					else if (typeid(*current_tile).name() == "8Gare"){
						std::cout << "Property" << std::endl;
						game.pay(current_player_id, static_cast<Gare*>(current_tile)->getRent(game.getPlayerById(current_tile->getOwner())->getGareCount()));
					}
				}

				std::cout << "Here are your properties: " << std::endl;
				game.printPlayerProperties(current_player_id);
			}
		} while(game.checkWinner() == -1);
}





void txtEnd(){

}