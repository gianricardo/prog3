#include "dealer.h"
#include "ui_dealer.h"

dealer::dealer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dealer)
{
    ui->setupUi(this);
}

dealer::~dealer()
{
    delete ui;
}
