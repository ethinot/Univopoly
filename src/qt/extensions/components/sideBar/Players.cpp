#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QPixmap>
#include "Players.h"
#include "Player_qt.h"


Players::Players(QWidget *parent, std::vector<Player> new_players) : QGridLayout(parent){
	loadPlayers(new_players);
	layoutAddWidgets();

	connect(this, SIGNAL(render(std::vector<Player>)), this, SLOT(rendering(std::vector<Player>)));

}

void Players::loadPlayers(std::vector<Player> players){
	players_qt.clear();
	for(int i = 0; i < players.size(); i ++){
		players_qt.push_back(new Player_qt(&players[i]));
	}
}

void Players::layoutAddWidgets(){
	for (int i=0; i<players_qt.size(); i++){
		this->addWidget(players_qt[i], 0, i);
	}
}

void Players::rendering(std::vector<Player> new_players){
	qDebug() << "rendering";
	loadPlayers(new_players);
	layoutAddWidgets();
	qDebug() << new_players[0].getNetWorth();
}
