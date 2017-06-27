#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "escreve_nome.h"
#include "escreve_nome_adversario.h"
#include "escreve_rodadas.h"
#include "../tela.h"
#include <iostream>
#include <QEventLoop>
#include <QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->layout_turnos->hide();
    ui->layout_naipes->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_tela(Tela *tel){
    t = tel;
}

void MainWindow::mostra_turnos(){
    ui->layout_turnos->show();
}

std::string MainWindow::nome_jogador(){
    QString qs = ui->l_nome_jogador->text();
    return qs.toStdString();
}

std::string MainWindow::nome_adversario(){
    QString qs = ui->l_nome_adversario->text();
    return qs.toStdString();
}

int MainWindow::numero_rodadas(){
    QString qs = ui->l_rodadas->text();
    return qs.toInt();
}

void MainWindow::informacao(std::string msg){
    QString qs = QString::fromStdString(msg);
    ui->l_informacao->setText(qs);
}

void MainWindow::rodada_atual(int x){
    ui->l_rodada_atual->setText(QString::number(x));
}

void MainWindow::construindo(){
    ui->layout_jogador->hide();
    ui->layout_adversario->hide();
    ui->i_carta_monte->hide();
    escreve_nome jog;
    escreve_nome_adversario adv;
    escreve_rodadas rod;
    jog.show();
    jog.exec();
    adv.show();
    adv.exec();
    rod.show();
    rod.exec();

    ui->l_nome_jogador->setText(jog.nome());
    ui->l_nome_adversario->setText(adv.nome());
    ui->l_rodadas->setText(rod.num());

    ui->layout_jogador->show();
    ui->layout_adversario->show();
    ui->i_carta_monte->show();
}

void MainWindow::imprime_carta(std::string card, bool mostra, int pos, int jog){
    QString filename = QString::fromStdString(card);
    QPixmap img;
    if(mostra) img.load(filename);
    else img.load(":/baralho/back.jpg");

    int w = ui->i_carta_a1->width();
    int h = ui->i_carta_a1->height();
    if (jog == 0) {
        switch(pos){
        case 1: ui->i_carta_j1->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 2: ui->i_carta_j2->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 3: ui->i_carta_j3->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 4: ui->i_carta_j4->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 5: ui->i_carta_j5->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        default:
            std::cout << "IMPRIME CARTA MAIN WINDOWS Nao era pra ter chego aqui" << std::endl;
        }
    }
    if (jog == 1) {
        switch(pos){
        case 1: ui->i_carta_a1->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 2: ui->i_carta_a2->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 3: ui->i_carta_a3->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 4: ui->i_carta_a4->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        case 5: ui->i_carta_a5->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio)); break;
        default:
            std::cout << "IMPRIME CARTA MAIN WINDOWS Nao era pra ter chego aqui" << std::endl;
        }
    }

}

void MainWindow::carta_monte(std::string card){
    QString filename = QString::fromStdString(card);
    QPixmap img;
    img.load(filename);
    int w = ui->i_carta_monte->width();
    int h = ui->i_carta_monte->height();
    ui->i_carta_monte->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_actionInicio_jogo_triggered()
{
    ui->b_inicio->hide();
    t->inicia_jogo();
    //t->imprime_mao_atual();
}

int MainWindow::pergunta_turnos(){
    ui->layout_turnos->show();
    //ui->l_informacao->setText("Jogador, escolha o numero de rodadas que voce acha que vai fazer!");
    QEventLoop loop;
    QObject::connect(ui->b_turno_0,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_turno_1,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_turno_2,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_turno_3,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_turno_4,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_turno_5,SIGNAL(clicked()),&loop,SLOT(quit()));
    loop.exec();
    loop.quit();
    ui->l_aposta_maxima->setText(QString::number(turno));
    int retorno = turno;
    ui->layout_turnos->hide();
    return retorno;
}

void MainWindow::on_b_turno_0_clicked()
{
    turno = 0;
}

void MainWindow::on_b_turno_1_clicked()
{
    turno = 1;
}

void MainWindow::on_b_turno_2_clicked()
{
    turno = 2;
}

void MainWindow::on_b_turno_3_clicked()
{
    turno = 3;
}

void MainWindow::on_b_turno_4_clicked()
{
    turno = 4;
}

void MainWindow::on_b_turno_5_clicked()
{
    turno = 5;
}

int MainWindow::pergunta_naipe(){
    ui->layout_naipes->show();
    ui->l_informacao->setText("Jogador, escolha o naipe de trunfo!");
    QEventLoop loop;
    QObject::connect(ui->b_espadas,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_copas,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_paus,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->b_ouros,SIGNAL(clicked()),&loop,SLOT(quit()));
    loop.exec();
    loop.quit();
    trunfo_rodada(naipe);
    int retorno = naipe;
    ui->layout_naipes->hide();
    return retorno;
}

void MainWindow::on_b_paus_clicked()
{
    naipe = 2;
}

void MainWindow::on_b_copas_clicked()
{
    naipe = 1;
}

void MainWindow::on_b_espadas_clicked()
{
    naipe = 0;
}

void MainWindow::on_b_ouros_clicked()
{
    naipe = 3;
}

int MainWindow::pergunta_carta(){
    ui->layout_jogador->show();
    ui->l_informacao->setText("Jogador, escolha a carta a ser jogada!");
    QEventLoop loop;
    QObject::connect(ui->i_carta_j1,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->i_carta_j2,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->i_carta_j3,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->i_carta_j4,SIGNAL(clicked()),&loop,SLOT(quit()));
    QObject::connect(ui->i_carta_j5,SIGNAL(clicked()),&loop,SLOT(quit()));
    loop.exec();
    loop.quit();
    ui->l_carta_escolhida->setText(QString::number(carta));
    int retorno = carta;
   // ui->layout_jogador->hide();
    return retorno;
}

void MainWindow::on_i_carta_j1_clicked(){
    carta = 0;
}

void MainWindow::on_i_carta_j2_clicked(){
    carta = 1;
}

void MainWindow::on_i_carta_j3_clicked(){
    carta = 2;
}

void MainWindow::on_i_carta_j4_clicked(){
    carta = 3;
}

void MainWindow::on_i_carta_j5_clicked(){
    carta = 4;
}

void MainWindow::trunfo_rodada(int n){
    switch(n) {
    case 0: ui->l_trunfo_rodada->setText("Espadas"); break;
    case 1: ui->l_trunfo_rodada->setText("Copas");   break;
    case 2: ui->l_trunfo_rodada->setText("Paus");    break;
    case 3: ui->l_trunfo_rodada->setText("Ouros");   break;
    default: ui->l_trunfo_rodada->setText("Deu bosta");
    }

}

void MainWindow::atualiza_cartas(int jog){
    QPixmap img;
    img.load(":/baralho/backx.jpg");
    int w = ui->i_carta_a1->width();
    int h = ui->i_carta_a1->height();
    if(jog == 0) {
        ui->i_carta_j1->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_j2->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_j3->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_j4->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_j5->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
    } else {
        ui->i_carta_a1->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_a2->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_a3->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_a4->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
        ui->i_carta_a5->setPixmap(img.scaled(w,h,Qt::KeepAspectRatio));
    }

}

void MainWindow::declarante(std::string nome){
    ui->l_nome_declarante->setText(QString::fromStdString(nome));

}

