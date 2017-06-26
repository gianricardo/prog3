
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

    game = new OneSuitGame("player", scene);

    //game->draw();

}

GameWindow::~GameWindow()
{
    delete ui;

    if(game != nullptr) delete game;
}
