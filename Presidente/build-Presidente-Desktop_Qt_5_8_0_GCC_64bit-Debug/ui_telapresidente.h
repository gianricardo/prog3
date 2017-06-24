/********************************************************************************
** Form generated from reading UI file 'telapresidente.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAPRESIDENTE_H
#define UI_TELAPRESIDENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaPresidente
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *titulo;
    QPushButton *esquerda;
    QPushButton *direita;
    QPushButton *pass;
    QPushButton *play;
    QLabel *label;
    QPushButton *novo_jogo;
    QPushButton *instructions;
    QPushButton *voltar;
    QLabel *texto;
    QLineEdit *lineEdit;
    QLabel *west;
    QLabel *nome_jogador;
    QLabel *east;
    QLabel *north;
    QLabel *text;

    void setupUi(QMainWindow *TelaPresidente)
    {
        if (TelaPresidente->objectName().isEmpty())
            TelaPresidente->setObjectName(QStringLiteral("TelaPresidente"));
        TelaPresidente->resize(900, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TelaPresidente->sizePolicy().hasHeightForWidth());
        TelaPresidente->setSizePolicy(sizePolicy);
        TelaPresidente->setMinimumSize(QSize(900, 700));
        TelaPresidente->setMaximumSize(QSize(900, 700));
        centralWidget = new QWidget(TelaPresidente);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 900, 700));
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setAlignment(Qt::AlignCenter);
        titulo = new QLabel(centralWidget);
        titulo->setObjectName(QStringLiteral("titulo"));
        titulo->setGeometry(QRect(300, 100, 300, 100));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(40);
        titulo->setFont(font);
        esquerda = new QPushButton(centralWidget);
        esquerda->setObjectName(QStringLiteral("esquerda"));
        esquerda->setGeometry(QRect(770, 560, 20, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        esquerda->setFont(font1);
        direita = new QPushButton(centralWidget);
        direita->setObjectName(QStringLiteral("direita"));
        direita->setGeometry(QRect(800, 560, 20, 25));
        direita->setFont(font1);
        pass = new QPushButton(centralWidget);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(770, 590, 50, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Purisa"));
        font2.setPointSize(10);
        pass->setFont(font2);
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(830, 560, 50, 55));
        play->setFont(font2);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(425, 450, 50, 25));
        novo_jogo = new QPushButton(centralWidget);
        novo_jogo->setObjectName(QStringLiteral("novo_jogo"));
        novo_jogo->setGeometry(QRect(330, 250, 240, 100));
        QFont font3;
        font3.setFamily(QStringLiteral("Purisa"));
        font3.setPointSize(20);
        novo_jogo->setFont(font3);
        instructions = new QPushButton(centralWidget);
        instructions->setObjectName(QStringLiteral("instructions"));
        instructions->setGeometry(QRect(330, 400, 240, 100));
        instructions->setFont(font3);
        voltar = new QPushButton(centralWidget);
        voltar->setObjectName(QStringLiteral("voltar"));
        voltar->setGeometry(QRect(20, 560, 89, 25));
        voltar->setFont(font1);
        texto = new QLabel(centralWidget);
        texto->setObjectName(QStringLiteral("texto"));
        texto->setGeometry(QRect(330, 200, 120, 25));
        texto->setFont(font2);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(455, 200, 115, 25));
        lineEdit->setFont(font2);
        west = new QLabel(centralWidget);
        west->setObjectName(QStringLiteral("west"));
        west->setGeometry(QRect(50, 60, 50, 17));
        west->setFont(font1);
        nome_jogador = new QLabel(centralWidget);
        nome_jogador->setObjectName(QStringLiteral("nome_jogador"));
        nome_jogador->setGeometry(QRect(400, 475, 100, 17));
        nome_jogador->setFont(font1);
        nome_jogador->setAlignment(Qt::AlignCenter);
        east = new QLabel(centralWidget);
        east->setObjectName(QStringLiteral("east"));
        east->setGeometry(QRect(800, 60, 50, 17));
        east->setFont(font1);
        north = new QLabel(centralWidget);
        north->setObjectName(QStringLiteral("north"));
        north->setGeometry(QRect(425, 10, 50, 17));
        north->setFont(font1);
        text = new QLabel(centralWidget);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(100, 150, 700, 500));
        QFont font4;
        font4.setFamily(QStringLiteral("Purisa"));
        font4.setPointSize(11);
        text->setFont(font4);
        text->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        text->setWordWrap(true);
        TelaPresidente->setCentralWidget(centralWidget);

        retranslateUi(TelaPresidente);

        QMetaObject::connectSlotsByName(TelaPresidente);
    } // setupUi

    void retranslateUi(QMainWindow *TelaPresidente)
    {
        TelaPresidente->setWindowTitle(QApplication::translate("TelaPresidente", "Presidente", Q_NULLPTR));
        titulo->setText(QApplication::translate("TelaPresidente", "Presidente", Q_NULLPTR));
        esquerda->setText(QApplication::translate("TelaPresidente", "<", Q_NULLPTR));
        direita->setText(QApplication::translate("TelaPresidente", ">", Q_NULLPTR));
        pass->setText(QApplication::translate("TelaPresidente", "Passar", Q_NULLPTR));
        play->setText(QApplication::translate("TelaPresidente", "Jogar", Q_NULLPTR));
        label->setText(QApplication::translate("TelaPresidente", "Sua vez", Q_NULLPTR));
        novo_jogo->setText(QApplication::translate("TelaPresidente", "Novo Jogo", Q_NULLPTR));
        instructions->setText(QApplication::translate("TelaPresidente", "Instructions", Q_NULLPTR));
        voltar->setText(QApplication::translate("TelaPresidente", "Voltar", Q_NULLPTR));
        texto->setText(QApplication::translate("TelaPresidente", "Digite seu nome:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("TelaPresidente", "Jogador", Q_NULLPTR));
        west->setText(QApplication::translate("TelaPresidente", "West", Q_NULLPTR));
        nome_jogador->setText(QString());
        east->setText(QApplication::translate("TelaPresidente", "East", Q_NULLPTR));
        north->setText(QApplication::translate("TelaPresidente", "North", Q_NULLPTR));
        text->setText(QApplication::translate("TelaPresidente", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TelaPresidente: public Ui_TelaPresidente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAPRESIDENTE_H
