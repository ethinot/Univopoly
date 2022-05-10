#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <QWidget>


class QPushButton;

class Controllers : public QWidget{
	Q_OBJECT
	public:
		explicit Controllers(QWidget *parent = 0);
	signals:
		void diceButton();
		void passButton();
	
	private:
		QPushButton *roll;
		QPushButton *pass; 
};

#endif // CONTROLLERS_H
