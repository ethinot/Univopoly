#include <iostream>
#include "mainWindow.h"
#include "Lobby.h"
#include <Handler_qt.h>
#include <QtWidgets/QApplication>
#include <QtGui/QImage>
#include <QtWidgets/QLabel>
#include <QPalette>
#include <QPushButton>

using namespace std;


int main(int argc, char **argv )
{
    srand((unsigned int)time(NULL));
    QApplication app (argc, argv);

    Handler_qt handler;

    handler.show();

    return app.exec();
}



