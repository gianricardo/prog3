#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QDialog>
#include <QApplication>
#include <QGraphicsItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _numero_jogadores = 0;
    int cont = 0;
    scene = new QGraphicsScene(this);
    text = new QGraphicsTextItem();

    QFont helvetica("Times",72);
    text->setFont(helvetica);
    text->setPlainText("Truco");
    text->setPos(80,0);
    scene->addItem(text);


    QBrush green(Qt::darkGreen);
    scene->setBackgroundBrush(green);

    for(int i = 0 ;i < 10; i++){
       for(int j = 0; j < 4; j++){
           QCarta *card = new QCarta(p3::Carta(i+1,(p3::Carta::Naipe)j,false));
           card->setPos(cont*4,150);
           scene->addItem(card);
           cont++;

       }
    }

    ui->graphicsView->setScene(scene);
    showFullScreen();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Name nome;
    nome.setModal(true);
    nome.exec();

    rule = new p4::Regra_Truco(nome.numero_jogadores(),3,3,12,0,40);
    _numero_jogadores = nome.numero_jogadores();

    if(nome.nome().size() > 0){
        if(nome.numero_jogadores() == 4){
            _jogo= new Qjogo(0,nome.nome());
            _jogadores.emplace_back((nome.nome().toStdString()));
            _jogadores.emplace_back("Computer1");
            _jogadores.emplace_back("Computer2");
            _jogadores.emplace_back("Computer3");
            game = new p4::Jogo_Truco(rule,jogadores(),_jogo);
            game->jogar();

        }
        else if(nome.numero_jogadores() == 2){
            _jogo2 = new Jogo2(0,nome.nome());
            _jogadores.emplace_back((nome.nome().toStdString()));
            _jogadores.emplace_back("Computer1");
            game = new p4::Jogo_Truco(rule, jogadores(),_jogo2);
            game->jogar();
        }
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Help _help;
    _help.setModal(true);
    _help.exec();

    show();
}

std::vector<std::string> MainWindow::jogadores(){
    return _jogadores;
}


int MainWindow::numero_jogadores(){
    return _numero_jogadores;
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
