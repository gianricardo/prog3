#include "qjogo.h"
#include "ui_jogo.h"
#include <QString>


Qjogo::Qjogo(QWidget *parent, QString n_name) :
    QMainWindow(parent),
    ui(new Ui::Jogo)
{
    _truco = false;
    _jogador = n_name;
    ui->setupUi(this);

    mao11 = new GetAcao(this);
    QBrush green(Qt::darkGreen);
    jogo_scene = new QGraphicsScene(this);
    jogo_scene->setBackgroundBrush(green);
    ui->graphicsView->setScene(jogo_scene);

    ui->lineEdit->setText("Computer 1");
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setText("Computer 2");
    ui->lineEdit_2->setDisabled(true);
    ui->lineEdit_3->setText(_jogador);
    ui->lineEdit_3->setDisabled(true);
    ui->lineEdit_4->setText("Computer 3");
    ui->lineEdit_4->setDisabled(true);




    ui->lineEdit_5->setText("0");
    ui->lineEdit_5->setDisabled(true);
    ui->lineEdit_6->setText("0");
    ui->lineEdit_6->setDisabled(true);
    ui->lineEdit_7->setText("0");
    ui->lineEdit_7->setDisabled(true);
    ui->lineEdit_8->setText("0");
    ui->lineEdit_8->setDisabled(true);



}

Qjogo::~Qjogo()
{
    delete ui;
}


void Qjogo::setPontuacao(QString pont, std::size_t pos){
    if(pos == 0){
        ui->lineEdit_6->setEnabled(true);
        ui->lineEdit_8->setEnabled(true);

        ui->lineEdit_6->setText(pont);
        ui->lineEdit_8->setText(pont);

        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_8->setDisabled(true);

    }
    else if(pos == 1){
        ui->lineEdit_5->setEnabled(true);
        ui->lineEdit_7->setEnabled(true);

        ui->lineEdit_5->setText(pont);
        ui->lineEdit_7->setText(pont);

        ui->lineEdit_5->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);


    }
}

void Qjogo::mostraBaralho(std::vector<std::pair<bool, p3::Carta> > _monte){
    for(unsigned int i = 0; i < _monte.size(); i++){
        qbaralho.emplace_back(new QCarta(_monte[i].second));
        qbaralho[i]->setPos(225+ i + 20,150);
        jogo_scene->addItem(qbaralho[i]);

    }
}

void Qjogo::mostraVira(p3::Carta _carta){
    vira = new QCarta(_carta);
    vira->setPos(225+40,150);
    jogo_scene->addItem(vira);

}

void Qjogo::mostraMao(){
    for(unsigned int i = 0; i < qmao.size(); i++){
        if(qmao[i]->getClickable() == false){
             qmao[i]->setClickable();
        }
    }
}

void Qjogo::mostraMaoInicio(std::vector<p3::Carta> _mao){
    for(unsigned int i = 0; i < _mao.size(); i++){
        _mao[i].vira();
        qmao.emplace_back(new QCarta(_mao[i]));
        qmao[i]->setPos(200 + i*40,290);
        jogo_scene->addItem(qmao[i]);
    }
}

void Qjogo::mostraMaooff(){
    for(unsigned int i = 0; i < qmao.size();i++){
        if(qmao[i]->getClickable()){
            qmao[i]->setClickable();
        }
    }
}

void Qjogo::outrasMaos(unsigned int pos,std::vector<p3::Carta> _mao){
    if(pos == 1){
        for(unsigned int i = 0; i < _mao.size(); i++){
            qmao1.emplace_back(new QCarta(_mao[i]));
            qmao1[i]->setPos(0,180 -i*30);
            jogo_scene->addItem(qmao1[i]);
        }
    }

    else if(pos == 2){
        for(unsigned int i = 0; i < _mao.size(); i++){
            qmao2.emplace_back(new QCarta(_mao[i]));
            qmao2[i]->setPos(200 +i*40,0);
            jogo_scene->addItem(qmao2[i]);
        }
    }
    else if(pos  == 3){
        for(unsigned int i = 0; i < _mao.size(); i++){
            qmao3.emplace_back(new QCarta(_mao[i]));
            qmao3[i]->setPos(515,180 -i*30);
            jogo_scene->addItem(qmao3[i]);
        }
    }
    else{
        return;
    }

}

