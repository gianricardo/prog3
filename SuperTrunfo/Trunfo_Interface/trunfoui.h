#ifndef TRUNFOUI_H
#define TRUNFOUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColor>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class TrunfoUI;
}

class TrunfoUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrunfoUI(QWidget *parent = 0);
    ~TrunfoUI();

protected:
    void generate_scene_welcome();
    void generate_scene_game();

private:
    Ui::TrunfoUI *ui;
    QGraphicsScene *game_scene;
    QGraphicsScene *welcome_scene;

};

#endif // TRUNFOUI_H
