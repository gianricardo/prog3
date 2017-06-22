#ifndef PARABENS_H
#define PARABENS_H

#include <QDialog>

namespace Ui {
class parabens;
}

class parabens : public QDialog
{
    Q_OBJECT

public:
    explicit parabens(QWidget *parent = 0);
    ~parabens();
    void insere(QString texto);
private:
    Ui::parabens *ui;
};

#endif // PARABENS_H
