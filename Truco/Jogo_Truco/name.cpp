#include "name.h"
#include "ui_name.h"
#include <QApplication>
#include <QMessageBox>

Name::Name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Name)
{
    ui->setupUi(this);
}

Name::~Name()
{
    delete ui;
}

void Name::on_pushButton_clicked()
{
     _nome = ui->lineEdit->displayText();
     _jogadores = 4;
    if(_nome.size() == 0){
        QMessageBox::warning(this,"incorrect Name","Invalid Name");
    }
    else{
        QMessageBox::information(this, "Name", _nome);
        close();
    }


}

QString Name::nome(){
    return _nome;
}

int Name::numero_jogadores(){
    return _jogadores;
}
