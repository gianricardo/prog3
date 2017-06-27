#include <chrono>
#include <thread>

#include "trunfoui.h"
#include "ui_trunfoui.h"

TrunfoUI::TrunfoUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrunfoUI),
    card_1_point(0, 0),
    card_2_point(card_1_point.x()+125+5, 0)

{
    ui->setupUi(this);

    _window_closed = false;

    timer = new Timer(this);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QColor(0,100,0));

    generate_scene_welcome();

    welcome_widget = ui->titleLayout;
    set_scene_welcome();
    ui->graphicsView->setScene(scene);
}

TrunfoUI::~TrunfoUI()
{
    delete _card_1;
    delete _card_2;
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
    buttonsWidget->setGeometry(0, 250, 250, 250);

    QWidget *cardsWidget = new QWidget(gameWidget);
    cardsWidget->setGeometry(250, 10 ,550, 500);

    create_buttons(buttonsWidget);
    create_cards(cardsWidget);

    ui->bottomButtonsWidget->raise();
    ui->bottomButtonsWidget->setWindowFlags(Qt::WindowStaysOnTopHint);

    return gameWidget;
}

void TrunfoUI::reset_game_scene()
{
    game_widget->close();
    game_widget = generate_scene_game();
}

void TrunfoUI::closeEvent(QCloseEvent *e)
{
    _window_closed = true;
    QMainWindow::closeEvent(e);
}

void TrunfoUI::connect_loop_signals()
{

}

void TrunfoUI::setup_game()
{
    _card_1 = nullptr;
    _card_2 = nullptr;

    game_widget = generate_scene_game();
    create_cards_label();

    _buttonsWidget->setDisabled(true);

    ui->bottomButtonsWidget->raise();

    _card_1->setShown(true);
    _card_2->setShown(false);

    update_cards();
}

std::vector<std::__cxx11::string> TrunfoUI::ask_names()
{
    namesDialog *names = new namesDialog(this);

    return names->ask();
}

void TrunfoUI::set_cards(int card_1_index, int card_2_index)
{
    _card_1->change_card(card_1_index);
    _card_2->change_card(card_2_index);
    update_cards();
}

void TrunfoUI::reset_cards()
{
    if(_card_1 != nullptr)
    {
        delete _card_1;
        _card_1 = nullptr;
    }

    if(_card_2 != nullptr)
    {
        delete _card_2;
        _card_2 = nullptr;
    }
}

void TrunfoUI::wait_for_game_start()
{
    QObject::connect(ui->buttonPlay, SIGNAL(clicked()),&loop, SLOT(quit()));
    this->show();
    loop.exec();
}

int TrunfoUI::get_play()
{
    _buttonsWidget->setEnabled(true);
    loop.exec();
    _buttonsWidget->setDisabled(true);
    return play_made;
}

void TrunfoUI::wait(int seconds)
{
    timer->start_timer(seconds);
}

void TrunfoUI::update_cards()
{
    _card_1->update();
    _card_2->update();
}

void TrunfoUI::reset_shown()
{
    _card_1->setShown(true);
    _card_2->setShown(false);

    update_cards();
}

void TrunfoUI::show_both_cards()
{
    _card_1->setShown(true);
    _card_2->setShown(true);

    update_cards();
}

void TrunfoUI::print_attributes_label(int attr)
{
    QString str;
    switch(attr)
    {
    case 1:
        str.append(QString::fromUtf8("Participação em gps"));
        break;

    case 2:
        str.append(QString::fromUtf8("Títulos mundiais"));
        break;

    case 3:
        str.append(QString::fromUtf8("Vitórias"));
        break;

    case 4:
        str.append(QString::fromUtf8("Pole positions"));
        break;

    case 5:
        str.append(QString::fromUtf8("GPS com pódios"));
        break;

    }
    attr_label->setText(str);
}

void TrunfoUI::print_cards_amount(int amount_1, int amount_2)
{
    cards_label_1->setText(QString::number(amount_1));
    cards_label_2->setText(QString::number(amount_2));
}

void TrunfoUI::print_round_winner(std::__cxx11::string winner)
{
    QString str;
    str.append(QString::fromStdString(winner));
    str.append(" ganhou!");

    winner_label->setText(str);
}

void TrunfoUI::print_round_draw()
{
    winner_label->setText(QString("Empatou!"));
}

void TrunfoUI::reset_round_winner()
{
    winner_label->setText(QString(" "));
    attr_label->setText(QString(" "));
}

void TrunfoUI::print_game_winner(std::__cxx11::string winner)
{
    QString str;
    str.append(QString::fromStdString(winner));
    str.append(QString(" venceu o jogo!"));
    QMessageBox::information(this, "Venceu!", str);
}

bool TrunfoUI::window_closed()
{
    return _window_closed;
}

void TrunfoUI::set_scene_welcome()
{
    if(game_widget != nullptr) game_widget->hide();
    welcome_widget->show();
}

void TrunfoUI::set_scene_game()
{
    welcome_widget->hide();
    game_widget->show();
    ui->bottomButtonsWidget->setWindowFlags(Qt::WindowStaysOnTopHint);
}

