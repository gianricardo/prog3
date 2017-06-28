#include "rounds.h"
#include "ui_rounds.h"

Rounds::Rounds(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rounds)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    QBrush roundb(Qt::darkCyan);
    scene->setBackgroundBrush(roundb);
    ui->graphicsView->setScene(scene);
}

Rounds::~Rounds()
{
    delete ui;
    delete scene;
}

int Rounds::rodadas()
{
    QEventLoop espera;
    QObject::connect(ui->pushButton,SIGNAL(clicked()),&espera,SLOT(quit()));
    espera.exec();
    return ui->horizontalSlider->value();
}

void Rounds::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit->setText(QString::number(value));
}
