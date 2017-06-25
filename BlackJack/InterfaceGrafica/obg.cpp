#include "obg.h"
#include "ui_obg.h"

obg::obg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::obg)
{
    ui->setupUi(this);
    this->setWindowFlags ( Qt::CustomizeWindowHint );
}

obg::~obg()
{
    delete ui;
}
