#include "Gametxt.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv){
    
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**       Bienvenue dans le jeu UNIVOPOLY        **"<<std::endl;
    std::cout<<"****                                         *****"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    std::cout<<"**************************************************"<<std::endl;
    

    srand((unsigned int)time(NULL));
    
    int nb_player;
    std::string filename = "../../data/tiles.json";
   
    lineBreak();

    do {
	    std::cout << "Salut, on joue à combien ? (1-8):  "; 
        std::cin >> nb_player;
	} while(nb_player != 1 && nb_player != 2 && nb_player != 3 && nb_player != 4 && nb_player != 5 && nb_player != 6 && nb_player != 7 && nb_player != 8 );
    
    Game game = txtInit(nb_player);

    txtLoop(game);

    return 0;
}