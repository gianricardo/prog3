#ifndef NAMESDIALOG_H
#define NAMESDIALOG_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class namesDialog;
}

class namesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit namesDialog(QWidget *parent = 0);
    ~namesDialog();

    std::vector<std::string> ask();

private slots:
    void on_okButton_clicked();

private:
    Ui::namesDialog *ui;
    std::string player_1_name;
    std::string player_2_name;
};

#endif // NAMESDIALOG_H
