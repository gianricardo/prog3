#include "escreve_nome.h"
#include "ui_escreve_nome.h"

escreve_nome::escreve_nome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::escreve_nome)
{
    ui->setupUi(this);
}

escreve_nome::~escreve_nome()
{
    delete ui;
}

QString escreve_nome::nome(){
    return ui->e_insira_nome->text();
}
