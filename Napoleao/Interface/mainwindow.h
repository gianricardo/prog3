#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <QPixmap>


class Tela;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_tela(Tela *tel);
    void mostra_turnos();
    std::string nome_jogador();
    std::string nome_adversario();
    int numero_rodadas();
    void informacao(std::string msg);
    void rodada_atual(int x);
    void aposta_max(int n);
    void turnos_vencidos(int n);
    void construindo();
    void inicio_rodada();
    void inicio_turno();
    void imprime_carta(std::string card, bool mostra,int pos, int jog);
    void carta_monte(std::string card);
    int pergunta_turnos();
    int pergunta_naipe();
    int pergunta_carta();
    void trunfo_rodada(int n);
    void atualiza_cartas(int jog);
    void declarante(std::string nome);
    void sleep(unsigned int n);
    void rodada_fim(int pos, int pontos, bool win);
    void pontos_jogador(int n);
    void pontos_adversario(int n);
    void fim_do_jogo();

private slots:
    void on_actionInicio_jogo_triggered();

    void on_b_turno_0_clicked();

    void on_b_turno_1_clicked();

    void on_b_turno_2_clicked();

    void on_b_turno_3_clicked();

    void on_b_turno_4_clicked();

    void on_b_turno_5_clicked();

    void on_b_paus_clicked();

    void on_b_copas_clicked();

    void on_b_espadas_clicked();

    void on_b_ouros_clicked();

    void on_i_carta_j1_clicked();

    void on_i_carta_j2_clicked();

    void on_i_carta_j3_clicked();

    void on_i_carta_j4_clicked();

    void on_i_carta_j5_clicked();

private:
    Ui::MainWindow *ui;
    Tela *t;
    int turno = 0;
    int naipe = 0;
    int carta = 0;
};

#endif // MAINWINDOW_H
