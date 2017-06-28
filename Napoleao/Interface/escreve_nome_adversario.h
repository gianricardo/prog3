#ifndef ESCREVE_NOME_ADVERSARIO_H
#define ESCREVE_NOME_ADVERSARIO_H

#include <QtWidgets/QDialog>
#include <QString>
namespace Ui {
class escreve_nome_adversario;
}

class escreve_nome_adversario : public QDialog
{
    Q_OBJECT

public:
    explicit escreve_nome_adversario(QWidget *parent = 0);
    ~escreve_nome_adversario();
    QString nome();

private:
    Ui::escreve_nome_adversario *ui;
};

#endif // ESCREVE_NOME_ADVERSARIO_H