void Qjogo::jogaCarta(unsigned int pos, unsigned int pos_carta, p3::Carta carta){
    if(pos == 0){
        jogo_scene->removeItem(qmao[pos_carta]);
        qmao.erase(qmao.begin() + pos_carta);
        qmesa.emplace(qmesa.begin(),new QCarta(carta));
        qmesa[0]->setPos(255, 220);
        jogo_scene->addItem(qmesa[0]);
    }
    else if(pos == 1){
        jogo_scene->removeItem(qmao1[pos_carta]);
        qmao1.erase(qmao1.begin() + pos_carta);
        qmesa.emplace(qmesa.begin(),new QCarta(carta));
        qmesa[0]->setPos(60,180-30);
        jogo_scene->addItem(qmesa[0]);
    }
    else if(pos == 2){
        jogo_scene->removeItem(qmao2[pos_carta]);
        qmao2.erase(qmao2.begin() + pos_carta);
        qmesa.emplace(qmesa.begin(),new QCarta(carta));
        qmesa[0]->setPos(255,70);
        jogo_scene->addItem(qmesa[0]);
    }
    else if(pos == 3){
        jogo_scene->removeItem(qmao3[pos_carta]);
        qmao3.erase(qmao3.begin() + pos_carta);
        qmesa.emplace(qmesa.begin(),new QCarta(carta));
        qmesa[0]->setPos(455,180 -30);
        jogo_scene->addItem(qmesa[0]);
    }

}

bool Qjogo::statusTruco(){
    return _truco;
}

bool Qjogo::maoDe11(std::vector<p3::Carta> mao1, std::vector<p3::Carta> mao2){
    mao11->show();
    mao11->addMao(mao1,mao2);

    return mao11->getAcao();


}

void Qjogo::setTrucoFalse(){
    _truco = false;
}

bool Qjogo::getClick(unsigned int carta){
    return qmao[carta]->getClicked();
}

unsigned int Qjogo::cartaSelecionada(){
    unsigned int cont = 0;
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_4->setDisabled(true);

    QEventLoop loop;
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),&loop,SLOT(quit()));
    loop.exec();
        for(unsigned int i = 0; i < qmao.size(); i++ ){
            if(qmao[i]->getSelected()){
                cont = i;
            }
        }
    return cont;

}

void Qjogo::comeca_novo_turno(){
    comeca_nova_rodada();
    unsigned int tamanho = 0;
    tamanho = qmao.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qmao[0]);
        qmao.erase(qmao.begin());
    }
    tamanho = qmao1.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qmao1[0]);
         qmao1.erase(qmao1.begin());
    }
    tamanho = qmao2.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qmao2[0]);
        qmao2.erase(qmao2.begin());
    }
    tamanho = qmao3.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qmao3[0]);
        qmao3.erase(qmao3.begin());
    }
    tamanho = qbaralho.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qbaralho[0]);
        qbaralho.erase(qbaralho.begin());
    }
    delete(vira);

}

void Qjogo::comeca_nova_rodada(){
    unsigned int tamanho = 0;
    tamanho = qmesa.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo_scene->removeItem(qmesa[0]);
        qmesa.erase(qmesa.begin());
    }
}

void Qjogo::jogadorGanhouRodada(p3::Carta carta,unsigned int pos){
    if(pos == 4){
        QMessageBox::information(this,"Ganhou Rodada", "Jogador: " + QString::number(pos) + " empatou a rodada com a carta" +
                             QString::number(carta.numero()));
    }
    else{
        if(carta.naipe() == p3::Carta::Naipe::Paus){
             QMessageBox::information(this,"Ganhou Rodada", "Jogador: " + QString::number(pos) + " ganhou a rodada com a Carta: " +
                                  QString::number(carta.numero()) + " de Paus");

        }
        if(carta.naipe() == p3::Carta::Naipe::Copas){
             QMessageBox::information(this,"Ganhou Rodada", "Jogador: " + QString::number(pos) + " ganhou a rodada com a Carta: " +
                                  QString::number(carta.numero()) + " de Copas");

        }
        if(carta.naipe() == p3::Carta::Naipe::Espadas){
             QMessageBox::information(this,"Ganhou Rodada", "Jogador: " + QString::number(pos) + " ganhou a rodada com a Carta: " +
                                  QString::number(carta.numero()) + " de Espadas");

        }
        if(carta.naipe() == p3::Carta::Naipe::Ouros){
             QMessageBox::information(this,"Ganhou Rodada", "Jogador: " + QString::number(pos) + " ganhou a rodada com a Carta: " +
                                  QString::number(carta.numero()) + " de Ouros");

        }
    }
}

void Qjogo::JogadoresCorreram(){
    QMessageBox::information(this,"Correram","Os Adversarios correram do truco");
}

void Qjogo::on_pushButton_2_clicked()
{
    if(_truco == false){
        _truco = true;
        QMessageBox::information(this,"Truco","Pediu Truco/Aumentou !");
    }
}

void Qjogo::mostraValorTruco(unsigned int _valor){
    QFont helvetica("Times",18);
    ui->lineEdit_9->setEnabled(true);
    ui->lineEdit_9->setFont(helvetica);
    ui->lineEdit_9->setText(QString::number(_valor));
    ui->lineEdit_9->setDisabled(true);
}

void Qjogo::acao(){
    QEventLoop loop;
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton->setDisabled(true);
    ui->pushButton_3->setDisabled(true);

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),&loop,SLOT(quit()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),&loop,SLOT(quit()));

    loop.exec();

}
