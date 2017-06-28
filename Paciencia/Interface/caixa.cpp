#include "caixa.h"
#include "ui_caixa.h"

Caixa::Caixa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Caixa)
{
    ui->setupUi(this);
}

Caixa::~Caixa()
{
    delete ui;
}

QString Caixa::nome(){

    return _nome;
}

void Caixa::on_pushButton_clicked()
{
    _nome = ui->lineEdit->text();

    close();
}
