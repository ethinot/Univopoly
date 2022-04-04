#include "Gametxt.h"

Game txtInit(int nb_player){
    Game game(nb_player);
	return game;
	// check operator = 
}

void lineBreak(){
	std::cout<<std::endl;
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
				lineBreak();

				std::cout << "Joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
				std::cout<< "Vous avez fait un "<<game.firstDice()<<" et un "<<game.secondDice()<<std::endl;
				lineBreak();
				
				game.movePlayer(current_player_id, dice_total);
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Pion se déplace à la casse " << current_position << std::endl;
				/*
				if (game.checkDouble() == 1) {
					
				}*/
				current_tile = game.getTileById(current_position);

				// Tile is a property or Gare and unowned
				if (current_tile->getOwner() == -1){
					
					std::cout << *current_tile << std::endl;

					do {std::cout << "Voudrai-tu l'acheter ? (y/n): "; std::cin >> anwser;} while(anwser != 'y' and anwser != 'n');

					switch(anwser){

						case 'y':
							game.buyTile(current_player_id, current_position);
							std::cout << "Joueur " << current_player_id << " a acheter" << current_tile->getName() << std::endl;
							lineBreak();
							break;

						case 'n':
							std::cout << "La prochaine fois peutetre" << std::endl;
							lineBreak();
							break;
					}
				
				// Tile is owned (can be a Property or Gare)
				}else if(current_tile->getOwner() != current_player_id){
					if (typeid(*current_tile).name() == typeid(Property).name()){
						std::cout << current_tile << std::endl;
						game.pay(current_player_id, static_cast<Property*>(current_tile)->getRent());
					}
					else if (typeid(*current_tile).name() == typeid(Gare).name()){
						std::cout << current_tile << std::endl;
						game.pay(current_player_id, static_cast<Gare*>(current_tile)->getRent(game.getPlayerById(current_tile->getOwner())->getGareCount()));
					}
				}else{
					std::cout << "Tu es chez toi" << current_tile->getName() << std::endl;
					lineBreak();
				}

				std::cout << "Your inventory: " << std::endl;
				game.printPlayerProperties(current_player_id);
			}
			if (game.getPlayerById(current_player_id)->isDead()){
				std::cout << "Vous avais perdu :(" << std::endl;
				game.killPlayer(current_player_id);
			}
		} while(game.checkWinner() == -1);
}





void txtEnd(){

}