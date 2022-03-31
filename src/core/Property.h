/**
 * @file Property.h
 * @brief Module Property
 *  
 * Module contenant la classe Property, le classe Property représente un case particulière, une propriétée. 
 * Elle est composée des toute les données membre et fonction membre du module Tile (héritage) c'est à dire:
 * 	- D'un id (le numéro de la case de 0 à 39)  
 * 	- D'un string (nom de la propriété) 
 *	- D'un prix
 * 	- D'un sell_price
 *  - D'un owner représenter par un nombre dans [0..8].
 * Une propriété à une plus 3 données membre:
 * 	- Un build_price correspondant à un prix d'une salle (maison)
 * 	- Un tableau de loyer (loyer pour un salle deux salles etc..)
 * 	- Un compteur de propiété poser sur le terains
 *    
 */
#ifndef _PROPERTY
#define _PROPERTY

#include "Tile.h"

class Property :  public Tile{

	//virtual int getType()override{ return Tile::TYPE::Property;};
	
	private:
<<<<<<< HEAD
		unsigned int build_price; /**< Prix pour une construction de salle*/
		unsigned int * rent; /**< Tableau d'entier non signé des loyers en fonction du nombre de construction*/
		unsigned int rent_count; /**< Compteur de construction*/
=======
		unsigned int build_price;
		unsigned int * rent;
		unsigned int rent_count;
>>>>>>> a11f19620b73b5a7bc5086feeab9387de7654fc2

	public:
		/**
		 * @brief Constructeur d'un nouveau objet Property
		 * Constructeur qui initialise tous les données membres d'une propriété et, passe le propriétaire à -1
		 * car quand la propriété est crée il n'en a pas encore.
		 * @param name nom de la propriété
		 * @param id id de la propriété
		 * @param price prix de la propriété
		 * @param sell_price prix de ventre
		 * @param new_build_price prix d'une construction
		 * @param rent_0 loyer de basse
		 * @param rent_1 loyer avec 1 salle
		 * @param rent_2 loyer avec 2 salles
		 * @param rent_3 loyer avec 3 salles
		 * @param rent_4 loyer avec 4 salles
		 * @param rent_5 loyer avec un amphithéatre
		 */
		Property(std::string name, unsigned int id, unsigned int price, unsigned int sell_price,
		unsigned int new_build_price, unsigned int rent_0, 
		unsigned int rent_1, unsigned int rent_2, unsigned int rent_3,
		unsigned int rent_4, unsigned int rent_5);
		unsigned int getRent() const;
		unsigned int getBuildPrice() const;
		void rentUpgrade();
		void emptyProperty();
};


#endif