#ifndef BOARD_QT_H
#define BOARD_QT_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QButtonGroup>
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
		void render(std::vector<Player*>, int);
		void buy(int);
		void buyOff();
		void buyTrue();
		void buyFalse();
		void sell(Player*);
		void sellOff();
		void sellTrue(int);
		void sellFalse();
	private slots:
		void rendering(std::vector<Player*>, int);
		void buying(int);
		void buyingOff();
		void selling(Player*);
		void sellingOff();
		void processSell();
	private:
		void clearLayout(QLayout* layout, bool deleteWidgets = true);
		QHBoxLayout *centralControls;
		QWidget *buyWidget;
		QWidget *sellWidget;
		QGridLayout *controlslayout;
		QPushButton *property_tobuy;
		QGridLayout *properties;
		QButtonGroup *proptosell;
		QVector<Tile_qt*> tiles;
		void loadProperties(Board *board);
		void layoutAddWidgets();
		QPushButton* buy_button;
		QPushButton* dbuy_button;
		QPushButton* sell_button;
		QPushButton* dsell_button;
};

#endif // WINDOW_H
