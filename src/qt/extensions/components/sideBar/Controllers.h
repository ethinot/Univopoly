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
	private slots:
		void disablePass();
		void enablePass();
		void disableRoll();
		void enableRoll();
	private:
		QPushButton *roll;
		QPushButton *pass; 
		void disableButton(QPushButton* button);
		void enableButton(QPushButton* button);
};

#endif // CONTROLLERS_H
