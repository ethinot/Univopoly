#ifndef SIDEBAR_H
#define SIDEBAR_H


#include "components/sideBar/Controllers.h"
#include <QWidget>

class QPushButton;

class sideBar : public QWidget{
	Q_OBJECT
	public:
		explicit sideBar(QWidget *parent = 0);
	signals: 
		void rollDices();
		void passTurn();
	private:
		Controllers *controllers;	
};

#endif // SIDEBAR_H
