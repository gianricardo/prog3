#include "fim_de_jogo.h"
#include "ui_fim_de_jogo.h"

fim_de_jogo::fim_de_jogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fim_de_jogo)
{
    ui->setupUi(this);
}

fim_de_jogo::~fim_de_jogo()
{
    delete ui;
}

void fim_de_jogo::texto(std::string text){
    ui->l_end_game->setText(QString::fromStdString(text));
}
