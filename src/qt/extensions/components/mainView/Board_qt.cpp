#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QPixmap>
#include "Board_qt.h"


Board_qt::Board_qt(QWidget *parent, Board *new_board) : QGridLayout(parent){
	board = new_board;
	loadProperties(board);
	layoutAddWidgets();
	centralControls = new QWidget();
	centralControls->setStyleSheet("background-color:grey");
	this->addWidget(centralControls, 4, 4, 3, 3);
	this->setContentsMargins(0, 0, 0, 0);
	this->setSpacing(0);	

	connect(this, SIGNAL(render(std::vector<Player>)), this, SLOT(rendering(std::vector<Player>)));
}

void Board_qt::loadProperties(Board *board){
	tiles.clear();
	for(int i = 0; i < board->getSize(); i ++){
		tiles.push_back(new Tile_qt(board->getTile(i)));
	}
}

void Board_qt::layoutAddWidgets(){
	this->addWidget(tiles[0], 10, 10);
	this->addWidget(tiles[10], 10, 0);
	this->addWidget(tiles[20], 0, 0);
	this->addWidget(tiles[30], 0, 10);

	for (int i=1; i<10; i++){
		this->addWidget(tiles[i], 10, 10-i);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[10+i], 10-i, 0);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[20+i], 0, i);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[30+i], i, 10);
	}
}

void Board_qt::rendering(std::vector<Player> players){
	qDebug() << "rendering";
	loadProperties(board);
	layoutAddWidgets();
	qDebug() << players[0].getPosition();
	//tiles[players[0]->getPosition()]->setStyleSheet("background-color: yellow");
	for(int i = 0; i < (int)players.size(); i++){
		QWidget *tmp_widget = new QWidget();
		if (i == 0) tmp_widget->setStyleSheet("background-color: yellow");
		else tmp_widget->setStyleSheet("background-color: blue");
		tiles[players[i].getPosition()]->addWidget(tmp_widget);
	}
}

