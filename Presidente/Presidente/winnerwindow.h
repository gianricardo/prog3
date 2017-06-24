#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QGraphicsScene>

namespace Ui {
class WinnerWindow;
}

class WinnerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerWindow(QWidget *parent = 0);
    ~WinnerWindow();
    void mostra_vencedor(int pos);
private slots:

private:
    QGraphicsScene *scene;
    Ui::WinnerWindow *ui;
};

#endif // WINNERWINDOW_H
