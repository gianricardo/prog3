#ifndef ROUNDS_H
#define ROUNDS_H

#include <QWidget>
#include <QEventLoop>
#include <QGraphicsScene>

namespace Ui {
class Rounds;
}

class Rounds : public QWidget
{
    Q_OBJECT

public:
    explicit Rounds(QWidget *parent = 0);
    ~Rounds();
    int rodadas();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Rounds *ui;
    QGraphicsScene *scene;
};

#endif // ROUNDS_H
