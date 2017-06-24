#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "game.h"

namespace Ui {
class Window;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(std::string player, QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::Window *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;

    OneSuitGame game;
};

#endif // WINDOW_H
