#include "nova_aposta.h"
#include "ui_nova_aposta.h"

nova_aposta::nova_aposta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nova_aposta)
{
    ui->setupUi(this);
    this->setWindowFlags ( Qt::CustomizeWindowHint );
}

nova_aposta::~nova_aposta()
{
    delete ui;
}

int nova_aposta::val(){
    return ui->lcdNumber->value();
}
