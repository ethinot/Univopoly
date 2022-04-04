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
	int current_player_id, dice_total, current_position, current_rent;
	Tile * current_tile;
	char anwser;
	do {
		for(unsigned char i = 0 ; i < game.getGameSize(); i++){ // boucle de jeu pour les différents joeurs
			std::cout << "#####################################################################";
			std::cout << "#####################################################################";

			//std::cout << typeid(Gare).name() << "   " << typeid(Property).name() << "  " << typeid(*game.getTileById(15)).name() << "  " << typeid(*game.getTileById(39)).name() << std::endl;

			lineBreak();

			current_player_id = game.getId(i);
			std::cout << std::endl;
			std::cout << "C'est au tour du joueur " << current_player_id << "!" << std::endl;
			lineBreak();

			if (game.checkJail(current_player_id)){
				std::cout << "Vous ete en prison !!" << std::endl;
			}else{

				std::cout << "Joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
				std::cout<< "Vous avez fait un "<<game.firstDice()<<" et un "<<game.secondDice()<<std::endl;
				
				game.movePlayer(current_player_id, dice_total);
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Pion se déplace à la casse " << current_position << std::endl;
				/*
				if (game.checkDouble() == 1) {
					
				}*/
				lineBreak();
				current_tile = game.getTileById(current_position);

				std::cout << *current_tile << std::endl;
				lineBreak();
				std::cout << "Tu as: " << game.getPlayerById(current_player_id)->getBalance() << "$" << std::endl;

				if (current_tile->getOwner() == -2){ // Case speciale 
					switch(current_tile->getId()){
						case 0:
							break;
						case 2:
							std::cout<< "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 4:
							std::cout<< "L'AML vous welcome ! mai l'adhesion va vous coute 50$ :)" << std::endl;
							if (game.pay(current_player_id, 50, -1)){
								std::cout << "L'AML vous remercie !!" << std::endl;
							}else{
								std::cout << "Oops vous n'avais pas assez d'argent" << std::endl;
								if(game.getPlayerById(current_player_id)->getNetWorth() > 50){
									do{
										std::cout << "Vendre des propriétés" << std::endl;
										game.checkPropertiesToSell(current_player_id);
									}while(!game.pay(current_player_id, 50, -1));
								}else{
									std::cout << "Tu na plus assez de capitale tu as perdu ;(" << std::endl;
									game.killPlayer(current_player_id);
								}
							}
							break;
						case 7:
							std::cout<< "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 10:
							std::cout << "Vous ete en visite en Prison" << std::endl;
							break;
						case 12:
							std::cout << "Stage dans la prochain version vous aurai un challenge pour gagner de l'argent" << std::endl;
							break;
						case 17:
							std::cout << "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 20:
							std::cout << "Vous ete au parc de la tete d'or" << std::endl;
							break;
						case 22:
							std::cout << "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 28:
							std::cout << "Stage dans la prochain version vous aurai un challenge pour gagner de l'argent" << std::endl;
							break;
						case 30:
							game.sendJail(current_player_id);
							std::cout << "OOOOOOPPSSSS vous partez en prison" << std::endl;
							break;
						case 33:
							std::cout << "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 36:
							std::cout << "Stage dans la prochain version vous aurai un challenge pour gagner de l'argent" << std::endl;
							break;
						case 38:
							std::cout<< "L'AML vous welcome ! mai l'adhesion va vous coute 50$ :)" << std::endl;
							if (game.pay(current_player_id, 50, -1)){
								std::cout << "L'AML vous remercie !!" << std::endl;
							}else{
								std::cout << "Oops vous n'avais pas assez d'argent" << std::endl;
								if(game.getPlayerById(current_player_id)->getNetWorth() > 50){
									do{
										std::cout << "Vendre des propriétés" << std::endl;
										game.checkPropertiesToSell(current_player_id);
									}while(!game.pay(current_player_id, 50, -1));
								}else{
									std::cout << "Tu na plus assez de capitale tu as perdu ;(" << std::endl;
									game.killPlayer(current_player_id);
								}
							}
							break;
					}
				}else if (current_tile->getOwner() == -1){ // Tile is a property or Gare and unowned

					do {
						std::cout << "Voudrai-tu l'acheter ? (y/n): "; 
						std::cin >> anwser;
					} while(anwser != 'y' and anwser != 'n');

					switch(anwser){

						case 'y':
							if (game.buyTile(current_player_id, current_position)) std::cout << "Joueur " << current_player_id << " a acheter " << current_tile->getName() << std::endl;
							else std::cout << "Vous avez pas pu acheter " << current_tile->getName() << std::endl;
							break;

						case 'n':
							std::cout << "La prochaine fois peutetre" << std::endl;
							lineBreak();
							break;
					}
				
				// Tile is owned (can be a Property or Gare)
				}else if(current_tile->getOwner() != current_player_id){
					if (typeid(*current_tile).name() == typeid(Property).name()){
						current_rent = static_cast<Property*>(current_tile)->getRent();
						std::cout << "Le loyer est de: " << current_rent << "$" << std::endl;
						if (game.pay(current_player_id, current_rent, current_tile->getOwner())){
							std::cout << "A la prochaine !!" << std::endl;
						}else{
							std::cout << "Oopsii vous n'avais pas assez d'argent" << std::endl;
							if(game.getPlayerById(current_player_id)->getNetWorth() > current_rent){
								do{
									std::cout << "Vendre des propriétés" << std::endl;
									game.checkPropertiesToSell(current_player_id);
								}while(!game.pay(current_player_id, current_rent, current_tile->getOwner()));
							}else{
								std::cout << "Tu na plus assez de capitale tu as perdu ;(" << std::endl;
								game.killPlayer(current_player_id);
							}
						}
					}
					else if (typeid(*current_tile).name() == typeid(Gare).name()){
						current_rent = static_cast<Gare*>(current_tile)->getRent(game.getPlayerById(current_tile->getOwner())->getGareCount());
						std::cout << "Le loyer est de: "<< current_rent << "$" << std::endl;
						if (game.pay(current_player_id, current_rent, current_tile->getOwner())){
							std::cout << "Vous payer " << current_rent << "$ au Joueur " << current_tile->getOwner() << std::endl;
							std::cout << "A la prochaine !!" << std::endl;
							lineBreak();
						}else{
							std::cout << "Oopsii vous n'avais pas assez d'argent" << std::endl;
							if(game.getPlayerById(current_player_id)->getNetWorth() > current_rent){
								do{
									std::cout << "Vendre des propriétés" << std::endl;
									game.checkPropertiesToSell(current_player_id);
								}while(!game.pay(current_player_id, current_rent, current_tile->getOwner()));
							}else{
								std::cout << "Tu na plus assez de capitale tu as perdu ;(" << std::endl;
								game.killPlayer(current_player_id);
							}
						}
					}
				}else{
					std::cout << "Qui aime pas faire cours a : " << current_tile->getName() << std::endl;
					lineBreak();
				}
			}

			lineBreak();
			std::cout << "Ce que tu possede: " << std::endl;
			lineBreak();
			game.printPlayerProperties(current_player_id);

			if (game.getPlayerById(current_player_id)->isDead()){
				std::cout << "Vous avais perdu :(" << std::endl;
				game.killPlayer(current_player_id);
			}

			anwser = ' ';
			do{std::cout << "Passer le tour. (y/n): "; std::cin >> anwser;} while(anwser != 'y' and anwser != 'n');

		}
	} while(game.checkWinner() == -1);
}





void txtEnd(){

}