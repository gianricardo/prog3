#ifndef BEMVINDO_H
#define BEMVINDO_H

#include <QDialog>

namespace Ui {
class bemvindo;
}

class bemvindo : public QDialog
{
    Q_OBJECT

public:
    explicit bemvindo(QWidget *parent = 0);
    ~bemvindo();

private:
    Ui::bemvindo *ui;
};

#endif // BEMVINDO_H
