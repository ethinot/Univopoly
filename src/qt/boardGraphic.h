#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QApplication>
#include <QPixmap>
#include <QGraphicsView>

#include <Board.h>

class BoardGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit BoardGraphicsView(QWidget *parent = nullptr);

    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    QPixmap background;
};


#endif //BOARDWINDOW_H