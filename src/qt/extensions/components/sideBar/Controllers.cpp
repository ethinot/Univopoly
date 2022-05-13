#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QDir>
#include "Controllers.h"

Controllers::Controllers(QWidget *parent) : QWidget(parent){

	layout = new QGridLayout(this);

	this->setStyleSheet("background-color: white;");
	//Create and position the button
	roll = new QPushButton(this);
	roll->setIcon(QIcon("img/roll_dice.png"));
	//Check if file exist
	QFile file("img/roll_dice.png");
	if(!file.exists()){ qDebug() << "File is not found!" << file.fileName(); }
	//Button settings 
	roll->setIconSize(QSize(60, 60));
	roll->setShortcut(tr("r"));
	//If the button is clicked the signal diceRolled is emit
	connect(roll, SIGNAL(clicked()), this, SIGNAL(diceButton()));
	connect(roll, SIGNAL(clicked()), this, SLOT(disableRoll()));
	connect(roll, SIGNAL(clicked()), this, SLOT(enablePass()));
	
	// Create and position the button
	pass = new QPushButton(this);
	pass->setIcon(QIcon("img/turnPass.png"));
	//Check if file exist
	//QFile file("img/buy.png");
	//if(!file.exists()){ qDebug() << "File is not found!" << file.fileName(); }
	//Button settings 
	pass->setIconSize(QSize(60, 60));
	pass->setShortcut(tr("p"));
	connect(pass, SIGNAL(clicked()), this, SIGNAL(passButton()));
	connect(pass, SIGNAL(clicked()), this, SLOT(disablePass()));
	connect(pass, SIGNAL(clicked()), this, SLOT(enableRoll()));

	layout->addWidget(roll, 0, 0);
	layout->addWidget(pass, 0, 1);
}


void Controllers::disableButton(QPushButton* button){
	button->setEnabled(false);
}

void Controllers::enableButton(QPushButton* button){
	button->setEnabled(true);
}

void Controllers::disablePass(){
	disableButton(pass);
}
void Controllers::enablePass(){
	enableButton(pass);
}

void Controllers::disableRoll(){
	disableButton(roll);
}
void Controllers::enableRoll(){
	enableButton(roll);
}