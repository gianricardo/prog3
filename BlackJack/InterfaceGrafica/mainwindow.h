#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEventLoop>
#include "nova_aposta.h"
#include "novo.h"
#include "bemvindo.h"
#include "n_aposta.h"
#include "dealer.h"
#include "continua.h"
#include "parabens.h"
#include "../../carteado/src/p3/carta.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::string novo_jogo();


    void placar (int total);
    int aposta();
    void boas_vindas();
    void naposta();
    int jogue();
    void vez_dealer();
    bool continuar();
    void vencedor(bool a, int b, int c);
    void placar_rodada(int saldo, int aposta);
    void mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p);


private slots:

    void on_actionhit_triggered();

    void on_actiondouble_triggered();

    void on_actionstay_triggered();

private:
    Ui::MainWindow *ui;
    QString nome;
    int ultimaaposta;
    int saldo;
    int ac;
};

#endif // MAINWINDOW_H
