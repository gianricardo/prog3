
#include "window.h"
#include "ui_window.h"

#include <iostream>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    QPixmap imagem;

    std::cout << imagem.load(":/PacienciaSpyder/img/none.png") << std::endl;
}

Window::~Window()
{
    delete ui;
}
