#include "escreve_rodadas.h"
#include "ui_escreve_rodadas.h"
#include <QString>
escreve_rodadas::escreve_rodadas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::escreve_rodadas)
{
    ui->setupUi(this);
}

escreve_rodadas::~escreve_rodadas()
{
    delete ui;
}

QString escreve_rodadas::num(){
    return ui->lineEdit->text();
}
