#ifndef TELAPRESIDENTE_H
#define TELAPRESIDENTE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QString>
#include "winnerwindow.h"
#include "imgcarta.h"
#include "../../carteado/src/p3/carta.h"

namespace Ui {
class TelaPresidente;
}

class TelaPresidente : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPresidente(QWidget *parent = 0);
    ~TelaPresidente();
    TelaPresidente(const TelaPresidente&);
    void show_hand(std::vector<p3::Carta> v0,std::vector<p3::Carta> v1,std::vector<p3::Carta> v2,std::vector<p3::Carta> v3);
    void show_montes(std::vector<p3::Carta> montes);
    int get_play();
    int tela_inicio();
    void show_winner(int pos);
    void show_pontuation(std::vector<int>);
    void show_position(std::vector<int> p);

private slots:
    void on_play_clicked();
    void on_esquerda_clicked();
    void on_direita_clicked();
    void on_pass_clicked();
    void on_novo_jogo_clicked();
    void on_instructions_clicked();
    void on_voltar_clicked();
    void quiting();

private:
    Ui::TelaPresidente *ui;
    WinnerWindow *win;
    QGraphicsScene *sceneGame;
    QGraphicsScene *sceneMenu;
    QGraphicsScene *sceneInstructions;
    QString playername;
    QGraphicsPolygonItem *cursor;
    int select;
    int select_max;
};

#endif // TELAPRESIDENTE_H
