#include "../core/Board.h"
#include "board_graphique.h"

BoardGraphicsView::BoardGraphiqueView(Qwidget *parent) :
    QGraphicsView(parent),
    background( QApplication:applicationDirPath() + "/img/Univopoly_Board001.png")