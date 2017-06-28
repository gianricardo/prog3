#ifndef QUITDIALOG_H
#define QUITDIALOG_H

#include <QDialog>
//#include <trunfoui.h>

namespace Ui {
class quitDialog;
}

class quitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit quitDialog(QWidget *parent = 0);
    ~quitDialog();
    bool quit();

public slots:


private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::quitDialog *ui;
    bool answer;


};

#endif // QUITDIALOG_H
