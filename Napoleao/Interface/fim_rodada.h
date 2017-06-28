#ifndef FIM_RODADA_H
#define FIM_RODADA_H

#include <QDialog>

namespace Ui {
class fim_rodada;
}

class fim_rodada : public QDialog
{
    Q_OBJECT

public:
    explicit fim_rodada(QWidget *parent = 0);
    void texto(std::string text);
    ~fim_rodada();

private:
    Ui::fim_rodada *ui;
};

#endif // FIM_RODADA_H
