#include "winnerwindow.h"
#include "ui_winnerwindow.h"

WinnerWindow::WinnerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setBackgroundBrush(Qt::green);
    ui->graphicsView->setScene(scene);
}

WinnerWindow::~WinnerWindow()
{
    delete ui;
}

void WinnerWindow::mostra_vencedor(int pos)
{
    switch(pos){
    case 0:
        ui->winner->setText("Parabéns você venceu");
        break;
    case 1:
        ui->winner->setText("West venceu a partida");
        break;
    case 2:
        ui->winner->setText("North venceu a partida");
        break;
    case 3:
        ui->winner->setText("East venceu a partida");
        break;
    }
    QEventLoop espera;
    QObject::connect(ui->pushButton,SIGNAL(clicked()),&espera,SLOT(quit()));
    espera.exec();
}
