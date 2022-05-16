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
#include <cmath>


Players::Players(QWidget *parent, std::vector<Player*> new_players) : QWidget(parent){
	layout = new QGridLayout(this);
	loadPlayers(new_players);
	layoutAddWidgets(0);
	this->setStyleSheet("background-color: white;");
	connect(this, SIGNAL(render(std::vector<Player*>, int)), this, SLOT(rendering(std::vector<Player*>, int)));

}

void Players::loadPlayers(std::vector<Player*> players){
	players_qt.clear();
	for(int i = 0; i < players.size(); i ++){
		players_qt.push_back(new Player_qt(this, players[i]));
	}
}

void Players::layoutAddWidgets(int current_player){
	clearLayout(layout);
	for (int i=0; i<players_qt.size(); i++){
		if (i == current_player) players_qt[i]->setStyleSheet("background-color: LightGreen; color:black; border: 3px solid DodgerBlue;");
		else setStyleSheet("background-color: white; border: 1px solid black;");
		layout->addWidget(players_qt[i], ceil(i/2), i%2);
	}
}

void Players::rendering(std::vector<Player*> new_players, int current_player){
	qDebug() << "rendering";
	loadPlayers(new_players);
	layoutAddWidgets(current_player);
}

void Players::clearLayout(QLayout* layout, bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}
