#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QPixmap>
#include <QString>
#include <QLabel>
#include "Tile_qt.h"


Tile_qt::Tile_qt(Tile *input_tile, char new_orientation) : QWidget(){
	tile = input_tile;
	layout = new QGridLayout(this);
	playersLayout = new QHBoxLayout();


	layout->setRowMinimumHeight(0, this->height()/3);
	layout->setRowMinimumHeight(1, this->height()/3);
	layout->setRowMinimumHeight(2, this->height()/3);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	//this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

	
	head = new QPushButton(QString::fromLocal8Bit(tile->getName().c_str()));
	layout->addWidget(head, 0, 0);
	layout->addLayout(playersLayout, 1, 0);

	if (tile->getOwner() == -1){
		QString price = QString::fromStdString(std::string("Price: ") + (std::to_string(tile->getPrice())) );
		footer = new QPushButton(price);
		footer->setStyleSheet("background-color:white; color:black;");
		layout->addWidget(footer, 2, 0);
	}


	head->setStyleSheet(QString::fromLocal8Bit("background-color: " + tile->getColor() + ";color: black;"));
	
	setStyleSheet("background-color: white; border: 1px solid black;"); //  border: 1px solid black;
}


void Tile_qt::addWidget(QWidget *widget){
	playersLayout->addWidget(widget);
}