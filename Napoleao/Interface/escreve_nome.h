#ifndef ESCREVE_NOME_H
#define ESCREVE_NOME_H

#include <QtWidgets/QDialog>
#include <QString>
namespace Ui {
class escreve_nome;
}

class escreve_nome : public QDialog
{
    Q_OBJECT

public:
    explicit escreve_nome(QWidget *parent = 0);
    ~escreve_nome();
    QString nome();

private:
    Ui::escreve_nome *ui;

};

#endif // ESCREVE_NOME_H
