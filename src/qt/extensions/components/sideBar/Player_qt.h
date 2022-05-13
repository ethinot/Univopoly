#ifndef PLAYER_QT_H
#define PLAYER_QT_H


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
#include "../../../../core/Player.h"

//class QPushButton;

class Player_qt : public QWidget{
	public:
		explicit Player_qt(QWidget *parent = 0, Player *player = 0);
		void addWidget(QWidget *widget);
	private:
		Player *player;
		QLabel *name;
		QPushButton *head;
		QPushButton *money;
		QGridLayout *properties;
		QGridLayout *layout;
		void loadProperties();
	
};

#endif // WINDOW_H
