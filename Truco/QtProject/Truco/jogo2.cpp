#include "jogo2.h"
#include "ui_jogo2.h"

Jogo2::Jogo2(QWidget *parent, QString n_nome) :
    Qjogo(parent,n_nome),
    ui(new Ui::Jogo2)
{
    _jogador = n_nome;
    ui->setupUi(this);

    QBrush green(Qt::darkGreen);

    ui->lineEdit->setText("Computer1");
    ui->lineEdit->setDisabled(true);

    ui->lineEdit_2->setText("0");
    ui->lineEdit_2->setDisabled(true);

    ui->lineEdit_3->setText(_jogador);
    ui->lineEdit_3->setDisabled(true);

    ui->lineEdit_4->setText("0");
    ui->lineEdit_4->setDisabled(true);

    jogo2_scene = new QGraphicsScene(this);
    jogo2_scene->setBackgroundBrush(green);
    ui->graphicsView->setScene(jogo2_scene);


}

Jogo2::~Jogo2()
{
    delete ui;
}

void Jogo2::setPontuacao(QString pont, std::size_t pos){
    if(pos == 0){
        ui->lineEdit_4->setEnabled(true);

        ui->lineEdit_4->setText(pont);

        ui->lineEdit_4->setDisabled(true);

    }
    else if(pos == 1){
        ui->lineEdit_2->setEnabled(true);

        ui->lineEdit_2->setText(pont);

        ui->lineEdit_2->setDisabled(true);


    }
}

void Jogo2::outrasMaos(unsigned int pos, std::vector<p3::Carta> _mao){
    if(pos == 1){
        for(unsigned int i = 0; i < _mao.size(); i++){
            QCarta *card = new QCarta(_mao[i]);
            card->setPos(225 +1*40,0);
            jogo2_scene->addItem(card);
        }
    }
    else{
        return;
    }
}

 void Jogo2::jogaCarta(unsigned int pos, unsigned int pos_carta, p3::Carta carta){

 }
