#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWindow>
#include <QHBoxLayout>
#include <QLayout>
#include "../core/Game.h"
#include "extensions/mainView.h"
#include "extensions/sideBar.h"


class QPushButton;

class Window : public QWidget{
	Q_OBJECT
 	public:
  		explicit Window();
		QLayout *layout;
	private:
		sideBar *sidebar;
		mainView *mainview;
		Game *game;
	private slots:
		void displayTwoDice();
};

#endif // MAINWINDOW_H
