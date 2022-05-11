#include "mainWindow.h"
#include "../core/Game.h"
#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>

Window::Window() : QWidget(){

	this->setMinimumSize(QSize(1280, 720));
	game = new Game(2);
	sidebar = new sideBar(this, game->getPlayers());
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
	connect(sidebar, SIGNAL(passTurn()), mainview, SIGNAL(buyMenuOff()));


	// buy property
	connect(this, SIGNAL(askBuy(int)), mainview, SIGNAL(buyMenu(int)));
	connect(mainview, SIGNAL(buyTrueM()), this, SLOT(buying()));

	// pay rent


	// change player display
	connect(this, SIGNAL(bought(std::vector<Player>)), sidebar, SIGNAL(renderPlayers(std::vector<Player>)));

	//connect(this, SIGNAL())


}


void Window::rollingDice(){
	qDebug() << "Rolling Dices";
	game->rollDice();
	emit diceRolled(game->firstDice() + game->secondDice());
}

void Window::movingPlayer(int amount){
	game->movePlayer(game->getId(current_player_index), amount);
	int current_position = game->getPlayerPosition(game->getId(current_player_index));
	qDebug() << "Moving player: " << current_position;
	emit playerMoved(game->getPlayers());
	qDebug() << game->getTileById(current_position)->getOwner();
	if (game->getTileById(current_position)->getOwner() == -1){
		emit askBuy(current_position);
	}
}

void Window::passingTurn(){
	qDebug() << "Passing turn";
	current_player_index += 1;
	if (current_player_index == game->getGameSize()) current_player_index = 0;

}

void Window::buying(){
	qDebug() << current_player_index;
	game->buyTile( game->getId(current_player_index), game->getPlayerPosition(game->getId(current_player_index)));
	qDebug() << game->getTileById(game->getPlayerPosition(game->getId(current_player_index)))->getPrice();
	emit bought(game->getPlayers());
}
