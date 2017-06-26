#ifndef OBG_H
#define OBG_H

#include <QDialog>

namespace Ui {
class obg;
}

class obg : public QDialog
{
    Q_OBJECT

public:
    explicit obg(QWidget *parent = 0);
    ~obg();

private:
    Ui::obg *ui;
};

#endif // OBG_H
