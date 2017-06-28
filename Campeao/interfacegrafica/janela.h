#ifndef JANELA_H
#define JANELA_H

#include <QDialog>
#include <iostream>
namespace Ui {
class janela;
}

class janela : public QDialog
{
    Q_OBJECT

public:
    explicit janela(QWidget *parent = 0);
    ~janela();
    QString texto();

private:
    Ui::janela *ui;
};

#endif // JANELA_H
