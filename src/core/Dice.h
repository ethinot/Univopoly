/**
 * @file Dice.h
 * @brief Module Dice
 *
 * Module contenant la classe Dice, le classe Dice est composée d'un tableau de deux entier qui représente les deux dés.
 *  
 */
#ifndef _DICE
#define _DICE

class Dice {

private:

	unsigned int * values;  /**< tableau 1D d'entier non signé */

public:

	/**
	* @brief Constructeur par défaut
	* Constucteur de la classe par défaut -> créé un tableau de deux entier non signés sur le tas.
	*/
	Dice();
	
	/**
	* @brief Destructeur par défaut
	* Destructeur de la classe -> suprime le tableau sauvgarder sur le tas.
	*/
	~Dice(); 

	/**
	* @brief Procédure pour lancer les dés
	* Procédure dice -> choisie aléatoirement deux entiers compris dans [1..6].
	*/
	void roll();
	
	/**
	 * @brief Fonction qui renvoie la valeur du premier dés
	 * La valeur du premier dés est sotcké dans un tableau d'entier, le premier dés est donc la case 0 du tableau.
	 * @return unsigned int 
	 */
	unsigned int getFirstDice() const;
	
	/**
	 * @brief Fonction qui renvoie la valeur du deuxième dés
	 * La valeur du second dés est sotcké dans un tableau d'entier, le second dés est donc la case 1 du tableau.
	 * @return unsigned int 
	 */
	unsigned int getSecondDice() const;
	
	/**
	* @brief Fonction qui vérifie si les deux dés sont des doubles
	* @return booléen 
	* Fonction checkDouble -> renvoie vrais ou faux selon si les deux dés formes un double.
	*/
	bool checkDouble() const;  

	/**
	* @brief Fonction qui renvoie la somme des deux dés
	* @return enier non-signé
	* Procédure getTotal -> renvoie la somme des deux dés lancés, le résultat est compris dans [2..12].
	*/
	unsigned int getTotal() const;
	
	/**
	* @brief Procédure qui effectue le teste de regression du module Dice
	* Procédure regressionTestDice -> Test si les fonctions membres du module Dice fonctionnes correctement.
	*/
	void testRegDice();
};

#endif