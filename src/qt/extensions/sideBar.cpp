#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include "sideBar.h"

sideBar::sideBar(QWidget *parent) : QWidget(parent){
	controllers = new Controllers(this);
	this->setStyleSheet("background-color:red");
}
