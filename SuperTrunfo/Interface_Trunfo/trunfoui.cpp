#include "trunfoui.h"
#include "ui_trunfoui.h"

TrunfoUI::TrunfoUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrunfoUI),
    card_1_point(0, 0),
    card_2_point(card_1_point.x()+125+5, 0)
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

//    gameWidget->set

    QWidget *buttonsWidget = new QWidget(gameWidget);
    buttonsWidget->setGeometry(0, 250, 250, 250);

    QWidget *cardsWidget = new QWidget(gameWidget);
    cardsWidget->setGeometry(250, 10 ,550, 500);

    create_buttons(buttonsWidget);
    create_cards(cardsWidget);

    return gameWidget;
}

void TrunfoUI::set_scene_welcome()

{
    game_widget->hide();
    welcome_widget->show();
    ui->backButton->hide();
}

void TrunfoUI::set_scene_game()
{
    welcome_widget->hide();
    game_widget->show();
    ui->backButton->show();
    ui->bottomButtonsWidget->raise();
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

void TrunfoUI::create_cards(QWidget *cardsWidget)
{
    QGraphicsView *cardsView = new QGraphicsView(cardsWidget);
    QGraphicsScene *cardsScene = new QGraphicsScene(cardsView);

    cardsView->setGeometry(0,0,540,500);
    cardsView->setEnabled(true);
    cardsView->setAlignment(Qt::AlignLeading|Qt::AlignHCenter|Qt::AlignVCenter);
    cardsView->setBackgroundBrush(QColor(0,100,0));

    Card *card_1 = new Card(1);
    Card *card_2 = new Card(2);

    card_1->setPos(card_1_point);
    card_2->setPos(card_2_point);

    cardsScene->addItem(card_1);
    cardsScene->addItem(card_2);

    cardsView->setScene(cardsScene);
}

void TrunfoUI::on_buttonPlay_clicked()
{
    //TODO arrumar jogo
    set_scene_game();
}

void TrunfoUI::on_backButton_clicked()
{
    //TODO resetar jogo
    set_scene_welcome();
}

void TrunfoUI::on_quitButton_clicked()
{
    quitDialog quit;
    quit.setModal(true);
    quit.exec();
}

void TrunfoUI::on_buttonInstructions_clicked()
{
    Instructions instructions;
    instructions.setModal(true);
    instructions.exec();
}
