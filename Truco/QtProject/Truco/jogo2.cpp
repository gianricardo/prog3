#include "jogo2.h"
#include "ui_jogo2.h"

Jogo2::Jogo2(QWidget *parent, QString n_nome) :
    Qjogo(parent,n_nome),
    ui(new Ui::Jogo2)
{

    _jogador = n_nome;
    ui->setupUi(this);



}

Jogo2::~Jogo2()
{
    delete ui;
}

void Jogo2::iniciaScene(){
    mao11 = new GetAcao(this);
    jogo2_scene = new QGraphicsScene(this);
    QBrush green(Qt::darkGreen);

    ui->lineEdit->setText("Computer1");
    ui->lineEdit->setDisabled(true);

    ui->lineEdit_2->setText("0");
    ui->lineEdit_2->setDisabled(true);

    ui->lineEdit_3->setText(_jogador);
    ui->lineEdit_3->setDisabled(true);

    ui->lineEdit_4->setText("0");
    ui->lineEdit_4->setDisabled(true);

    jogo2_scene->setBackgroundBrush(green);
    ui->graphicsView->setScene(jogo2_scene);

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
            qmao1.emplace_back(new QCarta(_mao[i]));
            qmao1[i]->setPos(100+i*40,0);
            jogo2_scene->addItem(qmao1[i]);
        }
    }

}

 void Jogo2::jogaCarta(unsigned int pos, unsigned int pos_carta, p3::Carta carta){
     if(pos == 0){
         jogo2_scene->removeItem(qmao[pos_carta]);
         qmao.erase(qmao.begin() + pos_carta);
         qmesa.emplace(qmesa.begin(),new QCarta(carta));
         qmesa[0]->setPos(140, 220);
         jogo2_scene->addItem(qmesa[0]);
     }
     else if(pos == 1){
         jogo2_scene->removeItem(qmao1[pos_carta]);
         qmao1.erase(qmao1.begin() + pos_carta);
         qmesa.emplace(qmesa.begin(),new QCarta(carta));
         qmesa[0]->setPos(140,70);
         jogo2_scene->addItem(qmesa[0]);
     }

 }

 bool Jogo2::maoDe11_2(){
     mao11->show();

     return mao11->getAcao();
 }


 unsigned int Jogo2::cartaSelecionada(){
     unsigned int cont = 0;
     ui->pushButton->setDisabled(true);
     ui->pushButton_2->setDisabled(true);
     ui->pushButton_4->setEnabled(true);

     QEventLoop loop;
     connect(ui->pushButton_4,SIGNAL(clicked(bool)),&loop,SLOT(quit()));
     loop.exec();
         for(unsigned int i = 0; i < qmao.size(); i++ ){
             if(qmao[i]->getSelected()){
                 cont = i;
             }
         }
     return cont;
 }

 void Jogo2::acao(unsigned int pont){
     QEventLoop loop;

     ui->pushButton->setEnabled(true);
     ui->pushButton_2->setEnabled(true);
     ui->pushButton_4->setDisabled(true);

     if(pont == 11){
         ui->pushButton->setDisabled(true);
     }

     connect(ui->pushButton_2,SIGNAL(clicked(bool)),&loop,SLOT(quit()));
     connect(ui->pushButton,SIGNAL(clicked(bool)),&loop,SLOT(quit()));
     connect(ui->pushButton_3, SIGNAL(clicked(bool)), &loop,SLOT(quit()));

     loop.exec();
 }

void Jogo2::mostraValorTruco(unsigned int _valor){
    QFont helvetica("Times",18);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_5->setFont(helvetica);
    ui->lineEdit_5->setText(QString::number(_valor + 3));
    ui->lineEdit_5->setDisabled(true);
}
void Jogo2::comeca_novo_turno(){
    comeca_nova_rodada();
    unsigned int tamanho = 0;
    tamanho = qmao.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo2_scene->removeItem(qmao[0]);
        qmao.erase(qmao.begin());
    }
    tamanho = qmao1.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo2_scene->removeItem(qmao1[0]);
         qmao1.erase(qmao1.begin());
    }
    tamanho = qbaralho.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo2_scene->removeItem(qbaralho[0]);
        qbaralho.erase(qbaralho.begin());
    }
    delete(vira);

}

void Jogo2::comeca_nova_rodada(){
    unsigned int tamanho = 0;
    tamanho = qmesa.size();
    for(unsigned int i = 0; i < tamanho; i++){
        jogo2_scene->removeItem(qmesa[0]);
        qmesa.erase(qmesa.begin());
    }

}

void Jogo2::mostraMaoInicio(std::vector<p3::Carta> _mao){
    for(unsigned int i = 0; i < _mao.size(); i++){
        _mao[i].vira();
        qmao.emplace_back(new QCarta(_mao[i]));
        qmao[i]->setPos(100 + i*40,290);
        jogo2_scene->addItem(qmao[i]);
    }

}

void Jogo2::mostraBaralho(std::vector<std::pair<bool, p3::Carta> > _monte){
    for(unsigned int i = 0; i < _monte.size(); i++){
        qbaralho.emplace_back(new QCarta(_monte[i].second));
        qbaralho[i]->setPos(80+ i + 20,150);
        jogo2_scene->addItem(qbaralho[i]);

    }
}

void Jogo2::mostraVira(p3::Carta _carta){
    vira = new QCarta(_carta);
    vira->setPos(100+40,150);
    jogo2_scene->addItem(vira);


}

void Jogo2::on_pushButton_clicked()
{
   if(_truco == false){
        _truco = true;
        QMessageBox::information(this,"Truco","Pediu Truco/Aumentou !");
    }
}

void Jogo2::fimDeJogo(unsigned int pos){
    if(pos == 0){
        QMessageBox::information(this,"Ganhador","O ganhador foi: " + _jogador);
    }
    else if(pos == 1){
        QMessageBox::information(this,"Ganhador", "O ganhador foi: Computer1");
    }
}

void Jogo2::on_pushButton_3_clicked()
{
    QApplication::quit();
}
