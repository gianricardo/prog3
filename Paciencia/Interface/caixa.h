#ifndef CAIXA_H
#define CAIXA_H

#include <QDialog>

namespace Ui {
class Caixa;
}

class Caixa : public QDialog
{
    Q_OBJECT

public:
    explicit Caixa(QWidget *parent = 0);
    ~Caixa();

    QString nome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Caixa *ui;
    QString _nome;
};

#endif // CAIXA_H
