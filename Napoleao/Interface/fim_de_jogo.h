#ifndef FIM_DE_JOGO_H
#define FIM_DE_JOGO_H

#include <QtWidgets/QDialog>

namespace Ui {
class fim_de_jogo;
}

class fim_de_jogo : public QDialog
{
    Q_OBJECT

public:
    explicit fim_de_jogo(QWidget *parent = 0);
    void texto(std::string text);
    ~fim_de_jogo();

private:
    Ui::fim_de_jogo *ui;
};

#endif // FIM_DE_JOGO_H
