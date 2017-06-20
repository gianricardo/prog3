#include "bemvindo.h"
#include "ui_bemvindo.h"

bemvindo::bemvindo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bemvindo)
{
    ui->setupUi(this);
}

bemvindo::~bemvindo()
{
    delete ui;
}
