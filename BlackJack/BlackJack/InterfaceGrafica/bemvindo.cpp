#include "bemvindo.h"
#include "ui_bemvindo.h"

bemvindo::bemvindo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bemvindo)
{
    ui->setupUi(this);
}
void bemvindo::texto(QString a){
    ui->lineEdit->insert("Bom jogo ");
    ui->lineEdit->insert(a);
}

bemvindo::~bemvindo()
{
    delete ui;
}
