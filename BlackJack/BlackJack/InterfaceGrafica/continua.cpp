#include "continua.h"
#include "ui_continua.h"

continua::continua(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::continua)
{
    ui->setupUi(this);
    this->setWindowFlags ( Qt::CustomizeWindowHint );
}

continua::~continua()
{
    delete ui;
}
