#include "Gametxt.h"
#include <unistd.h>
#include <termios.h>
#include <unistd.h>

Game txtInit(int nb_player){
    Game game(nb_player);
	return game;
}

void lineBreak(){
	std::cout<<std::endl;
}

void txtLoop(Game & game)
{
	int current_player_id, dice_total, current_position, current_rent;
	
	Tile * current_tile;
	
	char anwser;
	
	bool exit = false;

	do {
		for(unsigned char i = 0 ; i < game.getGameSize(); i++){ // boucle de jeu pour les différents joeurs
			std::cout << "########################################################";

			lineBreak();


			current_player_id = game.getId(i);
			std::cout << std::endl;
			std::cout << "C'est au tour du joueur " << current_player_id << "!" << std::endl;
			lineBreak();

			if (game.checkJail(current_player_id)){
				std::cout << "Vous êtes en prison !!" << std::endl;
			}else{

				std::cout << "Joueur "<< i+1 << " lance les dés..." << std::endl;
				dice_total = game.rollDice();
				std::cout<< "Vous avez fait un "<<game.firstDice()<<" et un "<<game.secondDice()<<std::endl;
				
				game.movePlayer(current_player_id, dice_total);
				
				current_position = game.getPlayerPosition(current_player_id);
				std::cout << "Vous vous déplacez à la case " << current_position << std::endl;
				/*
				if (game.checkDouble() == 1) {
					
				}*/
				lineBreak();
				current_tile = game.getTileById(current_position); // a faire on veut récuperrer la tile sur lequel est le joueurs
				//std::cout << typeid(*current_tile).name() <<std::endl; Debug permet de vérifier qu'elle est le type de la Tile

				std::cout << *current_tile << std::endl;
				lineBreak();
				std::cout << "Tu as: " << game.getPlayerById(current_player_id)->getBalance() << "€" << std::endl;

				if (current_tile->getOwner() == -2){ // Case speciale 
					switch(current_tile->getId()){
						case 0:
							break;
						case 2:
							std::cout<< "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 4:
							std::cout<< "L'AML vous welcome ! l'adhesion va vous coute 50€ :)" << std::endl;
							if (game.pay(current_player_id, 50, -1)){
								std::cout << "L'AML vous remercie !!" << std::endl;
							}else{
								std::cout << "Oops vous n'avais pas assez d'argent" << std::endl;
								if( (game.getPlayerById(current_player_id))->getNetWorth() > 50){
									do{
										std::cout << "Vendre des propriétés" << std::endl;
										game.checkPropertiesToSell(current_player_id);
									}while(!game.pay(current_player_id, 50, -1));
								}else{
									std::cout << "Tu n'as plus assez de capitale tu as perdu ;(" << std::endl;
									game.killPlayer(current_player_id);
								}
							}
							break;
						case 7:
							std::cout<< "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 10:
							std::cout << "Vous êtes en visite dans la Prison" << std::endl;
							break;
						case 12:
							std::cout << "Stage dans la prochain version vous aurai un challenge pour gagner de l'argent" << std::endl;
							break;
						case 17:
							std::cout << "Case Chance pour le moment il ne se passe rien :(" << std::endl;
							break;
						case 20:
							std::cout << "Vous êtes au parc de la tete d'or" << std::endl;
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
							std::cout<< "L'AML vous welcome ! mais l'adhesion va vous coute 50€ :)" << std::endl;
							if (game.pay(current_player_id, 50, -1)){
								std::cout << "L'AML vous remercie !!" << std::endl;
							}else{
								std::cout << "Oops vous n'avais pas assez d'argent" << std::endl;
								if( (game.getPlayerById(current_player_id))->getNetWorth() > 50){
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
						std::cout << "Voudrais-tu l'acheter ? (y/n): "; 
						std::cin >> anwser;
					} while(anwser != 'y' and anwser != 'n');

					switch(anwser){

						case 'y':
							if (game.buyTile(current_player_id, current_position)) std::cout << "Joueur " << current_player_id << " à acheter " << current_tile->getName() << std::endl;
							else std::cout << "Vous avez pas pu acheter " << current_tile->getName() << std::endl;
							break;

						case 'n':
							std::cout << "La prochaine fois peue-être" << std::endl;
							lineBreak();
							break;
					}
				
				// Tile is owned (can be a Property or Gare)
				}else if(current_tile->getOwner() != current_player_id){

					// type Property
					if (typeid(*current_tile).name() == typeid(Property).name()){
						current_rent = static_cast<Property*>(current_tile)->getRent();
						std::cout << "Le loyer est de: " << current_rent << "€" << std::endl;
						if (game.pay(current_player_id, current_rent, current_tile->getOwner())){
							std::cout << "Vous payer " << current_rent << "€ au Joueur " << current_tile->getOwner() << std::endl;
							std::cout << "A la prochaine !!" << std::endl;
						}else{
							std::cout << "Oopsii vous n'avez pas assez d'argent (t'es pauvre)" << std::endl;
							if( (game.getPlayerById(current_player_id))->getNetWorth() > current_rent){
								do{
									std::cout << "Vendre des propriétés" << std::endl;
									game.checkPropertiesToSell(current_player_id);
								}while(!game.pay(current_player_id, current_rent, current_tile->getOwner()));
							}else{
								std::cout << "Tu n'a plus assez de capitale tu as perdu ;( (gros noob)" << std::endl;
								game.killPlayer(current_player_id);
							}
						}
					}

					// type Gare
					else if (typeid(*current_tile).name() == typeid(Gare).name()){
						current_rent = static_cast<Gare*>(current_tile)->getRent( (game.getPlayerById(current_tile->getOwner()))->getGareCount());
						std::cout << "Le loyer est de: "<< current_rent << "€" << std::endl;
						if (game.pay(current_player_id, current_rent, current_tile->getOwner())){
							std::cout << "Vous payer " << current_rent << "€ au Joueur " << current_tile->getOwner() << std::endl;
							std::cout << "A la prochaine !!" << std::endl;
							lineBreak();
						}else{
							std::cout << "Oopsii vous n'avais pas assez d'argent" << std::endl;
							if( (game.getPlayerById(current_player_id))->getNetWorth() > current_rent){
								do{
									std::cout << "Vendre des propriétés" << std::endl;
									game.checkPropertiesToSell(current_player_id);
								}while(!game.pay(current_player_id, current_rent, current_tile->getOwner()));
							}else{
								std::cout << "Tu na plus assez de capitale tu as perdu ;( (gros noob)" << std::endl;
								game.killPlayer(current_player_id);
							}
						}
					}

				}else{
					std::cout << "Vous êtes: " << current_tile->getName() << std::endl;
					lineBreak();
				}
			}

			lineBreak();
			std::cout << "Ce que tu possède: " << std::endl;
			lineBreak();
			game.printPlayerProperties(current_player_id);

			if (game.getPlayerById(current_player_id)->isDead()){
				std::cout << "Vous avais perdu :(" << std::endl;
				game.killPlayer(current_player_id);
			}

			anwser = ' ';
			do{std::cout << "Passer le tour. (y/n): "; std::cin >> anwser;} while(anwser != 'y' and anwser != 'n');
			system("clear");

		}
		lineBreak();
		do {
			std::cout << "Voulez-vous quittez la partie ? (y/n): "; 
			std::cin >> anwser;
		} while(anwser != 'y' and anwser != 'n');
		
		switch(anwser){
			case 'y':
				exit = true;
				break;

			case 'n':
				exit = false;
				break;
		}
		system("clear");

	} while(exit == false && game.checkWinner() == -1);
}
