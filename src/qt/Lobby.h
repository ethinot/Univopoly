#ifndef LOBBY_H
#define LOBBY_H

#include <QWindow>
#include <QHBoxLayout>
#include <QLayout>
#include "../core/Game.h"
#include "extensions/mainView.h"
#include "extensions/sideBar.h"


class QPushButton;

class Lobby : public QWidget{
	Q_OBJECT
 	public:
  		explicit Lobby(QWidget *parent = 0);
	private:
		QPushButton *start;
		QButtonGroup *buttonGroup;
	signals:
		void endLobby(int);
	private slots:
		void endLobbySLOT();
};

#endif // MAINWINDOW_H
