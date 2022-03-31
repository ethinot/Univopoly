/**
 * @file Tile.h
 * @brief Module Tile (case)
 *
 * Module contenant la classe Tile, le classe Tile représente un case du plateau de jeu. 
 * Elle est composée: 
 * 	- D'un id (le numéro de la case de 0 à 39)  
 * 	- D'un string (nom de la case) 
 *	- D'un prix
 * 	- D'un sell_price
 *  - D'un owner représenter par un nombre dans [0..8].
 *  
 */
#ifndef _TILE
#define _TILE

//#include <iostream>
#include <fstream>
#include <string>

class Tile {


protected:

	unsigned int id; /**< id char non signé, les case son numéroter de 0 à 39 */
	std::string name; /**< nom de la case */
	unsigned int price; /**< prix de la case */
	unsigned int sell_price; /**< prix de revent */
	int owner; /**< propriétaire -> -1 si elle appartient a personne / -1 < owner =< 8 si la case est acheter*/

public:

	Tile();
	~Tile();
	virtual void getType();
	
	/**
	* @brief getId() récupère l'id de la case
	* La fonction getId -> ne prend pas de paramètre et renvoie l'id d'une case.
	*/
	unsigned int getId() const;
	
	/**
	* @brief getName() récupère le nom associer à la case
	* La fonction getName -> ne prend pas de paramètre et renvoie le nom d'une case.
	*/
	std::string getName() const;
	
	/**
	* @brief getPrice() récupère le prix associer à la case
	* La fonction getPrice -> ne prend pas de paramètre et renvoie le prix d'une case.
	*/
	unsigned int getPrice() const;
	
	/**
	* @brief getSellPrice() récupère le prix de vente d'une case
	* La fonction getSellPrice -> ne prend pas de paramètre et renvoie le prix d'une case.
	*/
	unsigned int getSellPrice() const; 
	
	/**
	* @brief getOwner() récupère la valeur du joueur de la case
	* La fonction getOwner -> ne prend pas de paramètre et renvoie l'id du joueur qui est le propriétaire ou 
	* -1 si la case n'est pas acheter.
	*/
	int getOwner() const;
	
	/**
	* @brief sold() permet de vendre une case
	* La procédure sold -> ne prend pas de paramètre .
	*/
	void sold();
	
	/**
	* @brief bought(unsigned int) met à jour les propriétaire (owner)
	* La procédure bought -> prend en paramètre l'id de l'acheteur et, 
	* met à jour le propriétaire de la case.
	*/
	void bought(unsigned int); 

	/**
	 * @brief opérateur de surcharge pour afficher les cases (gare/propriété) 
	 * La fontion operator << permet de surchager l'oppérateur de flux cout.
	 * Cela facilite l'affiche d'une case qu'elle soit propriété ou gare.
	 * @param out -> flux de sortie
	 * @param t -> instance de la classe tile, peut être une propriété ou une gare.
	 * @return ostream& 
	 */
	friend std::ostream & operator << (std::ostream &out, const Tile &t);
};

#endif