#include "mainWindow.h"
#include "../core/Game.h"
#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QDir>
#include <QInputDialog>
#include <QRadioButton>
#include <QButtonGroup>
#include <QGridLayout>
#include "Lobby.h"
#include <cmath>

Lobby::Lobby(QWidget *parent) : QWidget(parent){

	this->setMinimumSize(QSize(1280, 720));
	this->setStyleSheet("background-color:#B1D3AD;");
	start = new QPushButton(this);
	start->setIcon(QIcon("img/start.png"));
	start->setIconSize(QSize(200, 50 ));
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(start, 0, 1);
	buttonGroup = new QButtonGroup();

	for (int i = 2; i <= 8; i++){
		QRadioButton *tmp_btn = new QRadioButton(QString::fromStdString(std::to_string(i) + "Players"));
		tmp_btn->setStyleSheet(QString::fromStdString("color: black;"));
		buttonGroup->addButton(tmp_btn, i);
		layout->addWidget(tmp_btn, 1+ceil((i-2)/3), (i-2)%3);
	}
	setLayout(layout);

	connect(start, SIGNAL(clicked()), this, SLOT(endLobbySLOT()));
}

void Lobby::endLobbySLOT(){
	emit endLobby(buttonGroup->checkedId());
}

