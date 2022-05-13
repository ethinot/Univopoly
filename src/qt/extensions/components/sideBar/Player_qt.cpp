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
#include "Player_qt.h"


Player_qt::Player_qt(QWidget *parent, Player *input_player) : QWidget(parent){
	player = input_player;
	layout = new QGridLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setMaximumWidth(this->width());


	head = new QPushButton(QString::fromStdString(std::to_string(player->getId())));
	head->setMaximumHeight(20);
	head->setStyleSheet("background-color:white; color:black;");
	layout->addWidget(head, 0, 0);

	QString balance = QString::fromStdString(std::string("Money: ") + (std::to_string(player->getBalance())));
	money = new QPushButton(balance);
	money->setMaximumHeight(20);
	money->setStyleSheet("background-color:white; color:black;");
	layout->addWidget(money, 1, 0);

	properties = new QGridLayout();
	//properties->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
	layout->setSpacing(10);
	layout->addLayout(properties, 2, 0);

	loadProperties();

	//head->setStyleSheet(QString::fromLocal8Bit("background-color: " + tile->getColor() + ";color: black;"));
	
	setStyleSheet("background-color: white; border: 1px solid black;"); //  border: 1px solid black;
}


void Player_qt::addWidget(QWidget *widget){
	//playersLayout->addWidget(widget);
}


void Player_qt::loadProperties(){
	for(int i = 0; i < player->getProperties().size(); i++){
		head = new QPushButton(QString::fromLocal8Bit(player->getProperties()[i]->getName().c_str()));
		head->setStyleSheet(QString::fromLocal8Bit("background-color: " + player->getProperties()[i]->getColor()) + ";color: black;");
		properties->addWidget(head, i, 0);
	}
}