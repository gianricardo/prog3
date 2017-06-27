
#include "window.h"
#include "ui_window.h"

#include <iostream>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window),
    ok_button(nullptr),
    label(nullptr)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setSceneRect(this->frameGeometry());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );

    game = new OneSuitGame("player", scene);

    game->setEventHandler(this);
}

GameWindow::~GameWindow()
{
    delete ui;

    if(game != nullptr) delete game;
}

void GameWindow::gameover_event(bool won){

    if(won == false) return;

    if(ok_button == nullptr){

        ok_button = new QPushButton("ok", this);

        ok_button->setGeometry(295, 230, 30, 30);

        ok_button->show();

        QObject::connect(ok_button, SIGNAL (clicked()), this, SLOT (__ok_button_pressed__()));
    }

    if(label == nullptr){

        label = new QLabel("You Won", this);

        label->setGeometry(285, 200, 60, 30);

        label->show();
    }
}

void GameWindow::__ok_button_pressed__(){

    delete game;

    game = new OneSuitGame("player", scene);

    game->setEventHandler(this);

    if(ok_button != nullptr) delete ok_button;
    if(label != nullptr) delete label;

    ok_button = nullptr;
    label = nullptr;
}



