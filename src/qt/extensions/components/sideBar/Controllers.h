#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <QWidget>


class QPushButton;

class Controllers : public QWidget{
	Q_OBJECT
	public:
		explicit Controllers(QWidget *parent = 0);
	signals:
		void dicerolled();
	private slots:
		void rollDiceButtonClicked(bool clicked);
	private:
		QPushButton *m_button;
};

#endif // WINDOW_H
