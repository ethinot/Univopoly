#ifndef PLAYERS_H
#define PLAYERS_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLayout>
#include <QVector>
#include "../../../../core/Board.h"
#include "../../../../core/Player.h"
#include "Player_qt.h"


class QPushButton;

class Players : public QGridLayout{
	Q_OBJECT
	public:
		explicit Players(QWidget *parent = 0, std::vector<Player> player = std::vector<Player>());
	signals:
		void render(std::vector<Player>);
	private slots:
		void rendering(std::vector<Player>);
	private:
		QVector<Player_qt*> players_qt;
		void loadPlayers(std::vector<Player> new_players);
		void layoutAddWidgets();
};

#endif // WINDOW_H
