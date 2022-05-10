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

	connect(this, SIGNAL(renderBoard(std::vector<Player>)), board, SIGNAL(render(std::vector<Player>)));

}
