#include <iostream>
#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <QtGui/QImage>
#include <QtWidgets/QLabel>
#include <QPalette>
#include <QPushButton>

using namespace std;


int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    Window window;
    window.show();
    return app.exec();

}



