#include <QMessageBox>
#include "namesdialog.h"
#include "ui_namesdialog.h"

namesDialog::namesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::namesDialog)
{
    ui->setupUi(this);
    setModal(true);
}

namesDialog::~namesDialog()
{
    delete ui;
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

std::vector<std::__cxx11::string> namesDialog::ask()
{
    std::vector<std::string> vec;

    exec();

    vec.push_back(player_1_name);
    vec.push_back(player_2_name);

    return vec;
}

void namesDialog::on_okButton_clicked()
{
    if(ui->player1Line->text().isEmpty() || ui->player2Line->text().isEmpty())
    {
        QMessageBox::information(this, "Aiso", QString::fromUtf8("Nome não pode ser vazio!"));

    } else {
        player_1_name = ui->player1Line->text().toStdString();
        player_2_name = ui->player2Line->text().toStdString();
        close();
    }
}
