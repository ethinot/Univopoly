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

class Players : public QWidget{
	Q_OBJECT
	public:
		explicit Players(QWidget *parent = 0, std::vector<Player*> player = std::vector<Player*>());
	signals:
		void render(std::vector<Player*>, int);
		void killPlayerP(int);
	private slots:
		void rendering(std::vector<Player*>, int);
		void killingPlayer(int);
	private:
		void clearLayout(QLayout* layout, bool deleteWidgets = true);
		QVector<Player_qt*> players_qt;
		QGridLayout *layout;
		void loadPlayers(std::vector<Player*> new_players);
		void layoutAddWidgets(int current_player);
};

#endif // WINDOW_H
