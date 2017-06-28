#include "fim_rodada.h"
#include "ui_fim_rodada.h"

fim_rodada::fim_rodada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fim_rodada)
{
    ui->setupUi(this);
}

fim_rodada::~fim_rodada()
{
    delete ui;
}

void fim_rodada::texto(std::string text) {
    ui->l_fim_rodada->setText(QString::fromStdString(text));
}
