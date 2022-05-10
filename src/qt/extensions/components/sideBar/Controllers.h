#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <QWidget>


class QPushButton;

class Controllers : public QWidget{
	Q_OBJECT
	public:
		explicit Controllers(QWidget *parent = 0);
	private slots:
		//void rolled(bool rolled);
		//void buyButtonClicked(bool clicked);
	
	signals:
		void diceButton(bool emited);
	
	private:
		QPushButton *roll;
		QPushButton *buy; 
};

#endif // CONTROLLERS_H
