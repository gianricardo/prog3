#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPushButton>
#include <QLabel>

#include "game.h"
#include "cardimage.h"

namespace Ui {
class Window;
}

class GameWindow : public QMainWindow , public GameEventHandler {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    void gameover_event(bool won) override;

private slots:

    void __ok_button_pressed__();

private:

    Ui::Window *ui;

    QGraphicsScene *scene;

    OneSuitGame *game;

    QPushButton *ok_button;
    QLabel *label;
};

#endif // WINDOW_H
