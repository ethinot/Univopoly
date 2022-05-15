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
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	this->setStyleSheet("background-color: white;");

	roll = new QPushButton(this);
	roll->setIcon(QIcon("img/roll_dice.png"));
	roll->setIconSize(QSize(60, 60));
	roll->setShortcut(tr("r"));
	connect(roll, SIGNAL(clicked()), this, SIGNAL(diceButton()));
	connect(roll, SIGNAL(clicked()), this, SLOT(disableRoll()));
	connect(roll, SIGNAL(clicked()), this, SLOT(enablePass()));
	
	pass = new QPushButton(this);
	pass->setIcon(QIcon("img/turnPass.png"));
	pass->setIconSize(QSize(60, 60));
	pass->setShortcut(tr("p"));
	disableButton(pass);
	connect(pass, SIGNAL(clicked()), this, SIGNAL(passButton()));
	connect(pass, SIGNAL(clicked()), this, SLOT(disablePass()));
	connect(pass, SIGNAL(clicked()), this, SLOT(enableRoll()));


	sell = new QPushButton(this);
	sell->setIcon(QIcon("img/sell.png"));
	sell->setIconSize(QSize(60, 60));
	sell->setShortcut(tr("s"));
	connect(sell, SIGNAL(clicked()), this, SIGNAL(sellButton()));
	
	tweak = new QPushButton(this);
	tweak->setIcon(QIcon("img/x.png"));
	tweak->setIconSize(QSize(60, 60));
	connect(tweak, SIGNAL(clicked()), this, SIGNAL(tweakButton()));
	//tweak->setVisible(false);

	layout->addWidget(roll, 0, 0);
	layout->addWidget(pass, 0, 1);
	layout->addWidget(sell, 1, 0);
	layout->addWidget(tweak, 2, 0);
}


void Controllers::disableButton(QPushButton* button){
	button->setEnabled(false);
}

void Controllers::enableButton(QPushButton* button){
	button->setEnabled(true);
}

void Controllers::disablePass(){
	qDebug() << "disabling pass";
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