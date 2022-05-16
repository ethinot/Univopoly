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
	//connect(this, SIGNAL(playerDead()), sidebar, SIGNAL(passTurn()));
	connect(this, SIGNAL(playerDead()), sidebar, SIGNAL(deadPlayerButtons()));
	connect(sidebar, SIGNAL(passTurn()), this, SLOT(passingTurn()));
	connect(sidebar, SIGNAL(passTurn()), mainview, SIGNAL(buyMenuOff()));
	connect(sidebar, SIGNAL(passTurn()), mainview, SIGNAL(sellMenuOff()));
	connect(this, SIGNAL(playersDisplayChange(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));
	connect(this, SIGNAL(boardDisplayChange(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));


	// buy property
	connect(this, SIGNAL(askBuy(int)), mainview, SIGNAL(buyMenu(int)));
	connect(mainview, SIGNAL(buyTrueM()), this, SLOT(buying()));

	// sell prop
	connect(sidebar, SIGNAL(askSell()), this, SLOT(slotSellMenu()));
	connect(this, SIGNAL(signalSellMenu(Player*)), mainview, SIGNAL(sellMenu(Player*)));
	connect(mainview, SIGNAL(sellTrueM(int)), this, SLOT(selling(int)));
	connect(this, SIGNAL(sold(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));
	connect(this, SIGNAL(sold(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));


	// change player display
	connect(this, SIGNAL(bought(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));
	connect(this, SIGNAL(bought(std::vector<Player*>, int)), mainview, SIGNAL(renderBoard(std::vector<Player*>, int)));
	connect(this, SIGNAL(tileStart(std::vector<Player*>, int)), sidebar, SIGNAL(renderPlayers(std::vector<Player*>, int)));

	//tweak
	connect(sidebar, SIGNAL(tweak()), this, SLOT(tweaking()));

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
	qDebug() << "Moving Player";
	bool start = game->movePlayer(game->getId(current_player_index), amount);
	int current_position = game->getPlayerPosition(game->getId(current_player_index));
	emit playerMoved(game->getPlayers(), current_player_index);
	if (start) emit tileStart(game->getPlayers(), current_player_index);
	if (game->getTileById(current_position)->getOwner() == -1 && game->getTileById(current_position)->getPrice() <= game->getPlayerById(game->getId(current_player_index))->getNetWorth()  ){
		emit askBuy(current_position);
	}else if (game->getTileById(current_position)->getOwner() > 0 && game->getTileById(current_position)->getOwner() != game->getId(current_player_index)){
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
			qDebug() << "Player net worth higher";
			game->getPlayerById(game->getId(current_player_index))->findToSell(rent);
			game->pay(game->getId(current_player_index), rent, game->getTileById(current_position)->getOwner());
			emit playersDisplayChange(game->getPlayers(), current_player_index);
			emit boardDisplayChange(game->getPlayers(), current_player_index);
		}else {
			qDebug() << "Player dead";
			game->killPlayer(game->getId(current_player_index));
			playersDisplayChange(game->getPlayers(), current_player_index);
			boardDisplayChange(game->getPlayers(), current_player_index);
			emit playerDead();
		}
	}
}

void Window::passingTurn(){
	qDebug() << "Passing turn";
	current_player_index += 1;
	if (current_player_index >= game->getGameSize()) current_player_index = 0;
	playersDisplayChange(game->getPlayers(), current_player_index);
	boardDisplayChange(game->getPlayers(), current_player_index);
}

void Window::buying(){
	qDebug() << "Buying";
	game->buyTile( game->getId(current_player_index), game->getPlayerPosition(game->getId(current_player_index)));
	emit bought(game->getPlayers(), current_player_index);
}

void Window::selling(int property_id){
	qDebug() << "Selling";
	game->sellTile(game->getId(current_player_index), property_id);
	emit sold(game->getPlayers(), current_player_index);
}

void Window::tweaking(){
	qDebug() << "Tweaking";
	Player *tmp_player = game->getPlayers()[current_player_index];
	tmp_player->transaction(-(tmp_player->getBalance()-1));
	emit playersDisplayChange(game->getPlayers(), current_player_index);
}
