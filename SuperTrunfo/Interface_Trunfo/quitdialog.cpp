#include "quitdialog.h"
#include "ui_quitdialog.h"

quitDialog::quitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quitDialog)
{
    ui->setupUi(this);
}

quitDialog::~quitDialog()
{
    delete ui;
}

void quitDialog::on_yesButton_clicked()
{
    qApp->closeAllWindows();
    qApp->quit();
    qApp->quitOnLastWindowClosed();
}

void quitDialog::on_noButton_clicked()
{
    this->close();
}
