#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QPixmap>
#include "mainView.h"

mainView::mainView(QWidget *parent) : QWidget(parent){
	qDebug() << this->size();
	this->setStyleSheet("background-color: white");
	//this->setStyleSheet("background-image: url(/Users/enzo/Desktop/projetp4/vscode_univopoly_qt/img/Univopoly_Board.png)");
	//QPixmap univopoly_img("/Users/enzo/Desktop/projetp4/vscode_univopoly_qt/img/Univopoly_Board.png");
}
