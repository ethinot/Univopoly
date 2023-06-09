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
	head = new QGridLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setMaximumWidth(this->width()+ 10);

	layout->addLayout(head, 0, 0);
	head->setSpacing(10);
	head->setContentsMargins(0, 0, 0, 0);

	QString name = QString::fromStdString(std::string("Player: ") + (std::to_string(player->getId())));
	player_name = new QPushButton(name);
	player_name->setMaximumHeight(20);
	player_name->setStyleSheet("background-color:white; color:black;");
	head->addWidget(player_name, 0, 0);


	head_name = new QPushButton();
	head_name->setIcon(QIcon(QString::fromStdString("img/player" + std::to_string(player->getId()) + ".png")));
	head_name->setMaximumHeight(20);
	head_name->setStyleSheet("background-color:white; color:black;");
	head->addWidget(head_name, 1, 0);

	QString balance = QString::fromStdString(std::string("Money: ") + (std::to_string(player->getBalance())));
	money = new QPushButton(balance);
	money->setMaximumHeight(20);
	money->setStyleSheet("background-color:white; color:black;");
	head->addWidget(money, 2, 0);

	properties = new QGridLayout();
	properties->setSpacing(0);
	layout->addLayout(properties, 3, 0);

	loadProperties();

}


void Player_qt::addWidget(QWidget *widget){
	//playersLayout->addWidget(widget);
}


void Player_qt::loadProperties(){
	for(int i = 0; i < player->getProperties().size(); i++){
		QPushButton *prop_head = new QPushButton(QString::fromStdString(player->getProperties()[i]->getName().c_str()));
		prop_head->setStyleSheet(QString::fromStdString("background-color: " + player->getProperties()[i]->getColor()) + ";color: black;");
		properties->addWidget(prop_head, i, 0);
	}
}


void Player_qt::kill(){
	player_name->setVisible(false);
	money->setVisible(false);
	QPushButton *X_Button = new QPushButton();
	X_Button->setIcon(QIcon("img/x.png"));
	X_Button->setIconSize(QSize(60, 60));
	properties->addWidget(X_Button);
}