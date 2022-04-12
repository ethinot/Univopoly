/**
 * @file Board.h
 * @brief Module Board (Plateau)
 *
 * Module contenant la classe Board, le classe Board le plateau de jeu. 
 * Elle est composée d'un vector (tableau dynamique de STD) de pointeur sur Tile.

 */
#ifndef _BOARD
#define _BOARD

#include "Tile.h"
#include <vector>

class Board{

private:
    std::vector<Tile> game_board; /**< vector de typeTile*/
public:
    
    /**
     * @brief Construct un nouveau objet Board
     * Le board est représenter par un tableau de case (property, gare, special).
     * Construire un board reviens à ajouter des case au vector, ou l'indice du tableau est en corrélation avec l'id d'une case.  
     * 
     */
    Board();
    
    Board(std::string filename); //futur constructeur à partir d'un fichier json
    
    /**
     * @brief Destructeur de l'objet board
     * 
     */
    ~Board();

    /**
     * @brief Fonction qui prend en paramètre l'id d'une propriété et renvoie un pointeur correspondant à l'id passer en paramètre
     * 
     * @param property_id -> id d'une propriété 
     * @return Tile -> renvoie une référence sur Tile qui ne pourra pas être modifier
     */
    const Tile& getTile(unsigned int property_id);
    
    void testRegBoard();
};

#endif