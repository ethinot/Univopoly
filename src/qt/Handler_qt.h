#include <iostream>
#include "mainWindow.h"
#include "Lobby.h"
#include <QtWidgets/QApplication>
#include <QtGui/QImage>
#include <QtWidgets/QLabel>
#include <QPalette>
#include <QPushButton>
#include <QStackedWidget>

class Handler_qt : public QWidget
{
    Q_OBJECT
    public:
     explicit Handler_qt();
    private:
        Window *window;
        Lobby *lobby;
		QStackedWidget *stack;
    public slots:
        void startWindow(int);
        void startLobby();
	signals:
		void insertedWindow(QWidget*);
};