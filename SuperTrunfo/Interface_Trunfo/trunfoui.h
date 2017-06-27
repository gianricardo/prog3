#ifndef TRUNFOUI_H
#define TRUNFOUI_H

#include <vector>
#include <string>
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QColor>
#include <QPushButton>
#include <QLabel>
#include <QSize>
#include <QPoint>
#include <QBoxLayout>
#include <QPalette>
#include <QGraphicsWidget>
#include <card.h>
#include <quitdialog.h>
#include <instructions.h>
#include <namesdialog.h>
#include <QEventLoop>
#include <timer.h>
#include <QMessageBox>
#include <QFormLayout>

namespace Ui {
class TrunfoUI;
}

class TrunfoUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrunfoUI(QWidget *parent = 0);
    ~TrunfoUI();
    std::vector<std::string> ask_names();
    void set_cards(int card_1_index, int card_2_index);
    void reset_cards();
    void wait_for_game_start();
    int get_play();
    void wait(int seconds);
    void update_cards();
    void reset_shown();
    void show_both_cards();
    void print_attributes_label(int attr);
    void print_cards_amount(int amount_1, int amount_2);
    void print_round_winner(std::string winner);
    void print_round_draw();
    void reset_round_winner();
    void print_game_winner(std::string winner);
    bool window_closed();

protected:
    void setup_game();
    void generate_scene_welcome();
    QWidget *generate_scene_game();
    void reset_game_scene();
    void closeEvent(QCloseEvent *e) override;

    void connect_loop_signals();
    void set_scene_welcome();
    void set_scene_game();
    void create_buttons(QWidget *buttonsWidget);
    void create_cards(QWidget *cardsWidget);
    void create_cards_label();

public slots:
    void on_buttonPlay_clicked();

    void on_quitButton_clicked();

    void on_buttonInstructions_clicked();

    void partGps();

    void titMundiais();

    void vitorias();

    void polePositions();

    void gpsPodios();

private slots:


private:
    Ui::TrunfoUI *ui;
    QGraphicsScene *scene;
    QWidget *game_widget = nullptr;
    QWidget *welcome_widget = nullptr;

    QEventLoop loop;
    Timer *timer;

    QWidget *_buttonsWidget;

    Card *_card_1;
    Card *_card_2;

    QWidget *cardsLabelWidget;
    QLabel *cards_label_1;
    QLabel *cards_label_2;
    QLabel *winner_label;
    QLabel *attr_label;

    QPointF card_1_point;
    QPointF card_2_point;

    int play_made;
    bool _window_closed;
};

#endif // TRUNFOUI_H
