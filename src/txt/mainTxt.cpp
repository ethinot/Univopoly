#include "Gametxt.h"
#include <iostream>
#include <stdio.h>

int main(int argc, char ** argv){
    
    std::cout<<"**************************************************"<std::endl;
    std::cout<<"**       Bienvenue dans le jeu UNIVOPOLY        **"<std::endl;
    std::cout<<"****                                         *****"<std::endl;
    std::cout<<"**************************************************"<std::endl;
    std::cout<<"**************************************************"<std::endl;
    std::cout<<"**************************************************"<std::endl;
    
    txtInit();

    txtBoucle();

    txtFin();

    return 0;
}