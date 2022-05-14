#include "mainWindow.h"
#include "../core/Game.h"
#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>

Window::Window() : QWidget(){

	this->setMinimumSize(QSize(1280, 720));
	game = new Game(4);
	sidebar = new sideBar(this, game->getPlayers());
	mainview = new mainView(this, game->getBoard());

	this->setStyleSheet("background-color:DarkSeaGreen");

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


	current_player_index = 0;


	// roll dice
	connect(sidebar, SIGNAL(rollDices()), this, SLOT(rollingDice()));


	// move player
	connect(this, SIGNAL(diceRolled(int)), this, SLOT(movingPlayer(int)));
	connect(this, SIGNAL(playerMoved(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));

	// pass turn
	connect(sidebar, SIGNAL(passTurn()), this, SLOT(passingTurn()));
	connect(sidebar, SIGNAL(passTurn()), mainview, SIGNAL(buyMenuOff()));
	connect(this, SIGNAL(playersDisplayChange(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));
	connect(this, SIGNAL(boardDisplayChange(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));


	// buy property
	connect(this, SIGNAL(askBuy(int)), mainview, SIGNAL(buyMenu(int)));
	connect(mainview, SIGNAL(buyTrueM()), this, SLOT(buying()));

	// sell prop
	connect(sidebar, SIGNAL(askSell()), this, SLOT(slotSellMenu()));
	connect(this, SIGNAL(signalSellMenu(Player*)), mainview, SIGNAL(sellMenu(Player*)));


	// change player display
	connect(this, SIGNAL(bought(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));
	connect(this, SIGNAL(bought(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));
	connect(this, SIGNAL(tileStart(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));

	//connect(this, SIGNAL())


}

void Window::slotSellMenu(){
	emit signalSellMenu(game->getPlayers()[current_player_index]);
}


void Window::rollingDice(){
	qDebug() << "Rolling Dices";
	game->rollDice();
	emit diceRolled(game->firstDice() + game->secondDice());
}

void Window::movingPlayer(int amount){
	bool start = game->movePlayer(game->getId(current_player_index), amount);
	int current_position = game->getPlayerPosition(game->getId(current_player_index));
	qDebug() << "Moving player: " << current_position;
	emit playerMoved(game->getPlayers(), current_player_index);
	qDebug() << game->getTileById(current_position)->getOwner();
	if (start) emit tileStart(game->getPlayers(), current_player_index);
	if (game->getTileById(current_position)->getOwner() == -1){
		emit askBuy(current_position);
	}else if (game->getTileById(current_position)->getOwner() > 0){
		int rent = 0;
		if (typeid(*game->getTileById(current_position)).name() == typeid(Property).name()){
						rent = static_cast<Property*>(game->getTileById(current_position))->getRent();
		}
		else if (typeid(*game->getTileById(current_position)).name() == typeid(Gare).name()){
						rent = static_cast<Gare*>(game->getTileById(current_position))->getRent( (game->getPlayerById(game->getTileById(current_position)->getOwner()))->getGareCount());
		}
		bool succesful = game->pay(game->getId(current_player_index), rent, game->getTileById(current_position)->getOwner());
		if (succesful) emit playersDisplayChange(game->getPlayers(), current_player_index);
		else if (game->getPlayerById(game->getId(current_player_index))->getNetWorth() > rent){
			game->getPlayerById(game->getId(current_player_index))->findToSell(rent);
			game->pay(game->getId(current_player_index), rent, game->getTileById(current_position)->getOwner());
			emit playersDisplayChange(game->getPlayers(), current_player_index);
			emit boardDisplayChange(game->getPlayers(), current_player_index);
		}else {
			game->getPlayerById(game->getId(current_player_index))->killMe();
			emit playersDisplayChange(game->getPlayers(), current_player_index);
			emit boardDisplayChange(game->getPlayers(), current_player_index);
		}
	}
}

void Window::passingTurn(){
	qDebug() << "Passing turn";
	current_player_index += 1;
	if (current_player_index == game->getGameSize()) current_player_index = 0;
	playersDisplayChange(game->getPlayers(), current_player_index);
	boardDisplayChange(game->getPlayers(), current_player_index);
}

void Window::buying(){
	qDebug() << current_player_index;
	game->buyTile( game->getId(current_player_index), game->getPlayerPosition(game->getId(current_player_index)));
	qDebug() << game->getTileById(game->getPlayerPosition(game->getId(current_player_index)))->getPrice();
	emit bought(game->getPlayers(), current_player_index);
}
