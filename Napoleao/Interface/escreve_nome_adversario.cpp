#include "escreve_nome_adversario.h"
#include "ui_escreve_nome_adversario.h"

escreve_nome_adversario::escreve_nome_adversario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::escreve_nome_adversario)
{
    ui->setupUi(this);
}

escreve_nome_adversario::~escreve_nome_adversario()
{
    delete ui;
}

QString escreve_nome_adversario::nome(){
    return ui->e_escreve_nome_adversario->text();
}
