/**
 * @file Game.h
 * @brief Module Game 
 *
 * Module contenant la classe Game, la classe Game représente le jeu. 
 * Elle est composée: 
 * 	- D'un board_game (plateau de jeu)  
 * 	- De players (un tableau dynamique de joueurs) 
 *	- De total_players (le nombre total de joueurs)
 * 	- D'un dés
 *  
 */
#ifndef _GAME
#define _GAME

#include "Board.h"
#include "Player.h"
#include "Dice.h"
#include "Gare.h"
#include <map>
#include <vector>

class Game{

private:
	Board board_game; /**< plateau de jeu*/
	std::vector<Player*> players; /**< tableau dynamique qui stocke les joueurs*/
	int total_player; /**< nombre de joueur*/
	Dice dice; /**< paire de dés */

public:
	
	int parc_money; /**< argent contenue dans le parking gratuit*/

	/**
	 * @brief Fonction qui récupère un joueur 
	 * 
	 * @param id -> id du joueur qu'on veut récupérer
	 * @return Player& -> référence sur un joueur
	 */
	Player* getPlayerById(int id);
	
	/**
	 * @brief Fonction qui récupère une case (chance, propriété, gare etc...)
	 * 
	 * @param tile_id -> id de la case
	 * @return Tile& -> pointeur sur la case
	 */
	Tile* getTileById(int tile_id);
	
	/**
	 * @brief Retourne un pointeur sur le Board
	 * 
	 * @return Board* -> pointeur sur le board
	 */
	Board* getBoard();
	
	/**
	 * @brief Récupère le tableau contenant les joueurs
	 * 
	 * @return std::vector<Player*> -> vector de pointeur de Player
	 */
	std::vector<Player*> getPlayers();
	
	/**
	 * @brief Constructeur d'un objet Game
	 * 
	 * @param total_player -> nombre de joueur
	 */
	Game(int total_player);
	
	/**
	 * @brief Constructeur d'un objet Game à partir d'un fichier 
	 * 
	 * @param total_player -> nombre de joueur
	 * @param filename -> nom du fichier pour initialiser le board
	 */
	Game(int total_player, std::string filename);
	
	/**
	 * @brief Destucteur d'un objet Game
	 * 
	 */
	~Game();
	
	/**
	 * @brief Revoi le nombre de joueur présent dans la partie
	 * 
	 * @return int -> nombre de joueur
	 */
	int getGameSize() const;
		
	/**
	 * @brief Récupere l'id du joueur
	 * 
	 * @return int -> l'id du joueur
	 */
	int getId(int indice) const;
	
	/**
	 * @brief Fonction qui récupère l'index d'un joueur en fonction de sont id  
	 * 
	 * @param id -> id d'un joueur
	 * @return int -> index dans le tableau players correspondant à l'id du joueurs passer en paramètre
	 */
	int getPlayerIndex(int id) const; 

	/**
	 * @brief Récupère la position du joueur correspondant à l'id
	 * 
	 * @param id -> id du joueur recherché
	 * @return int -> position du joueur
	 */
	int getPlayerPosition(int id);
	
	/**
	 * @brief Lance les dés
	 * 
	 * @return int -> somme des deux dés
	 */
	int rollDice();
	
	/**
	 * @brief Renvoie la valeur du premier dé
	 * 
	 * @return unsigned int -> valeur du premier dé
	 */
	unsigned int firstDice() const;
	
	/**
	 * @brief Renvoie la valeur du deuxième dé
	 * 
	 * @return unsigned int -> valeur du deuxième dé
	 */
	unsigned int secondDice() const;
	
	/**
	 * @brief Renvoie vrai si les deux dés forment un double
	 * 
	 * @return true -> double
	 * @return false -> pas de double
	 */
	bool checkDouble() const;
	
	/**
	 * @brief Procédure permetant de déplacer un joueur
	 * 
	 * @param id -> id du joueur à déplacer
	 * @param how_much -> paramètre correspondant à combien doit on déplacer le joueur
	 */
	bool movePlayer(int id, int how_much);
	
	/**
	 * @brief Procédure qui affiche le ou les propriétés posséder par un joueur
 	 * 
	 * @param id -> id du joueur en question
	 */
	void printPlayerProperties(int id);

	/**
	 * @brief Premet à un joueur de payer un autre joueurs ou une taxe
	 * 
	 * @param id -> id du joueur qui doit payer
	 * @param amount -> argent dû
	 * @param reciever_id -> id du joueur qui reçois son loyer
	 * @return true -> vrai si la transaction est un succès
	 * @return false -> faux si la transaction n'a pas eu lieu
	 */
	bool pay(int id, int amount, int receiver_id);
	
	/**
	 * @brief Permet d'acheter une case
	 * 
	 * @param id -> id du joueur qui souhaite acheter une case
	 * @param property_id -> id de la case en question
	 * @return true -> vrai si le joueur a bien pu acheter le case
	 * @return false -> faux si il n'a pas eu les moyen de l'acheter
	 */
	bool buyTile(int palyer_id, unsigned int property_id);

	/**
	 * @brief Premet de vendre une case
	 * 
	 * @param palyer_id -> id du joueur qui souhaite vendre la case en question
	 * @param property_id -> id de la case qui vas être vendu
	 * @return true -> vrai si la case à bien été vendu
	 * @return false -> faux si la case n'a pas été vendu
	 */
	bool sellTile(int palyer_id, unsigned int property_id);

	/**
	 * @brief Procédure qui demande qu'elle propriété le joueur veut vendre et la vend
	 * @param id -> id du joueur
	 */
	void checkPropertiesToSell(int id);
	
	/**
	 * @brief Fonction booléen qui vérifie si un joueur est en prison 
	 * 
	 * @param id -> id d'un joueur
	 * @return true -> vrai si le joueur est en prison
	 * @return false -> faux si l'inverse
	 */
	bool checkJail(int id);
	
	/**
	 * @brief Procédure qui premet d'envoyer le joueur en prison
	 * 
	 * @param id -> id du joueur à envoyer en prison
	 */
	void sendJail(int id);
	
	/**
	 * @brief Procédure qui supprime un joueur 
	 * 
	 * @param id -> id du joueur à surpimer
	 */
	void killPlayer(int id);

	/**
	 * @brief Vérifie si il y'a un gagnant et revoie l'id de ce dernier
	 * 
	 * @return int -> id du joueur gagnant
	 */
	int checkWinner();
};

#endif