#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <QWidget>
#include <QGridLayout>


class QPushButton;

class Controllers : public QWidget{
	Q_OBJECT
	public:
		explicit Controllers(QWidget *parent = 0);
	signals:
		void diceButton();
		void passButton();
		void sellButton();
		void tweakButton();
	private slots:
		void disablePass();
		void enablePass();
		void disableRoll();
		void enableRoll();
	private:
		QPushButton *roll;
		QPushButton *pass;
		QPushButton *sell; 
		QPushButton *tweak; 
		QGridLayout *layout;
		void disableButton(QPushButton* button);
		void enableButton(QPushButton* button);
};

#endif // CONTROLLERS_H
