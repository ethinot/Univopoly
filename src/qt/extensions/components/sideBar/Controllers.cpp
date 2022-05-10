#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QDir>
#include "Controllers.h"

Controllers::Controllers(QWidget *parent) : QWidget(parent){
	
	//Create and position the button
	roll = new QPushButton(this);
	roll->setIcon(QIcon("img/roll_dice.png"));
	//Check if file exist
	QFile file("img/roll_dice.png");
	if(!file.exists()){ qDebug() << "File is not found!" << file.fileName(); }
	//Button settings 
	roll->setIconSize(QSize(60, 60));
	roll->setGeometry(140, 630, 60, 60);
	roll->setShortcut(tr("r"));
	//If the button is clicked the signal diceRolled is emit
	connect(roll, SIGNAL(clicked(bool)), this, SIGNAL(diceButton(bool)));
	
	// Create and position the button
	buy = new QPushButton(this);
	buy->setIcon(QIcon("img/buy.png"));
	//Check if file exist
	//QFile file("img/buy.png");
	//if(!file.exists()){ qDebug() << "File is not found!" << file.fileName(); }
	//Button settings 
	buy->setIconSize(QSize(60, 60));
	buy->setGeometry(200, 630, 60, 60);
	buy->setShortcut(tr("b"));
}

/*
void Controllers::rolled(bool rolled) {
	qDebug() << "Ok 1"; 
	if(rolled) emit diceButton(rolled);
}*/