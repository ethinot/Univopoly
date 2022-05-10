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
	connect(roll, SIGNAL(clicked()), this, SIGNAL(diceButton()));
	
	// Create and position the button
	pass = new QPushButton(this);
	pass->setIcon(QIcon("img/buy.png"));
	//Check if file exist
	//QFile file("img/buy.png");
	//if(!file.exists()){ qDebug() << "File is not found!" << file.fileName(); }
	//Button settings 
	pass->setIconSize(QSize(60, 60));
	pass->setGeometry(200, 630, 60, 60);
	pass->setShortcut(tr("p"));
	connect(pass, SIGNAL(clicked()), this, SIGNAL(passButton()));
}