#include "novo.h"
#include "ui_novo.h"

novo::novo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::novo)
{
    ui->setupUi(this);
}

novo::~novo()
{
    delete ui;
}

QString novo::nome()
{
    return ui->lineEdit->text();
}
