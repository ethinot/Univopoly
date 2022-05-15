#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include "sideBar.h"

sideBar::sideBar(QWidget *parent, std::vector<Player*> new_players) : QWidget(parent){
	layout = new QGridLayout(this);
	controllers = new Controllers(this);
	players = new Players(this, new_players);

	layout->addWidget(players, 0, 0);
	layout->addWidget(controllers, 1, 0);

	this->setStyleSheet("background-color:red");
	
	connect(controllers, SIGNAL(diceButton()), this , SIGNAL(rollDices()));
	connect(controllers, SIGNAL(passButton()), this , SIGNAL(passTurn()));
	connect(controllers, SIGNAL(sellButton()), this , SIGNAL(askSell()));
	connect(controllers, SIGNAL(tweakButton()), this , SIGNAL(tweak()));
	connect(this, SIGNAL(deadPlayerButtons()), controllers, SLOT(disablePass()));
	connect(this, SIGNAL(deadPlayerButtons()), controllers, SLOT(enableRoll()));
	connect(this, SIGNAL(renderPlayers(std::vector<Player*>, int)), players, SIGNAL(render(std::vector<Player*>, int)));
	
}