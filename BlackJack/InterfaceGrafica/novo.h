#ifndef NOVO_H
#define NOVO_H

#include <QDialog>

namespace Ui {
class novo;
}

class novo : public QDialog
{
    Q_OBJECT

public:
    explicit novo(QWidget *parent = 0);
    ~novo();
    QString nome();
private:
    Ui::novo *ui;
};

#endif // NOVO_H
