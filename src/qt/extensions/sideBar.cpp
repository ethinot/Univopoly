#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include "sideBar.h"

sideBar::sideBar(QWidget *parent, std::vector<Player> new_players) : QWidget(parent){
	controllers = new Controllers(this);
	layout = new QGridLayout(this);
	players = new Players(this, new_players);

	layout->addWidget(controllers, 0, 0);
	layout->addWidget(players, 1, 0);

	this->setStyleSheet("background-color:red");
	connect(controllers, SIGNAL(diceButton()), this , SIGNAL(rollDices()));
	connect(controllers, SIGNAL(passButton()), this , SIGNAL(passTurn()));
	connect(this, SIGNAL(renderPlayers(std::vector<Player>)), players, SIGNAL(render(std::vector<Player>)));
	
}