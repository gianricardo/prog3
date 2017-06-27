#ifndef JOGO2_H
#define JOGO2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QApplication>
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
    void iniciaScene() override;
    void setPontuacao(QString pont = "0", std::size_t pos = 0) override;
    void outrasMaos(unsigned int pos, std::vector<p3::Carta> _mao) override;
    void jogaCarta(unsigned int pos,unsigned int pos_carta, p3::Carta carta) override;
    bool maoDe11_2() override;
    unsigned int cartaSelecionada() override;
    void acao(unsigned int pont) override;
    void mostraValorTruco(unsigned int _valor = 0) override;
    void comeca_novo_turno() override;
    void comeca_nova_rodada() override;
    void mostraMaoInicio(std::vector<p3::Carta> _mao);
    void mostraBaralho(std::vector<std::pair<bool, p3::Carta> > _monte);
    void mostraVira(p3::Carta _carta);
    void fimDeJogo(unsigned int pos) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Jogo2 *ui;
    QGraphicsScene *jogo2_scene;

};

#endif // JOGO2_H
