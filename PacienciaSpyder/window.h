#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private:
    Ui::Window *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
};

#endif // WINDOW_H
