#ifndef _GARE
#define _GARE
/**
 * @brief Module Gare
 *  
 * Module contenant la classe Gare, le classe Gare représente un case particulière, une gare. 
 * Elle est composée des toute les données membre et fonction membre du module Tile (héritage) c'est à dire:
 * 	- D'un id (le numéro de la case de 0 à 39)  
 * 	- D'un string (nom de la propriété) 
 *	- D'un prix
 * 	- D'un sell_price
 *  - D'un owner représenter par un nombre dans [0..8].
 * Une Gare à en plus 1 donnée membre:
 * 	- basic_rent (le loyer basique d'une gare)
 *    
 */

#include "Tile.h"

class Gare : public Tile{

	private:
		unsigned int basic_rent; /**< Prix basique d'une gare*/

	public:
		/**
		 * @brief Constructeur d'un objet Gare
		 * 
		 * @param name -> nom 
		 * @param color -> couleur
		 * @param background -> couleur du back
		 * @param id -> numéro de la case
		 * @param price -> prix d'achat
		 * @param sell_price -> prix de vente
		 */
		
		/**
		 * @brief Constructeur d'un objet Gare 
		 * 
		 * @param name 
		 * @param color 
		 * @param background 
		 * @param id 
		 * @param price 
		 * @param sell_price 
		 */
		Gare(std::string name, std::string color, std::string background, unsigned int id, unsigned int price, unsigned int sell_price);
		
		/**
		 * @brief Destructeur d'un object Gare 
		 * 
		 */
		~Gare();

		/**
		 * @brief Accesseur du loyer à payer
		 * La loyer à payer dépend du nombre de gare possèder par le joueur.
		 * @param gare_number -> nombre de gare (constante multiplicative)
		 * @return unsigned int 
		 */
		unsigned int getRent(unsigned int gare_number) const;
};
#endif