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
  		explicit Window(int new_total_player = 2, QWidget *parent = 0);
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
		void sold(std::vector<Player*>, int);
		void deadPlayer(int);
		void endWindow();
	private slots:
		void rollingDice();
		void movingPlayer(int amount);
		void passingTurn();
		void buying();
		void slotSellMenu();
		void selling(int);
		void tweaking();
};

#endif // MAINWINDOW_H
