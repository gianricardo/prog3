#ifndef N_APOSTA_H
#define N_APOSTA_H

#include <QDialog>

namespace Ui {
class n_aposta;
}

class n_aposta : public QDialog
{
    Q_OBJECT

public:
    explicit n_aposta(QWidget *parent = 0);
    ~n_aposta();

private:
    Ui::n_aposta *ui;
};

#endif // N_APOSTA_H
