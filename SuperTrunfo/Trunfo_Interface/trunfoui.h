#ifndef TRUNFOUI_H
#define TRUNFOUI_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QColor>
#include <QPushButton>
#include <QLabel>
#include <QSize>
#include <QPoint>
#include <QBoxLayout>
#include <QGraphicsWidget>
#include <card.h>
#include "card_test.h"

namespace Ui {
class TrunfoUI;
}

class TrunfoUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrunfoUI(QWidget *parent = 0);
    ~TrunfoUI();

protected:
    void generate_scene_welcome();
    QWidget *generate_scene_game();

    void set_scene_welcome();
    void set_scene_game();
    void create_buttons(QWidget *buttonsWidget);
    void create_cards();

private slots:
    void on_buttonPlay_clicked();

private:
    Ui::TrunfoUI *ui;
    QGraphicsScene *scene;
    QWidget *game_widget;
    QWidget *welcome_widget;

    QPoint card_1_point;
    QPoint card_2_point;
    QSize card_size;
};

#endif // TRUNFOUI_H
