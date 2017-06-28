#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <string>
#include "ui_mainwindow.h"
#include "../Paciencia/paciencia.h"
#include "../Paciencia/tela.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualiza_jogo();

    void list_botton();

    void fim_jogo();

    void atualiza_dados();

    void jogador(QString nome);

private slots:
    void on_m_0_clicked();

    void on_m_1_clicked();

    void on_m_2_clicked();

    void on_m_3_clicked();

    void on_m_4_clicked();

    void on_m_5_clicked();

    void on_m_6_clicked();

    void on_m_7_clicked();

    void on_m_8_clicked();

    void on_m_9_clicked();

    void on_m_10_clicked();

    void on_m_11_clicked();

    void on_m_12_clicked();

private:
    Ui::MainWindow *ui;

    p3::Paciencia _pac;
    p3::Tela _tel;

    int jogada[2];
    int _click = 0;
    QList<QPushButton *> m;//= {ui->m_0, ui->m_1, ui->m_2, ui->m_3, ui->m_4, ui->m_5, ui->m_6, ui->m_7, ui->m_8, ui->m_9, ui->m_10, ui->m_11, ui->m_12};

};

#endif // MAINWINDOW_H
