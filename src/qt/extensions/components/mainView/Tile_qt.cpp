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


Tile_qt::Tile_qt(Tile *input_tile) : QWidget(){
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

	if (tile->getOwner() > -1){
		QString rent;
		qDebug() << typeid(*tile).name();
		if ((typeid(*tile).name() == typeid(Property).name())){
			int current_rent = static_cast<Property*>(tile)->getRent();
			rent = QString::fromStdString(std::to_string(tile->getOwner()) + " Rent: " + (std::to_string(current_rent)) );
		}/*else if ((typeid(*tile).name() == typeid(Gare).name())){
			int current_rent = static_cast<Gare*>(tile)->getRent();
			QString rent = QString::fromStdString(std::string("Rent: ") + (std::to_string(current_rent)) );
		}*/

		footer = new QPushButton(rent);
		footer->setStyleSheet("background-color:grey; color:black;");
		layout->addWidget(footer, 2, 0);
	}


	head->setStyleSheet(QString::fromStdString("background-color: " + tile->getColor()) + ";color: black;");
	setStyleSheet(QString::fromStdString("background-color:" + tile->getBackColor() + ";") + "; border: 1px solid black;"); //  border: 1px solid black;
}	


void Tile_qt::addWidget(QWidget *widget){
	playersLayout->addWidget(widget);
}