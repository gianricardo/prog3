
#include "window.h"
#include "ui_window.h"

#include <iostream>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setSceneRect(this->frameGeometry());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );

    auto item = new CardImage(3, 0);

    item->setPos(5, 0);

    //item->setFlag(QGraphicsItem::ItemIsMovable);

    //scene->addItem(item);

    item->setUp(true);

    game = new OneSuitGame("player", scene);

    game->draw();
}

GameWindow::~GameWindow()
{
    delete ui;
}
