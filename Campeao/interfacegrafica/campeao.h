#ifndef CAMPEAO_H
#define CAMPEAO_H

#include <QMainWindow>
#include "janela.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "ui_campeao.h"

namespace Ui {
class Campeao;
}

class Campeao : public QMainWindow
{
    Q_OBJECT

public:
    explicit Campeao(QWidget *parent = 0);
    ~Campeao();

private slots:
    void on_actionnova_janela_triggered();

private:
    Ui::Campeao *ui;
    QGraphicsScene * cena_campeao;
};

#endif // CAMPEAO_H
