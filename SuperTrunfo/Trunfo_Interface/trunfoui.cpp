#include "trunfoui.h"
#include "ui_trunfoui.h"

TrunfoUI::TrunfoUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrunfoUI),
    card_1_point(250, 300),
    card_2_point(460, 300),
    card_size(200, 307)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QColor(0,100,0));

    game_widget = generate_scene_game();
    generate_scene_welcome();
    welcome_widget = ui->titleLayout;

    set_scene_welcome();

    ui->graphicsView->setScene(scene);
}

TrunfoUI::~TrunfoUI()
{
    delete ui;
}

void TrunfoUI::generate_scene_welcome()
{
    ui->gameTitle->setText("<font color='black'>Super Trunfo</font>");

    ui->titleLayout->hide();
}

QWidget *TrunfoUI::generate_scene_game()
{
    QWidget *gameWidget = new QWidget(ui->centralWidget);
    gameWidget->setGeometry(0,0, 800,600);

    QWidget *buttonsWidget = new QWidget(gameWidget);
    buttonsWidget->setGeometry(0, 0, 250, 250);

    QWidget *cardsWidget = new QWidget(gameWidget);
    cardsWidget->setGeometry(250, 0 ,550, 600);

    create_buttons(buttonsWidget);

    return gameWidget;
}

void TrunfoUI::set_scene_welcome()
{
    game_widget->hide();
    welcome_widget->show();
}

void TrunfoUI::set_scene_game()
{
    welcome_widget->hide();
    game_widget->show();
    create_cards();

}

void TrunfoUI::create_buttons(QWidget *buttonsWidget)
{
    QVBoxLayout *buttonsLayout = new QVBoxLayout(buttonsWidget);
    buttonsLayout->setSpacing(6);
    buttonsLayout->setContentsMargins(11,11,11,11);

    QPushButton *part_gps = new QPushButton(buttonsWidget);
    QPushButton *tit_mundiais = new QPushButton(buttonsWidget);
    QPushButton *vitorias = new QPushButton(buttonsWidget);
    QPushButton *pole_positions = new QPushButton(buttonsWidget);
    QPushButton *gps_podios = new QPushButton(buttonsWidget);

    part_gps->setMinimumSize(200,0);
    tit_mundiais->setMinimumSize(200,0);
    vitorias->setMinimumSize(200,0);
    pole_positions->setMinimumSize(200,0);
    gps_podios->setMinimumSize(200,0);

    part_gps->setText(QString::fromUtf8("Participação em GPs"));
    tit_mundiais->setText(QString::fromUtf8("Títulos mundiais de construtores"));
    vitorias->setText(QString::fromUtf8("Vitórias"));
    pole_positions->setText(QString::fromUtf8("Pole positions"));
    gps_podios->setText(QString::fromUtf8("GPs com pódios"));

    buttonsLayout->addWidget(part_gps);
    buttonsLayout->addWidget(tit_mundiais);
    buttonsLayout->addWidget(vitorias);
    buttonsLayout->addWidget(pole_positions);
    buttonsLayout->addWidget(gps_podios);
}

void TrunfoUI::create_cards()
{
    Card *card_1 = new Card(1);
    Card *card_2 = new Card(2);

    scene->addItem(card_1);
    scene->addItem(card_2);
}

void TrunfoUI::on_buttonPlay_clicked()
{
    set_scene_game();
}
