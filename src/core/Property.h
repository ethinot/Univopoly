#ifndef _PROPERTY
#define _PROPERTY
/**
 * @brief Module Property
 *  
 * Module contenant la classe Property, le classe Property représente un case particulière, une propriétée. 
 * Elle est composée des toute les données membre et fonction membre du module Tile (héritage) c'est à dire:
 * 	- D'un id (le numéro de la case de 0 à 39)  
 * 	- D'un string (nom de la propriété) 
 *	- D'un prix
 * 	- D'un sell_price
 *  - D'un owner représenter par un nombre dans [0..8].
 * Une propriété à en plus 3 données membre:
 * 	- Un build_price correspondant à un prix d'une salle (maison)
 * 	- Un tableau de loyer (loyer pour un salle deux salles etc..)
 * 	- Un compteur de propiété poser sur le terains
 *    
 */

#include "Tile.h"
#include <iostream>
#include <assert.h>
#include <string.h>

class Property :  public Tile{

private:
	unsigned int build_price; /**< Prix pour une construction de salle*/
	unsigned int rent[6]; /**< Tableau d'entier non signé des loyers en fonction du nombre de construction*/
	unsigned int rent_count; /**< Compteur de construction*/

public:
	/**
	 * @brief Constructeur d'un nouveau objet Property
	 * Constructeur qui initialise tous les données membres d'une propriété et, passe le propriétaire à -1
	 * car quand la propriété est crée il n'en a pas encore.
	 * @param name nom de la propriété
	 * @param color nom de la couleur
	 * @param backgroun nom de la couleur du background
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
	Property(std::string name, std::string color, std::string background, unsigned int id, unsigned int price, unsigned int sell_price,
	unsigned int new_build_price, unsigned int rent_0, 
	unsigned int rent_1, unsigned int rent_2, unsigned int rent_3,
	unsigned int rent_4, unsigned int rent_5);
			
	/**
	 * @brief Récupère le loyer 
	 * Récupère le loyer en fonction du nombre de construction sur la case.
	 * 
	 * @return unsigned int 
	 */
	unsigned int getRent() const;
	
	/**
	 * @brief Renvoie le prix d'une construction
	 * Récupère le prix d'une construction lier à la propriété.
	 * @return unsigned int 
	 */
	unsigned int getBuildPrice() const;
	
	/**
	 * @brief Augmente le prix de ventre d'un propriété
	 * Si le proriétaire achète une maison, cela augment le nombre de construction sur le terrain et
	 * augmente par la même occasion le prix de vente (plus 30% du prix d'un batiment)
	 * 
	 */
	void rentUpgrade();
	
	/**
	 * @brief Remet le prix de base d'une propriété
	 * Exemple si un propriétaire veut vendre une propriété, cette dernière doit pouvoir être  racheter au prix d'origine.
	 * 
	 */
	void emptyProperty();
	
	/**
	 * @brief Test de regression pour le module property
	 * Cette procédure permet de tester les fonction et procédure hériter du module "Tile". 
	 * 
	 */
	void testRegProperty();
};


#endif