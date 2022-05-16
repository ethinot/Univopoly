#include <iostream>
#include "mainWindow.h"
#include "Lobby.h"
#include "Handler_qt.h"
#include <QtWidgets/QApplication>
#include <QtGui/QImage>
#include <QtWidgets/QLabel>
#include <QPalette>
#include <QPushButton>
#include <QDebug>

using namespace std;


Handler_qt::Handler_qt() : QWidget(){
	this->setStyleSheet("background-color:#B1D3AD");
	stack = new QStackedWidget(this);
    Lobby *lobby = new Lobby();
	stack->addWidget(lobby);
	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(stack);
    connect(lobby, SIGNAL(endLobby(int)), this, SLOT(startWindow(int)));
	connect(this, SIGNAL(insertedWindow(QWidget*)), stack, SLOT(setCurrentWidget(QWidget*)));
    //connect(window, SIGNAL(endWindow()), this, SLOT(startLobby()));
	setLayout(layout);
}

void Handler_qt::startWindow(int player_number){
    window = new Window(player_number);
	stack->addWidget(window);
	emit insertedWindow(window);
}

void Handler_qt::startLobby(){
    lobby->setVisible(true);
    window->setVisible(false);
}




