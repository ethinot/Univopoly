#ifndef PROPERTY_QT_H
#define PROPERTY_QT_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLayout>
#include <QObject>
#include <QPainter>
#include <QVector>
#include <QLabel>
#include "../../../../core/Tile.h"

//class QPushButton;

class Tile_qt : public QWidget{
	public:
		explicit Tile_qt(Tile *tile = 0, char orientation = 'n');
		void addWidget(QWidget *widget);
	private:
		Tile *tile;
		QLabel *name;
		QPushButton *head;
		QPushButton *footer;
		QHBoxLayout *playersLayout;
		QGridLayout *layout;
		char orientation;
	
};

#endif // WINDOW_H
