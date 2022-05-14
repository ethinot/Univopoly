#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QPixmap>
#include "mainView.h"

mainView::mainView(QWidget *parent, Board* new_board) : QWidget(parent){
	
	board = new Board_qt(this, new_board);

	this->setStyleSheet("background-color: white");

	connect(this, SIGNAL(renderBoard(std::vector<Player*>, int)), board, SIGNAL(render(std::vector<Player*>, int)));
	connect(this, SIGNAL(buyMenu(int)), board, SIGNAL(buy(int)));
	connect(this, SIGNAL(buyMenuOff()), board, SIGNAL(buyOff()));
	connect(board, SIGNAL(buyTrue()), this, SIGNAL(buyTrueM()));

}
