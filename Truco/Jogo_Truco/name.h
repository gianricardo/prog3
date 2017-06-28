#ifndef NAME_H
#define NAME_H

#include <QDialog>
#include <QString>

namespace Ui {
class Name;
}

class Name : public QDialog
{
    Q_OBJECT

public:
    explicit Name(QWidget *parent = 0);
    ~Name();
    QString nome();
    int numero_jogadores();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Name *ui;
    QString _nome;
    int _jogadores;
};

#endif // NAME_H
