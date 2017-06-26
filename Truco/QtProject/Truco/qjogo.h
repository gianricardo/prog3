#ifndef JOGO_H
#define JOGO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <vector>
#include <QEventLoop>
#include "qcarta.h"
#include "getacao.h"

namespace Ui {
class Jogo;
}

class Qjogo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Qjogo(QWidget *parent = 0, QString n_name = "");
    ~Qjogo();
    virtual void setPontuacao(QString = "0", std::size_t pos = 0);
    void mostraBaralho(std::vector<std::pair<bool, p3::Carta> > _monte);
    void mostraVira(p3::Carta _carta);
    void mostraMao();
    void mostraMaoInicio(std::vector<p3::Carta> _mao);
    void mostraMaooff();
    virtual void outrasMaos(unsigned int pos, std::vector<p3::Carta> _mao);
    virtual void jogaCarta(unsigned int pos, unsigned int pos_carta, p3::Carta carta);
    bool statusTruco();
    bool maoDe11(std::vector<p3::Carta> mao1, std::vector<p3::Carta> mao2);
    void setTrucoFalse();
    bool getClick(unsigned int carta);
    unsigned int cartaSelecionada();
    void comeca_novo_turno();
    void comeca_nova_rodada();
    void jogadorGanhouRodada(p3::Carta carta,unsigned int pos);
    void JogadorGanhouTurno(unsigned int pos);
    void JogadoresCorreram();
    void mostraValorTruco(unsigned int _valor = 0);
    void acao();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::Jogo *ui;
    QString _jogador;
    QGraphicsScene *jogo_scene;
    std::vector<QCarta *> qbaralho;
    std::vector<QCarta *> qmao;
    std::vector<QCarta *> qmao1;
    std::vector<QCarta *> qmao2;
    std::vector<QCarta *> qmao3;
    std::vector<QCarta *> qmesa;
    QCarta *vira;
    GetAcao *mao11;
    bool _truco;
};

#endif // JOGO_H
