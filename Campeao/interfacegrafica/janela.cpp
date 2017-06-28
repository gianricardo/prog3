#include "janela.h"
#include "ui_janela.h"

janela::janela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janela)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

janela::~janela()
{
    delete ui;
}

QString janela:: texto(){
    return ui->linha->text();
}
