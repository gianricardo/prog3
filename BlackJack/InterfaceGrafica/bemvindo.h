#ifndef BEMVINDO_H
#define BEMVINDO_H

#include <QDialog>

namespace Ui {
class bemvindo;
}

class bemvindo : public QDialog
{
    Q_OBJECT

public:
    explicit bemvindo(QWidget *parent = 0);
    ~bemvindo();
    //recebe o nome a ser exibido (nome do jogador)
    void texto(QString a);

private:
    Ui::bemvindo *ui;

};

#endif // BEMVINDO_H
