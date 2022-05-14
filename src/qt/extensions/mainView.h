#ifndef MAINVIEW_H
#define MAINVIEW_H


#include <QWidget>
#include <QLayout>
#include "components/mainView/Board_qt.h"

class QPushButton;

class mainView : public QWidget{
	Q_OBJECT
	public:
		explicit mainView(QWidget *parent = 0, Board *new_board = 0);
	signals:
		void renderBoard(std::vector<Player*> players, int);
		void buyMenu(int);
		void buyMenuOff();
		void buyTrueM();
		void sellMenu(Player*);
	private:
		Board_qt *board;
		QLayout *layout;
};

#endif // WINDOW_H
