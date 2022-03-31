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
	std::cout << "Salut, on joue à combien ?" << std::endl;
    std::cin >> nb_player;
    Game game1 = txtInit(5);
    Game game2 = game1;
    Game game = txtInit(nb_player);

    txtLoop(game);

    txtEnd();

    return 0;
}