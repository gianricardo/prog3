#include "trunfoui.h"
#include "ui_trunfoui.h"

TrunfoUI::TrunfoUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrunfoUI)
{
    ui->setupUi(this);

    generate_scene_game();
    generate_scene_welcome();

    ui->graphicsView->setScene(welcome_scene);
}

TrunfoUI::~TrunfoUI()
{
    delete ui;
}

void TrunfoUI::generate_scene_welcome()
{

    welcome_scene = new QGraphicsScene(this);
    welcome_scene->setBackgroundBrush(QColor(0,100,0));

    QLabel *label = new QLabel(ui->centralWidget);
    label->setText("SuperTrunfo");
    //QPushButton *button_play = new QPushButton(ui->centralWidget);
    //QPushButton *button_instructions = new QPushButton(ui->centralWidget);


    label->setAlignment(Qt::AlignHCenter);
    label->setAlignment(Qt::AlignTop);



    welcome_scene->addWidget(label);

}

void TrunfoUI::generate_scene_game()
{
    game_scene = new QGraphicsScene(this);
    game_scene->setBackgroundBrush(QColor(0,100,0));
}