void TrunfoUI::create_buttons(QWidget *buttonsWidget)
{
    QVBoxLayout *buttonsLayout = new QVBoxLayout(buttonsWidget);
    buttonsLayout->setSpacing(6);
    buttonsLayout->setContentsMargins(11,11,11,11);

    QPushButton *partGps = new QPushButton(buttonsWidget);
    QPushButton *titMundiais = new QPushButton(buttonsWidget);
    QPushButton *vitorias = new QPushButton(buttonsWidget);
    QPushButton *polePositions = new QPushButton(buttonsWidget);
    QPushButton *gpsPodios = new QPushButton(buttonsWidget);

    partGps->setObjectName(QString("partGps"));
    titMundiais->setObjectName(QString("titMundiais"));
    vitorias->setObjectName(QString("vitorias"));
    polePositions->setObjectName(QString("polePositions"));
    gpsPodios->setObjectName(QString("gpsPodios"));

    partGps->setMinimumSize(200,0);
    titMundiais->setMinimumSize(200,0);
    vitorias->setMinimumSize(200,0);
    polePositions->setMinimumSize(200,0);
    gpsPodios->setMinimumSize(200,0);

    partGps->setText(QString::fromUtf8("Participação em GPs"));
    titMundiais->setText(QString::fromUtf8("Títulos mundiais de construtores"));
    vitorias->setText(QString::fromUtf8("Vitórias"));
    polePositions->setText(QString::fromUtf8("Pole positions"));
    gpsPodios->setText(QString::fromUtf8("GPs com pódios"));

    buttonsLayout->addWidget(partGps);
    buttonsLayout->addWidget(titMundiais);
    buttonsLayout->addWidget(vitorias);
    buttonsLayout->addWidget(polePositions);
    buttonsLayout->addWidget(gpsPodios);

    QObject::connect(partGps, SIGNAL(clicked()), this, SLOT(partGps()) );
    QObject::connect(titMundiais, SIGNAL(clicked()), this, SLOT(titMundiais()));
    QObject::connect(vitorias, SIGNAL(clicked()), this, SLOT(vitorias()));
    QObject::connect(polePositions, SIGNAL(clicked()), this, SLOT(polePositions()));
    QObject::connect(gpsPodios, SIGNAL(clicked()), this, SLOT(gpsPodios()));

    QObject::connect(partGps, SIGNAL(clicked()), &loop, SLOT(quit()) );
    QObject::connect(titMundiais, SIGNAL(clicked()), &loop, SLOT(quit()) );
    QObject::connect(vitorias, SIGNAL(clicked()), &loop, SLOT(quit()) );
    QObject::connect(polePositions, SIGNAL(clicked()), &loop, SLOT(quit()) );
    QObject::connect(gpsPodios, SIGNAL(clicked()), &loop, SLOT(quit()) );

    _buttonsWidget = buttonsWidget;
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

    _card_1 = card_1;
    _card_2 = card_2;

    _card_1->setShown(true);
    _card_2->setShown(false);

    cardsView->setScene(cardsScene);
}

void TrunfoUI::create_cards_label()
{
    cardsLabelWidget = new QWidget(game_widget);
    cardsLabelWidget->setGeometry(0, 100, 200, 140);

    QVBoxLayout *labelLayout = new QVBoxLayout(cardsLabelWidget);
    QHBoxLayout *player1Layout = new QHBoxLayout(); //TODO fix
    QHBoxLayout *player2Layout = new QHBoxLayout();

    attr_label = new QLabel(QString(" "), cardsLabelWidget);
    attr_label->setStyleSheet("QLabel { background-color : white; color : black; }");
    labelLayout->addWidget(attr_label);


    winner_label = new QLabel(QString::fromUtf8(" "), cardsLabelWidget);
    winner_label->setStyleSheet("QLabel { background-color : white; color : black; }");
    labelLayout->addWidget(winner_label);

    QLabel *cardsLabel = new QLabel(QString::fromUtf8("Número de cartas"), cardsLabelWidget);
    cardsLabel->setStyleSheet("QLabel { background-color : white; color : black; }");
    labelLayout->addWidget(cardsLabel);


    QLabel *player1Label = new QLabel(QString::fromUtf8("Jogador 1:"), cardsLabelWidget);
    player1Label->setStyleSheet("QLabel { background-color : white; color : black; }");
    cards_label_1 = new QLabel(QString(" "), cardsLabelWidget);
    cards_label_1->setStyleSheet("QLabel { background-color : white; color : black; }");
    player1Layout->addWidget(player1Label);
    player1Layout->addWidget(cards_label_1);
    labelLayout->addItem(player1Layout);
    connect(labelLayout, SIGNAL(destroyed(QObject*)), player1Layout, SLOT(deleteLater()));

    QLabel *player2Label = new QLabel(QString::fromUtf8("Jogador 2:"), cardsLabelWidget);
    player2Label->setStyleSheet("QLabel { background-color : white; color : black; }");
    cards_label_2 = new QLabel(QString(" "), cardsLabelWidget);
    cards_label_2->setStyleSheet("QLabel { background-color : white; color : black; }");
    player2Layout->addWidget(player2Label);
    player2Layout->addWidget(cards_label_2);
    labelLayout->addItem(player2Layout);
    connect(labelLayout, SIGNAL(destroyed(QObject*)), player2Layout, SLOT(deleteLater()));

}

void TrunfoUI::on_buttonPlay_clicked()
{
    if(game_widget != nullptr)  reset_game_scene();
    setup_game();
    set_scene_game();
}

void TrunfoUI::on_quitButton_clicked()
{
    quitDialog quit;
    quit.setModal(true);
    _window_closed = quit.quit();
}

void TrunfoUI::on_buttonInstructions_clicked()
{
    Instructions instructions;
    instructions.setModal(true);
    instructions.exec();
}

void TrunfoUI::partGps()
{
    play_made = 1;
}

void TrunfoUI::titMundiais()
{
    play_made = 2;
}

void TrunfoUI::vitorias()
{
    play_made = 3;
}

void TrunfoUI::polePositions()
{
    play_made = 4;
}

void TrunfoUI::gpsPodios()
{
    play_made = 5;
}
