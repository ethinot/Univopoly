/**
 * @file Tile.h
 * @brief Module Tile (case)
 *
 * Module contenant la classe Tile, le classe Tile représente un case du plateau de jeu. 
 * Ell est composée d'un id (le numéro de la case de 0 à 39)  d'un string (nom de la case), d'un price,
 * d'un sell_price et d'un owner représenter par un nombre dans [0..8].
 *  
 */
#ifndef _TILE
#define _TILE

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
	* @brief Procédure qui effectue le teste de regression du module Tile
	* Procédure regressionTestTile -> Test si les fonctions membres du module Tile fonctionnes correctement.
	*/
	void regressionTestTile();
};

#endif