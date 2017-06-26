#ifndef CONTINUA_H
#define CONTINUA_H

#include <QDialog>

namespace Ui {
class continua;
}

class continua : public QDialog
{
    Q_OBJECT

public:
    explicit continua(QWidget *parent = 0);
    ~continua();


private:
    Ui::continua *ui;
};

#endif // CONTINUA_H
