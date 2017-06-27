#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include "name.h"
#include "qjogo.h"
#include "jogo2.h"
#include "help.h"
#include "../../Truco/jogo_truco.h"
#include "../../Truco/regratruco.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector<std::string> jogadores();
    int numero_jogadores();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    std::vector<std::string> _jogadores;
    int _numero_jogadores;
    Ui::MainWindow *ui;
    Qjogo *_jogo;
    Jogo2 *_jogo2;
    QGraphicsScene *scene;
    QGraphicsTextItem *text;
    QGraphicsRectItem *rect;
    QGraphicsPixmapItem *imagem;
    p4::Regra_Truco *rule;
};

#endif // MAINWINDOW_H
