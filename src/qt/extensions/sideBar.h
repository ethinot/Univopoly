#ifndef SIDEBAR_H
#define SIDEBAR_H


#include "components/sideBar/Controllers.h"
#include "components/sideBar/Players.h"
#include <QWidget>
#include <QGridLayout>

class QPushButton;

class sideBar : public QWidget{
	Q_OBJECT
	public:
		explicit sideBar(QWidget *parent = 0, std::vector<Player*> players = std::vector<Player*>());
	signals: 
		void rollDices();
		void passTurn();
		void renderPlayers(std::vector<Player*> players, int);
	private:
		Controllers *controllers;
		Players *players;
		QGridLayout *layout;
};

#endif // SIDEBAR_H
