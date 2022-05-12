/**
 * @file Player.h
 * @brief Module Player (Joueur)
 *
 * Module contenant la classe Player, le classe Player représente un joueur. 
 * Le module a comme donnée membre:
 * 	- id -> l'id du joueur (1 à 8)
 * 	- goods -> l'inventaire respactif au joueur
 * 	- position -> l'id de la case sur laquel se trouve le joueur
 * 	- jail_count -> -1 si le joueur n'est pas en prison et de 1 à 3 si il l'est
 * 	- number_gare -> nombre de gare posséder par le joueur
 */
#ifndef _PLAYER
#define _PLAYER

#include "Inventory.h"

class Player{

private:
	int id; /**< Id joueur */
	Inventory goods; /**< Inventaire */
	unsigned int position; /**< Position actuel du joueur */
	int jail_count; /**< Compteur de tours en prison (-1 si pas en prison) */
	unsigned int number_gare; /**< nombre de gare */
	bool bot; /**< booléen si joueur est un bot ou non */

public:
	
	/**
	 * @brief Constructeur d'un objet Player par défault
	 * Initialise les différents données membre 
	 */
	Player();
	
	/**
	 * @brief Construct a new Player object avec l'id du joueur en paramètre
	 * Initialise les différents données membre
	 * @param new_id -> id du nouveau joueur crée
	 */
	Player(int new_id);
	
	/**
	 * @brief Récupère l'id du joueur
	 * 
	 * @return unsigned int 
	 */
	int getId() const;
	
	/**
	 * @brief Renvoie combien le joueur à d'argent dans son porte monnaie
	 * 
	 * @return int 
	 */
	int getBalance();
	
	/**
	 * @brief Calcul en renvoie la valeur de tous ce que possède le joueur
	 * NetWorth = valeur de toutes les propriétés + porte monnaie.
	 * @return int 
	 */
	int getNetWorth();
	
	/**
	 * @brief Effecue si possible la transaction d'argent
	 * 
	 * @param amout 
	 * @return true -> si la transaction à été effectué
	 * @return false -> si la transaction à échoué 
	 */
	bool transaction(unsigned int amout);
	
	/**
	 * @brief Renvoie un pointeur sur la propriété dont l'id est le paramètre
	 * 
	 * @param property_id 
	 * @return Tile*
	 */
	Tile* getProperty(unsigned int property_id);
	
	/**
	 * @brief Vérifie si la propriété à bien été acheter 
	 * 
	 * @param property -> la propriété
	 * @return true -> vrai si l'achat a bien pu s'éffectuer
	 * @return false -> faux si l'achat n'a pas abouti
	 */
	bool buyProperty(unsigned int property_id, Tile*property);
	
	/**
	 * @brief Vérifie si la propriété à bien été vendue
	 * 
	 * @param property_id -> id de la propriété à vendre
	 * @return true -> vrai si la propriété à bien été vendue
	 * @return false -> faux si la propriété n'a pas pu être vendue
	 */
	bool sellProperty(unsigned int property_id);
	
	/**
	 * @brief Affiche les propriétés posséder par le joueur
	 * 
	 */
	void printProperties();	

	/**
	 * @brief Récupère le position du joueur
	 * 
	 * @return unsigned int 
	 */
	unsigned int getPosition() const;
	
	/**
	 * @brief Change la positon du joueur
	 * 
	 * @param how_much -> nombre de case correspondant à lavancement
	 */
	bool changePostion(unsigned int how_much);
	
	/**
	 * @brief Envoie le joueur en prison et lance le compteur jail_count
	 * 
	 */
	void goJail();
	
	/**
	 * @brief Vérifie si le joueur est en prison ou non
	 * 
	 * @return true -> vrai si le joueur est en prison
	 * @return false -> faux si il n'est pas en prison
	 */
	bool checkJail();
	
	/**
	 * @brief Vérifie si le joueur ne peux plus jouer (game over)
	 * Si le joueur n'a plus de propriété et d'argent dans son porte monnaie, il ne peut plus jouer.
	 * @return true -> vrai si le joueur ne peut plus jouer
	 * @return false -> faux si il peut continuer de jouer
	 */
	bool isDead() const;
	
	/**
	 * @brief Ajoute une gare au nombre total de gare posséder par le joueur
	 * 
	 */
	void plusGare();
	
	/**
	 * @brief Enlève une gare au nombre total de gare d'un joueur
	 * 
	 */
	void minusGare();
	
	/**
	 * @brief Renvoie le nombre de gare d'un joueur
	 * 
	 * @return unsigned int 
	 */
	unsigned int getGareCount() const;

	/**
	 * @brief Vérifie si un joueur est un bot
	 * 
	 * @return true -> vrai, c'est un bot
	 * @return false -> faux c'est un joueur
	 */
	bool checkBot() const;

	/**
	 * @brief Test de régression du module Player
	 * 
	 */
	void testRegPlayer();
};

#endif