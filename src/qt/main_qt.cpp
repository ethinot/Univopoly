/*
# Installer Qt5
# Ajouter dans le path le chemin vers bin et vers tools/mingw/bin (voir le chemin exacte suivant la version)
# ouvrir un bash
# qmake
# make
# ./release/pacman_qt
*/

#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>

using namespace std;


int main(int argc, char **argv)
{
    
    QApplication app(argc, argv);
    QImage image
    image.load("../../img/Univopoly_board.png");
    return app.exec();

}

