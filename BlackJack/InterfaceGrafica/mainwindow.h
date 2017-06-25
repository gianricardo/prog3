#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEventLoop>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QTimer>
#include "nova_aposta.h"
#include "novo.h"
#include "obg.h"
#include "bemvindo.h"
#include "n_aposta.h"
#include "dealer.h"
#include "continua.h"
#include "parabens.h"
#include "../../carteado/src/p3/carta.h"
#include "imagem_carta.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //mostra janela de dialogo de novo jogo
    //retorna uma string com o nome do jogador
    std::string novo_jogo();
    //atualiza o saldo do jogador
    //recebe novo saldo
    void placar (int total);
    //pede que o jogador entre com a nova aposta
    //retorna o valor da nova aposta
    int aposta();
    //mostra a tela de boas vindas
    void boas_vindas();
    //mostra a tela de aviso que o jogador nao esta apto a apostar
    void naposta();
    //habilida o menu de jogada
    //retorna o valor da acao, 1 hit, 2 dobrar aposta e 3 finalizar jogada
    int jogue();
    //mostra a tela de aviso de que é a vez do dealer jogar
    void vez_dealer();
    //pergunta se o jogador quer continuar jogando (nova partida)
    //true se sim, false se nao
    bool continuar();
    //mostra a mensagem de vencedor
    //recebe true para jogador vencedor e false para dealer vencedor
    //o valor da ultima aposta (b)
    //o valor do saldo resultante apos a rodada (c)
    void vencedor(bool a, int b, int c);
    //atualiza o placar
    //recebe saldo atual e aposta atual
    void placar_rodada(int saldo, int aposta);
    //mostra dois vetores de carta, um para dealer e outro para jogador
    //recebe vetor de cartas da mao do dealer d
    //e vetor de cartas da mao do jogador p
    void mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p);
    //mostra a tela de agradecimento e fecha o aplicativo
    void obrigado();

private slots:
//acoes ao clicar nos botoes de jogada
    void on_actionhit_triggered();

    void on_actiondouble_triggered();

    void on_actionstay_triggered();

private:
    Ui::MainWindow *ui;
    //nome do jogador
    QString nome;
    //valor da ultima aposta
    int ultimaaposta;
    //saldo atual
    int saldo;
    //valor referente ao ultimo botao de aposta clicado
    int ac;
    QGraphicsScene* scene;
    QGraphicsPixmapItem *imagem;
};

#endif // MAINWINDOW_H
