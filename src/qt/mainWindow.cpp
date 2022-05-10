#include "mainWindow.h"
#include "../core/Game.h"
#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>

Window::Window() : QWidget(){

	this->setMinimumSize(QSize(1280, 720));

	sidebar = new sideBar(this);
	mainview = new mainView(this);
	game = new Game(2);

	layout = new QHBoxLayout(this);
	setLayout(layout);

	QSizePolicy sidebarPolicy = sidebar->sizePolicy();
	sidebarPolicy.setHorizontalStretch(1);
	sidebar->setSizePolicy(sidebarPolicy);
 
	QSizePolicy mainviewPolicy = mainview->sizePolicy();
	mainviewPolicy.setHorizontalStretch(2);
	mainview->setSizePolicy(mainviewPolicy);

	layout->addWidget(mainview);
	layout->addWidget(sidebar);

	this->setStyleSheet("background-color:white");
	connect(sidebar, SIGNAL(check(bool)), this, SLOT(displayTwoDice()) );
}

void Window::displayTwoDice() {
	qDebug() << "Enter";
	game->rollDice();
	qDebug() << game->firstDice();
	qDebug() << game->secondDice();
}

