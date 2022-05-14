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
		int current_player_index;
	signals:
		void diceRolled(int amount);
		void playerMoved(std::vector<Player*>, int);
		void askBuy(int);
		void bought(std::vector<Player*>, int);
		void tileStart(std::vector<Player*>, int);
		void playersDisplayChange(std::vector<Player*>, int);
		void boardDisplayChange(std::vector<Player*>, int);
		void signalSellMenu(Player*);
	private slots:
		void rollingDice();
		void movingPlayer(int amount);
		void passingTurn();
		void buying();
		void slotSellMenu();
};

#endif // MAINWINDOW_H
