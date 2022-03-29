#include "Game.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char ** argv){
    
    cout<<"**************************************************"<endl;
    cout<<"**       Bienvenue dans le jeu UNIVOPOLY        **"<endl;
    cout<<"****                                         *****"<endl;
    cout<<"**************************************************"<endl;
    cout<<"**************************************************"<endl;
    cout<<"**************************************************"<endl;
    
    unsigned char nb_player;
    unsigned char dice_total;
    unsigned char position_actuel;
    unsigned char position_future;
    bool in_game = true;
    cout<<endl; 
    cout<<"Salut, on joue à combien ?"<<endl;
    cin>>nb_player;
    Game game(nb_player);
    


    do {
        for(unsigned char i = 0 ; i<total_player; i++){ // boucle de jeu pour les différents joeurs
            
            cout<<"C'est au tour du joueur "<< i+1 <<"!"<<endl;
            cout<<"Le joueur "<< i+1 <<" lance les dés..."<<endl;
            game.dice.rollDice();
            dice_total = game.dice.getTotal();
            
            position_actuel = game.Players[i].getPosition();
            cout<<"Vous êtes sur la case "<<position_actuel<<"."<<endl;
            game.Players[i].changePostion(dice_total);
            cout<<"Votre pion se déplace de la casse "<<position_actuel<<" à la case "<<
            
            if (game.dice.checkDouble() == 1) {

            }

        }
    } while(in_game);

    return 0;
}