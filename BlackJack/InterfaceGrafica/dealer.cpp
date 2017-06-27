#include "dealer.h"
#include "ui_dealer.h"

dealer::dealer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dealer)
{
    ui->setupUi(this);

    this->setWindowFlags ( Qt::CustomizeWindowHint );



}

dealer::~dealer()
{

    delete ui;
}
