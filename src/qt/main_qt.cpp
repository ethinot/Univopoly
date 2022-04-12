#include <iostream>

#include <QtWidgets/QApplication>
#include <QtGui/QImage>
#include <QtWidgets/QLabel>
#include <QPalette>

using namespace std;


int main(int argc, char **argv)
{
    cout << "Hello World!" << endl;

    QApplication app(argc, argv);
    QLabel label;

    //QImage image("/Users/enzo/Desktop/Univopoly_Qt/univopoly/img/Univopoly_Board.png");

    //Palette palette;
    //palette.setColor(label.backgroundRole(), Qt::yellow);
    //label.setPalette(palette);

    label.setPixmap( QPixmap( "/Users/enzo/Desktop/projetp4/Univopoly_Qt/univopoly/img/Univopoly_Board.png" ) );

    label.setScaledContents( true );

    label.setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //label.setPixmap(QPixmap::fromImage(image));

    label.show();

    return app.exec();

}



