#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualiza_jogo(){

    atualiza_dados();

    std::string nome_carta, carta;
    QString qcarta;

    for(int i = 0; i <= 12; i++){
        nome_carta = _tel.mostra_carta(_pac.get_jogo() , i);

        carta = "background-image: url(:/baralho/"+ nome_carta +".png);";

        qcarta = QString::fromStdString(carta);

        m[i]->setStyleSheet(qcarta);
     }
}

void MainWindow::jogador(QString nome){

    _pac.nome_jogador(nome.toStdString());
}

void MainWindow::list_botton(){

    m.append(ui->m_0);
    m.append(ui->m_1);
    m.append(ui->m_2);
    m.append(ui->m_3);
    m.append(ui->m_4);
    m.append(ui->m_5);
    m.append(ui->m_6);
    m.append(ui->m_7);
    m.append(ui->m_8);
    m.append(ui->m_9);
    m.append(ui->m_10);
    m.append(ui->m_11);
    m.append(ui->m_12);
}

void MainWindow::fim_jogo(){

    QMessageBox::information(this, tr("Fim de Jogo"), tr("Vitoria"));

    exit(1);
}

void MainWindow::atualiza_dados(){

       QString aux;

       aux = QString::fromStdString(_pac.nome_jogador());
       ui->nome_jogador->setText(aux);

       aux = QString::fromStdString(_pac.pontuacao());
       ui->pontuacao->setText(aux);

       aux = QString::fromStdString(_pac.jogada_atual());
       ui->jogada->setText(aux);
}

void MainWindow::on_m_0_clicked()
{
    jogada[_click] = 0;

    _pac.verifica_jogada(jogada[0], jogada[1]);
    _click = 0;
    atualiza_jogo();
}

void MainWindow::on_m_1_clicked()
{
    jogada[_click] = 1;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_2_clicked()
{
    jogada[_click] = 2;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_3_clicked()
{
    jogada[_click] = 3;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_4_clicked()
{
    jogada[_click] = 4;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_5_clicked()
{
    jogada[_click] = 5;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_6_clicked()
{
    jogada[_click] = 6;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_7_clicked()
{
    jogada[_click] = 7;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_8_clicked()
{
    jogada[_click] = 8;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_9_clicked()
{
    jogada[_click] = 9;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_10_clicked()
{
    jogada[_click] = 10;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_11_clicked()
{
    jogada[_click] = 11;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}

void MainWindow::on_m_12_clicked()
{
    jogada[_click] = 12;

    _click++;

    if(_click == 2){
        if(!(_pac.verifica_jogada(jogada[0], jogada[1])))
            MainWindow::fim_jogo();
        _click = 0;
        atualiza_jogo();
    }
}
