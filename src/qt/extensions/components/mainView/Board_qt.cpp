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
	QGridLayout *controlslayout = new QGridLayout(centralControls);
	centralControls->setStyleSheet("background-color:DarkSeaGreen");
	property_buying = new QPushButton();
	buy_button = new QPushButton(centralControls);
	buy_button->setIcon(QIcon("img/buy.png"));
	buy_button->setIconSize(QSize(60, 60));
	buy_button->setStyleSheet("background-color:white");
	buy_button->setShortcut(tr("b"));
	dbuy_button = new QPushButton(centralControls);
	dbuy_button->setIcon(QIcon("img/dontBuy.png"));
	dbuy_button->setIconSize(QSize(60, 60));
	dbuy_button->setStyleSheet("background-color:white");
	dbuy_button->setShortcut(tr("d"));

	controlslayout->addWidget(buy_button, 1, 0);
	controlslayout->addWidget(property_buying, 0, 1);
	controlslayout->addWidget(dbuy_button, 1, 2);
	
	centralControls->setVisible(false);

	this->addWidget(centralControls, 4, 4, 3, 3);
	this->setContentsMargins(0, 0, 0, 0);
	this->setSpacing(0);	

	connect(this, SIGNAL(render(std::vector<Player*>)), this, SLOT(rendering(std::vector<Player*>)));
	connect(this, SIGNAL(buy(int)), this, SLOT(buying(int)));
	connect(this, SIGNAL(buyOff()), this, SLOT(buyingOff()));

	connect(dbuy_button, SIGNAL(clicked()), this, SLOT(buyingOff()));
	connect(dbuy_button, SIGNAL(clicked()), this, SIGNAL(buyFalse()));

	connect(buy_button, SIGNAL(clicked()), this, SLOT(buyingOff()));
	connect(buy_button, SIGNAL(clicked()), this, SIGNAL(buyTrue()));

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

void Board_qt::rendering(std::vector<Player*> players){
	qDebug() << "rendering";
	loadProperties(board);
	layoutAddWidgets();
	for(int i = 0; i < (int)players.size(); i++){
		QPushButton *tmp_widget = new QPushButton();
		tmp_widget->setIcon(QIcon(QString::fromStdString("img/player" + std::to_string(players[i]->getId()) + ".png")));
		tiles[players[i]->getPosition()]->addWidget(tmp_widget);
	}
}


void Board_qt::buying(int Tile_id){
	qDebug() << "Showing buy menu";
	property_buying->setText(QString::fromStdString(board->getTile(Tile_id)->getName()));
	property_buying->setStyleSheet(QString::fromLocal8Bit("background-color: " + board->getTile(Tile_id)->getColor()) + ";color: black;");
	centralControls->setVisible(true);
}

void Board_qt::buyingOff(){
	qDebug() << "Off buy menu";
	centralControls->setVisible(false);
}