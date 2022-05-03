#ifndef SIDEBAR_H
#define SIDEBAR_H


#include "components/sideBar/Controllers.h"
#include <QWidget>

class QPushButton;

class sideBar : public QWidget{
	public:
		explicit sideBar(QWidget *parent = 0);
	private:
		Controllers *controllers;
		
};

#endif // WINDOW_H
