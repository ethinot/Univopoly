#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include "sideBar.h"

sideBar::sideBar(QWidget *parent) : QWidget(parent){
	controllers = new Controllers(this);
	this->setStyleSheet("background-color:white");
	connect(controllers, SIGNAL(diceButton(bool)), this ,SIGNAL(check(bool)) );
}

/*
void sideBar::sendToMain(bool emited){
	qDebug() << "Ok 2";
	if (emited) emit check(emited);
}
*/