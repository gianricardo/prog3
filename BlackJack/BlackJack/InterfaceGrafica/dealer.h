#ifndef DEALER_H
#define DEALER_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class dealer;
}

class dealer : public QDialog
{
    Q_OBJECT

public:
    explicit dealer(QWidget *parent = 0);
    ~dealer();

private:
    Ui::dealer *ui;
};

#endif // DEALER_H
