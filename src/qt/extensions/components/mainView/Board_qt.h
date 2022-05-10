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
	private slots:
		void rendering(std::vector<Player>);
	private:
		QWidget *centralControls;
		QVector<Tile_qt*> tiles;
		void loadProperties(Board *board);
		void layoutAddWidgets();
};

#endif // WINDOW_H
