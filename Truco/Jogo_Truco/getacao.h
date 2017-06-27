#ifndef GETACAO_H
#define GETACAO_H

#include <QDialog>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <vector>
#include "../../carteado/src/p3/carta.h"
#include "qcarta.h"

namespace Ui {
class GetAcao;
}

class GetAcao : public QDialog
{
    Q_OBJECT

public:
    explicit GetAcao(QWidget *parent = 0);
    ~GetAcao();
    bool getAcao();
    void addMao(std::vector<p3::Carta> mao1, std::vector<p3::Carta> mao2);

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::GetAcao *ui;
    QGraphicsScene *scene;
    std::vector<QCarta *> _mao1;
    std::vector<QCarta *> _mao2;
    QGraphicsTextItem * text2;
    QGraphicsTextItem * text;
    bool aceitar;
};

#endif // GETACAO_H
