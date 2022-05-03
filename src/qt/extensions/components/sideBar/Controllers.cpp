#include <QApplication>
#include <QPushButton>
#include <QScreen>
#include <QDebug>
#include "Controllers.h"

Controllers::Controllers(QWidget *parent) : QWidget(parent){

	// Create and position the button
	m_button = new QPushButton("Roll Dice", this);
	m_button->setGeometry(10, 10, 80, 30);
	m_button->setCheckable(true);

}

void Controllers::rollDiceButtonClicked(bool clicked){
	if (clicked) emit dicerolled();
}
