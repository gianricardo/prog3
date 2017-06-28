#ifndef ESCREVE_RODADAS_H
#define ESCREVE_RODADAS_H

#include <QDialog>

namespace Ui {
class escreve_rodadas;
}

class escreve_rodadas : public QDialog
{
    Q_OBJECT

public:
    explicit escreve_rodadas(QWidget *parent = 0);
    ~escreve_rodadas();
    QString num();

private:
    Ui::escreve_rodadas *ui;
};

#endif // ESCREVE_RODADAS_H
