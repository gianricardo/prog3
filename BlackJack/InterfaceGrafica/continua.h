#ifndef CONTINUA_H
#define CONTINUA_H

#include <QDialog>

namespace Ui {
class continua;
}

class continua : public QDialog
{
    Q_OBJECT

public:
    //retornara true se o jogador quiser continuar e false se nao
    explicit continua(QWidget *parent = 0);
    ~continua();


private:
    Ui::continua *ui;
};

#endif // CONTINUA_H
