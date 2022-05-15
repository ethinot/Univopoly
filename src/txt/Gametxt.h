/**
 * @file Game.h
 * @brief Module Game
 *
 * Module contenant la classe Game. 

 *  
 */
#ifndef _GAMETXT
#define _GAMETXT

#include "../core/Game.h"

/**
 * @brief Initialise tous ce dont le Game a besoin (dés board players)
 * 
 * @param nb_player -> nombre de joueur dans la partie
 * @return un objet game
 */
Game txtInit(int nb_player);

/**
 * @brief Procédure qui affectue la boulce principale du jeu. 
 * 
 * @param game -> objet contenant tous ce dont le jeu à besoin
 */
void txtLoop(Game & game);

/**
 * @brief Procédure qui permet de sauter une ligne sur l'affichage texte
 * 
 */
void lineBreak();

#endif