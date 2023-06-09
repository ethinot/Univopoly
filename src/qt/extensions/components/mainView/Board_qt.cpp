#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include <QScreen>
#include <QDebug>
#include <QWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QPixmap>
#include "Board_qt.h"
#include <cmath>


Board_qt::Board_qt(QWidget *parent, Board *new_board) : QGridLayout(parent){
	board = new_board;
	loadProperties(board);
	layoutAddWidgets();


	centralControls = new QHBoxLayout();

	buyWidget = new QWidget();
	QVBoxLayout *buylayout = new QVBoxLayout(buyWidget);
	buylayout->setSpacing(50);
	buyWidget->setStyleSheet("background-color:#B1D3AD");
	property_tobuy = new QPushButton();
	QHBoxLayout *buybuttons = new QHBoxLayout();
	buy_button = new QPushButton(buyWidget);
	buy_button->setIcon(QIcon("img/buy.png"));
	buy_button->setIconSize(QSize(60, 60));
	buy_button->setStyleSheet("background-color: rgba(0, 0, 0, 0.2);");
	buy_button->setShortcut(tr("b"));
	dbuy_button = new QPushButton(buyWidget);
	dbuy_button->setIcon(QIcon("img/dontBuy.png"));
	dbuy_button->setIconSize(QSize(60, 60));
	dbuy_button->setStyleSheet("background-color: rgba(0, 0, 0, 0.2);");
	dbuy_button->setShortcut(tr("d"));

	buybuttons->addWidget(buy_button);
	buybuttons->addWidget(dbuy_button);
	buylayout->addWidget(property_tobuy);
	buylayout->addLayout(buybuttons);
	
	buyWidget->setVisible(false);

	centralControls->addWidget(buyWidget, Qt::AlignCenter );

	proptosell = new QButtonGroup;
	sellWidget = new QWidget();
	sellWidget->setStyleSheet("background-color:#B1D3AD");
	QVBoxLayout *selllayout = new QVBoxLayout(sellWidget);
	properties = new QGridLayout();
	QHBoxLayout *sellbuttons = new QHBoxLayout();
	sell_button = new QPushButton(buyWidget);
	sell_button->setIcon(QIcon("img/deal.png"));
	sell_button->setIconSize(QSize(60, 60));
	sell_button->setStyleSheet("background-color: rgba(0, 0, 0, 0.2);");
	sell_button->setShortcut(tr("b"));
	dsell_button = new QPushButton(buyWidget);
	dsell_button->setIcon(QIcon("img/x.png"));
	dsell_button->setIconSize(QSize(60, 60));
	dsell_button->setStyleSheet("background-color: rgba(0, 0, 0, 0.2);");
	dsell_button->setShortcut(tr("d"));


	sellbuttons->addWidget(sell_button);
	sellbuttons->addWidget(dsell_button);
	selllayout->addLayout(properties);
	selllayout->addLayout(sellbuttons);

	centralControls->addWidget(sellWidget, Qt::AlignCenter);

	sellWidget->setVisible(false);


	this->addLayout(centralControls, 4, 4, 3, 3);
	this->setContentsMargins(0, 0, 0, 0);
	this->setSpacing(0);

	connect(this, SIGNAL(render(std::vector<Player*>, int)), this, SLOT(rendering(std::vector<Player*>, int)));
	connect(this, SIGNAL(buy(int)), this, SLOT(buying(int)));
	connect(this, SIGNAL(buyOff()), this, SLOT(buyingOff()));

	connect(dbuy_button, SIGNAL(clicked()), this, SLOT(buyingOff()));
	connect(dbuy_button, SIGNAL(clicked()), this, SIGNAL(buyFalse()));

	connect(buy_button, SIGNAL(clicked()), this, SLOT(buyingOff()));
	connect(buy_button, SIGNAL(clicked()), this, SIGNAL(buyTrue()));


	connect(dsell_button, SIGNAL(clicked()), this, SLOT(sellingOff()));
	connect(dsell_button, SIGNAL(clicked()), this, SIGNAL(sellFalse()));

	connect(sell_button, SIGNAL(clicked()), this, SLOT(processSell()));
	//connect(sell_button, SIGNAL(clicked()), this, SLOT(sellingOff()));
	connect(this, SIGNAL(sellOff()), this, SLOT(sellingOff()));


	connect(this, SIGNAL(sell(Player*)), this, SLOT(selling(Player*)));

}

void Board_qt::loadProperties(Board *board){
	tiles.clear();
	for(int i = 0; i < board->getSize(); i ++){
		tiles.push_back(new Tile_qt(board->getTile(i)));
	}
}

void Board_qt::layoutAddWidgets(){
	this->addWidget(tiles[0], 10, 10);
	this->addWidget(tiles[10], 10, 0);
	this->addWidget(tiles[20], 0, 0);
	this->addWidget(tiles[30], 0, 10);

	for (int i=1; i<10; i++){
		this->addWidget(tiles[i], 10, 10-i);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[10+i], 10-i, 0);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[20+i], 0, i);
	}
	for (int i=1; i<10; i++){
		this->addWidget(tiles[30+i], i, 10);
	}
}

void Board_qt::rendering(std::vector<Player*> players, int current_player){
	qDebug() << "rendering";
	loadProperties(board);
	layoutAddWidgets();
	for(int i = 0; i < (int)players.size(); i++){
		QPushButton *tmp_widget = new QPushButton();
		tmp_widget->setIcon(QIcon(QString::fromStdString("img/player" + std::to_string(players[i]->getId()) + ".png")));
		if (i == current_player) tmp_widget->setStyleSheet("background-color: Lime; color:black; border: 2px solid DodgerBlue;");
		tiles[players[i]->getPosition()]->addWidget(tmp_widget);
	}
}


void Board_qt::buying(int Tile_id){
	qDebug() << "Showing buy menu";
	property_tobuy->setText(QString::fromStdString(board->getTile(Tile_id)->getName()));
	property_tobuy->setStyleSheet(QString::fromStdString("background-color: " + board->getTile(Tile_id)->getColor()) + ";color: black;");
	buyWidget->setVisible(true);
}

void Board_qt::buyingOff(){
	qDebug() << "Off buy menu";
	buyWidget->setVisible(false);
}

void Board_qt::sellingOff(){
	qDebug() << "Off sell menu";
	sellWidget->setVisible(false);
}

void Board_qt::selling(Player *player){
	qDebug() << "Selling Board";
	std::vector<Tile*> owned = player->getProperties();
	clearLayout(properties);
	for (int i = 0; i < owned.size(); i++){
		QRadioButton *tmp_prop = new QRadioButton(QString::fromStdString(owned[i]->getName() + " Sell: " + std::to_string(owned[i]->getSellPrice())));
		tmp_prop->setStyleSheet(QString::fromStdString("background-color: " + owned[i]->getColor()) + ";color: black;");
		proptosell->addButton(tmp_prop, owned[i]->getId());
		properties->addWidget(tmp_prop, ceil(i/2), i%2);
	}
	sellWidget->setVisible(true);
}


void Board_qt::clearLayout(QLayout* layout, bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}


void Board_qt::processSell(){
	qDebug() << "Processing sell";
	emit sellingOff();
	emit sellTrue(proptosell->checkedId());
}
