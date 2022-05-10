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


Player_qt::Player_qt(Player *input_player) : QWidget(){
	player = input_player;
	layout = new QGridLayout(this);
	//playersLayout = new QHBoxLayout();


	//this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

	
	head = new QPushButton(QString::fromStdString(std::to_string(player->getId())));
	layout->addWidget(head, 0, 0);
	//layout->addLayout(playersLayout, 1, 0);

	QString money = QString::fromStdString(std::string("Money: ") + (std::to_string(player->getNetWorth())));
	footer = new QPushButton(money);
	footer->setStyleSheet("background-color:white; color:black;");
	layout->addWidget(footer, 0, 1);


	//head->setStyleSheet(QString::fromLocal8Bit("background-color: " + tile->getColor() + ";color: black;"));
	
	setStyleSheet("background-color: white; border: 1px solid black;"); //  border: 1px solid black;
}


void Player_qt::addWidget(QWidget *widget){
	//playersLayout->addWidget(widget);
}