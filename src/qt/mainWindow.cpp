#include "mainWindow.h"
#include "../core/Game.h"
#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>

Window::Window() : QWidget(){

	this->setMinimumSize(QSize(1280, 720));
	game = new Game(2);
	sidebar = new sideBar(this);
	mainview = new mainView(this, game->getBoard());

	layout = new QHBoxLayout(this);
	setLayout(layout);

	QSizePolicy sidebarPolicy = sidebar->sizePolicy();
	sidebarPolicy.setHorizontalStretch(1);
	sidebar->setSizePolicy(sidebarPolicy);
 
	QSizePolicy mainviewPolicy = mainview->sizePolicy();
	mainviewPolicy.setHorizontalStretch(3);
	mainview->setSizePolicy(mainviewPolicy);

	layout->addWidget(mainview);
	layout->addWidget(sidebar);


	this->setStyleSheet("background-color:black");

	current_player_index = 0;


	// roll dice
	connect(sidebar, SIGNAL(rollDices()), this, SLOT(rollingDice()));


	// move player
	connect(this, SIGNAL(diceRolled(int)), this, SLOT(movingPlayer(int)));
	connect(this, SIGNAL(playerMoved(std::vector<Player>)), mainview, SIGNAL(renderBoard(std::vector<Player>)));

	// pass turn
	connect(sidebar, SIGNAL(passTurn()), this, SLOT(passingTurn()));
}


void Window::rollingDice(){
	qDebug() << "Rolling Dices";
	game->rollDice();
	emit diceRolled(game->firstDice() + game->secondDice());
}

void Window::movingPlayer(int amount){
	qDebug() << "Moving player";
	game->movePlayer(game->getId(current_player_index), amount);
	qDebug() << game->getPlayerPosition(game->getId(current_player_index));
	emit playerMoved(game->getPlayers());
}

void Window::passingTurn(){
	current_player_index += 1;
	if (current_player_index == game->getGameSize()) current_player_index = 0;

}
