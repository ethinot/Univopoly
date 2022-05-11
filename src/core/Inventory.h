#ifndef _INVENTORY
#define _INVENTORY
/**
 * @file Inventory.h
 * @brief Module Inventory
 *
 * Module contenant la classe Inventory, le classe Inventory représente un inventaire d'un joueur du jeu. 
 * Elle est composée: 
 * 	- D'un walet (porte monnaie du joueur)  
 * 	- D'une map collection (association d'un id de property et une case) 
 *  
 */

#include <iostream>
#include <vector>
#include <map>
#include "Property.h"

class Inventory{

private:
	int wallet; /**< Porte monnaie*/
	std::map<unsigned int, Tile*> collection; /**< vector -> association d'un indice et un pointeur sur tile */

public:
	/**
	 * @brief Constructeur d'un objet Inventory 
	 * 
	 */
	Inventory();

	/**
	 * @brief Destructeur d'un objet Inventory
	 *  
	 */
	~Inventory();

	/**
	 * @brief retourne la valeur dans le walet
	 * Ici getBalance retourne l'argent que le joeur possède dans sont porte monnaie
	 * @return int 
	 */
	int getBalance() const;

	/**
	 * @brief Vérifie si la mise à jours du porte monnaie est possible 
	 * Modifie la valeur du porte monnaie, avec le changement de wallet négativement ou positivement
	 * @param amount -> valeur positive ou négative à ajouter au porte monnaie
	 * @return true -> si la mise à jour est possible
	 * @return false -> si ce n'est pas possible (solde < 0) 
	 */
	bool changeBalance(int amount);

	/**
	 * @brief Renvoie la valeur de tous les bien que possède un joueur
	 * getNetWorth additionne l'argent contenue dans le porte monnaie ainsi que le valeur de vente que possède un joueur
	 * @return int 
	 */
	int getNetWorth() const;

	/**
	 * @brief Renvoie une référence sur une propriété
	 * 
	 * @param property_id -> l'id de la propriété à récuperer
	 * @return Tile*
	 */
	Tile* getProperty(int property_id);

	/**
	 * @brief ajoute une propriété à la collection d'un joueur
	 * 
	 * @param new_property -> pointeur sur Tile de la propriété à ajouter
	 */
	void addProperty(int property_id, Tile* new_property);

	/**
	 * @brief supprime un propriété de la collection d'un joueur
	 * 
	 * @param property_id -> id de la propriété à suprimer
	 * @return true 
	 * @return false 
	 */
	bool removeProperty(unsigned int property_id);
	
	/**
	 * @brief Renvoie le vector contenant les propriétés qu'un joueur possède
	 * 
	 * @return std::vector<Tile*> 
	 */
	std::map<unsigned int, Tile*> getProperties() const;

	/**
	 * @brief Fonction booléen qui renvoie vrais si le joueur n'a pas de propriété 
	 * 
	 * @return true 
	 * @return false 
	 */
	bool collectionEmpty() const;

	/**
	 * @brief Surcharge de l'oppérateur d'affichage cout <<
	 * Permet l'affichage de l'inventaire d'un joueur via la surcharge de l'oppérateur <<
	 * @param out -> flux de sortie ostream
	 * @param inventory -> référence 
	 * @return std::ostream& 
	 */
	friend std::ostream& operator<< (std::ostream& out, const Inventory& inventory);
	
	/**
	 * @brief Procédure qui se charge de l'affiche de l'inventaire d'un joueur
	 * 
	 * @param gare_count -> nombre de gare possédé par un joueur 
	 */
	void printInventory(int gare_count);

	void testRegInventory();

};

#endif

