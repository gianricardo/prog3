#include "campeao.h"
#include "ui_campeao.h"
#include "carta_campea.h"

Campeao::Campeao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Campeao)
{
    ui->setupUi(this);
    ui->terceiro->hide();

    QBrush cinzao(Qt::darkGray);
    cena_campeao = new QGraphicsScene(this);
    cena_campeao->setBackgroundBrush(cinzao);
    ui->qgraphicsview->setScene(cena_campeao);
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowFlags ( Qt::CustomizeWindowHint );

    QPixmap mypixmap_caue_uml;

    std::cout << mypixmap_caue_uml.load(":/5004721-green-wallpaper-background.jpg") << std::endl;
    ui->qgraphicsview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qgraphicsview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cena_campeao->addPixmap(mypixmap_caue_uml);
    Carta_campea * _carta = new Carta_campea(2,3);
    _carta->setX(300);
    cena_campeao->addItem(_carta); // Qgraphics item, passar ponteiro
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();


}

Campeao::~Campeao()
{
    delete ui;
}

void Campeao::on_actionnova_janela_triggered()
{
    janela j;
    j.exec();
    ui->linhaa->clear();
    ui->linhaa->insert(j.texto());
    j.close();
    ui->Banana->hide();
    ui->terceiro->show();
    ui->linhaa_2->clear();
    ui->linhaa_2->insert(" Seu Carlinho");
    ui->pushButton_1->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
}
