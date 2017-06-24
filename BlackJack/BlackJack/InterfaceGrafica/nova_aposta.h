#ifndef NOVA_APOSTA_H
#define NOVA_APOSTA_H

#include <QDialog>

namespace Ui {
class nova_aposta;
}

class nova_aposta : public QDialog
{
    Q_OBJECT

public:
    explicit nova_aposta(QWidget *parent = 0);
    ~nova_aposta();
    int val();

private:
    Ui::nova_aposta *ui;
};

#endif // NOVA_APOSTA_H
