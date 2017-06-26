#ifndef JOGO2_H
#define JOGO2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "qcarta.h"
#include "qjogo.h"

namespace Ui {
class Jogo2;
}

class Jogo2 : public Qjogo
{
    Q_OBJECT

public:
    explicit Jogo2(QWidget *parent = 0, QString n_nome ="");
    ~Jogo2();
    void setPontuacao(QString pont = "0", std::size_t pos = 0) override;
    void outrasMaos(unsigned int pos, std::vector<p3::Carta> _mao) override;
    void jogaCarta(unsigned int pos,unsigned int pos_carta, p3::Carta carta) override;


private:
    Ui::Jogo2 *ui;
    QString _jogador;
    QGraphicsScene *jogo2_scene;
};

#endif // JOGO2_H
