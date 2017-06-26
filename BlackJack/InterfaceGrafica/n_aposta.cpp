#include "n_aposta.h"
#include "ui_n_aposta.h"

n_aposta::n_aposta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::n_aposta)
{
    ui->setupUi(this);
    this->setWindowFlags ( Qt::CustomizeWindowHint );
}

n_aposta::~n_aposta()
{
    delete ui->buttonBox;
    delete ui->label;
    delete ui->label_2;
    delete ui;
}
