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
 * @brief 
 * 
 * @param nb_player 
 * @return Game 
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