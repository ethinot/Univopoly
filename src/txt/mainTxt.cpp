#include "Gametxt.h"
#include <iostream>
#include <stdio.h>

int main(int argc, char ** argv){
    
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**       Bienvenue dans le jeu UNIVOPOLY        **"<<std::endl;
    std::cout<<"****                                         *****"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    


    int nb_player;
    std::string filename = "../../data/tiles.json";
	std::cout << "Salut, on joue à combien ?: ";
    std::cin >> nb_player;
    Game game = txtInit(nb_player, filename);

    txtLoop(game);

    txtEnd();

    return 0;
}