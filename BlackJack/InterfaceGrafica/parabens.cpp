#include "parabens.h"
#include "ui_parabens.h"

parabens::parabens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parabens)
{
    ui->setupUi(this);
    this->setWindowFlags ( Qt::CustomizeWindowHint );
}

parabens::~parabens()
{
    delete ui->buttonBox;
    delete ui->label;
    delete ui;
}


void parabens::insere(QString texto){
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(texto);
}
