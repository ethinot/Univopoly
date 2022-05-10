#ifndef BOARD_QT_H
#define BOARD_QT_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLayout>
#include <QVector>
#include "Tile_qt.h"
#include "../../../../core/Board.h"
#include "../../../../core/Player.h"


class QPushButton;

class Board_qt : public QGridLayout{
	Q_OBJECT
	public:
		explicit Board_qt(QWidget *parent = 0, Board *board = 0);
		Board *board;
	signals:
		void render(std::vector<Player>);
		void buy(int);
		void buyOff();
		void buyTrue(int);
		void buyFalse();
	private slots:
		void rendering(std::vector<Player>);
		void buying(int);
		void buyingOff();
	private:
		QWidget *centralControls;
		QVector<Tile_qt*> tiles;
		void loadProperties(Board *board);
		void layoutAddWidgets();
		QPushButton* buy_button;
		QPushButton* dbuy_button;
};

#endif // WINDOW_H
