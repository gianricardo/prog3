/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInicio_jogo;
    QWidget *centralWidget;
    QWidget *layout_turnos;
    QVBoxLayout *lala;
    QPushButton *b_turno_0;
    QPushButton *b_turno_1;
    QPushButton *b_turno_2;
    QPushButton *b_turno_3;
    QPushButton *b_turno_4;
    QPushButton *b_turno_5;
    QWidget *layout_naipes;
    QVBoxLayout *layout_trunfo;
    QPushButton *b_paus;
    QPushButton *b_copas;
    QPushButton *b_espadas;
    QPushButton *b_ouros;
    QLabel *l_nome_adversario;
    QLabel *l_informacao;
    QLabel *l_rodadas;
    QLabel *l_rodada_atual;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QWidget *layout_jogador;
    QHBoxLayout *horizontalLayout;
    ClickableLabel *i_carta_j1;
    ClickableLabel *i_carta_j2;
    ClickableLabel *i_carta_j3;
    ClickableLabel *i_carta_j4;
    ClickableLabel *i_carta_j5;
    QWidget *layout_adversario;
    QHBoxLayout *horizontalLayout_2;
    ClickableLabel *i_carta_a1;
    ClickableLabel *i_carta_a2;
    ClickableLabel *i_carta_a3;
    ClickableLabel *i_carta_a4;
    ClickableLabel *i_carta_a5;
    QPushButton *b_inicio;
    QLabel *l_aposta_maxima;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_7;
    QLabel *l_carta_escolhida;
    QTextBrowser *textBrowser_8;
    QLabel *l_trunfo_rodada;
    ClickableLabel *i_carta_monte;
    QTextBrowser *textBrowser_9;
    QLabel *l_nome_declarante;
    QLabel *l_nome_jogador;
    QLabel *l_informacao_2;
    QTextBrowser *textBrowser_11;
    QLabel *l_turnos_vencidos;
    QLabel *l_pontuacao_adversario;
    QLabel *l_pontuacao_jogador;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1171, 721);
        QFont font;
        font.setFamily(QStringLiteral("MathJax_Typewriter"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral("background-color:green"));
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionInicio_jogo = new QAction(MainWindow);
        actionInicio_jogo->setObjectName(QStringLiteral("actionInicio_jogo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layout_turnos = new QWidget(centralWidget);
        layout_turnos->setObjectName(QStringLiteral("layout_turnos"));
        layout_turnos->setGeometry(QRect(1020, 10, 71, 241));
        layout_turnos->setFont(font);
        lala = new QVBoxLayout(layout_turnos);
        lala->setSpacing(6);
        lala->setContentsMargins(11, 11, 11, 11);
        lala->setObjectName(QStringLiteral("lala"));
        b_turno_0 = new QPushButton(layout_turnos);
        b_turno_0->setObjectName(QStringLiteral("b_turno_0"));
        QFont font1;
        font1.setFamily(QStringLiteral("MathJax_Typewriter"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        b_turno_0->setFont(font1);

        lala->addWidget(b_turno_0);

        b_turno_1 = new QPushButton(layout_turnos);
        b_turno_1->setObjectName(QStringLiteral("b_turno_1"));
        b_turno_1->setFont(font1);

        lala->addWidget(b_turno_1);

        b_turno_2 = new QPushButton(layout_turnos);
        b_turno_2->setObjectName(QStringLiteral("b_turno_2"));
        b_turno_2->setFont(font1);

        lala->addWidget(b_turno_2);

        b_turno_3 = new QPushButton(layout_turnos);
        b_turno_3->setObjectName(QStringLiteral("b_turno_3"));
        b_turno_3->setFont(font1);

        lala->addWidget(b_turno_3);

        b_turno_4 = new QPushButton(layout_turnos);
        b_turno_4->setObjectName(QStringLiteral("b_turno_4"));
        b_turno_4->setFont(font1);

        lala->addWidget(b_turno_4);

        b_turno_5 = new QPushButton(layout_turnos);
        b_turno_5->setObjectName(QStringLiteral("b_turno_5"));
        b_turno_5->setFont(font1);

        lala->addWidget(b_turno_5);

        layout_naipes = new QWidget(centralWidget);
        layout_naipes->setObjectName(QStringLiteral("layout_naipes"));
        layout_naipes->setGeometry(QRect(940, 20, 71, 231));
        layout_naipes->setFont(font);
        layout_trunfo = new QVBoxLayout(layout_naipes);
        layout_trunfo->setSpacing(6);
        layout_trunfo->setContentsMargins(11, 11, 11, 11);
        layout_trunfo->setObjectName(QStringLiteral("layout_trunfo"));
        b_paus = new QPushButton(layout_naipes);
        b_paus->setObjectName(QStringLiteral("b_paus"));
        b_paus->setFont(font1);

        layout_trunfo->addWidget(b_paus);

        b_copas = new QPushButton(layout_naipes);
        b_copas->setObjectName(QStringLiteral("b_copas"));
        b_copas->setFont(font1);

        layout_trunfo->addWidget(b_copas);

        b_espadas = new QPushButton(layout_naipes);
        b_espadas->setObjectName(QStringLiteral("b_espadas"));
        b_espadas->setFont(font1);

        layout_trunfo->addWidget(b_espadas);

        b_ouros = new QPushButton(layout_naipes);
        b_ouros->setObjectName(QStringLiteral("b_ouros"));
        b_ouros->setFont(font1);

        layout_trunfo->addWidget(b_ouros);

        b_paus->raise();
        b_ouros->raise();
        b_espadas->raise();
        b_copas->raise();
        l_nome_adversario = new QLabel(centralWidget);
        l_nome_adversario->setObjectName(QStringLiteral("l_nome_adversario"));
        l_nome_adversario->setGeometry(QRect(40, 20, 181, 31));
        l_nome_adversario->setFont(font);
        l_nome_adversario->setAutoFillBackground(false);
        l_nome_adversario->setStyleSheet(QStringLiteral("background-color:white"));
        l_nome_adversario->setFrameShape(QFrame::Box);
        l_nome_adversario->setFrameShadow(QFrame::Plain);
        l_nome_adversario->setLineWidth(2);
        l_informacao = new QLabel(centralWidget);
        l_informacao->setObjectName(QStringLiteral("l_informacao"));
        l_informacao->setGeometry(QRect(750, 340, 401, 61));
        l_informacao->setFont(font);
        l_informacao->setAcceptDrops(false);
        l_informacao->setStyleSheet(QStringLiteral("background-color:white"));
        l_informacao->setInputMethodHints(Qt::ImhNone);
        l_informacao->setFrameShape(QFrame::WinPanel);
        l_informacao->setLineWidth(2);
        l_informacao->setScaledContents(true);
        l_informacao->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        l_informacao->setWordWrap(true);
        l_informacao->setMargin(-1);
        l_rodadas = new QLabel(centralWidget);
        l_rodadas->setObjectName(QStringLiteral("l_rodadas"));
        l_rodadas->setGeometry(QRect(860, 30, 41, 31));
        l_rodadas->setFont(font);
        l_rodadas->setStyleSheet(QStringLiteral("background-color:white"));
        l_rodada_atual = new QLabel(centralWidget);
        l_rodada_atual->setObjectName(QStringLiteral("l_rodada_atual"));
        l_rodada_atual->setGeometry(QRect(890, 60, 16, 31));
        l_rodada_atual->setFont(font);
        l_rodada_atual->setStyleSheet(QStringLiteral("background-color:white"));
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(790, 30, 91, 31));
        textBrowser_3->setFont(font);
        textBrowser_3->setStyleSheet(QStringLiteral("background-color:white"));
        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(790, 60, 131, 31));
        textBrowser_4->setFont(font);
        textBrowser_4->setStyleSheet(QStringLiteral("background-color:white"));
        layout_jogador = new QWidget(centralWidget);
        layout_jogador->setObjectName(QStringLiteral("layout_jogador"));
        layout_jogador->setGeometry(QRect(140, 420, 501, 161));
        layout_jogador->setFont(font);
        horizontalLayout = new QHBoxLayout(layout_jogador);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        i_carta_j1 = new ClickableLabel(layout_jogador);
        i_carta_j1->setObjectName(QStringLiteral("i_carta_j1"));
        i_carta_j1->setFont(font);
        i_carta_j1->setCursor(QCursor(Qt::ArrowCursor));
        i_carta_j1->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_j1->setScaledContents(true);

        horizontalLayout->addWidget(i_carta_j1);

        i_carta_j2 = new ClickableLabel(layout_jogador);
        i_carta_j2->setObjectName(QStringLiteral("i_carta_j2"));
        i_carta_j2->setFont(font);
        i_carta_j2->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_j2->setScaledContents(true);

        horizontalLayout->addWidget(i_carta_j2);

        i_carta_j3 = new ClickableLabel(layout_jogador);
        i_carta_j3->setObjectName(QStringLiteral("i_carta_j3"));
        i_carta_j3->setFont(font);
        i_carta_j3->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_j3->setScaledContents(true);

        horizontalLayout->addWidget(i_carta_j3);

        i_carta_j4 = new ClickableLabel(layout_jogador);
        i_carta_j4->setObjectName(QStringLiteral("i_carta_j4"));
        i_carta_j4->setFont(font);
        i_carta_j4->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_j4->setScaledContents(true);

        horizontalLayout->addWidget(i_carta_j4);

        i_carta_j5 = new ClickableLabel(layout_jogador);
        i_carta_j5->setObjectName(QStringLiteral("i_carta_j5"));
        i_carta_j5->setFont(font);
        i_carta_j5->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_j5->setScaledContents(true);

        horizontalLayout->addWidget(i_carta_j5);

        layout_adversario = new QWidget(centralWidget);
        layout_adversario->setObjectName(QStringLiteral("layout_adversario"));
        layout_adversario->setGeometry(QRect(140, 80, 501, 161));
        layout_adversario->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(layout_adversario);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        i_carta_a1 = new ClickableLabel(layout_adversario);
        i_carta_a1->setObjectName(QStringLiteral("i_carta_a1"));
        i_carta_a1->setFont(font);
        i_carta_a1->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_a1->setScaledContents(true);

        horizontalLayout_2->addWidget(i_carta_a1);

        i_carta_a2 = new ClickableLabel(layout_adversario);
        i_carta_a2->setObjectName(QStringLiteral("i_carta_a2"));
        i_carta_a2->setFont(font);
        i_carta_a2->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_a2->setScaledContents(true);

        horizontalLayout_2->addWidget(i_carta_a2);

        i_carta_a3 = new ClickableLabel(layout_adversario);
        i_carta_a3->setObjectName(QStringLiteral("i_carta_a3"));
        i_carta_a3->setFont(font);
        i_carta_a3->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_a3->setScaledContents(true);

        horizontalLayout_2->addWidget(i_carta_a3);

        i_carta_a4 = new ClickableLabel(layout_adversario);
        i_carta_a4->setObjectName(QStringLiteral("i_carta_a4"));
        i_carta_a4->setFont(font);
        i_carta_a4->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_a4->setScaledContents(true);

        horizontalLayout_2->addWidget(i_carta_a4);

        i_carta_a5 = new ClickableLabel(layout_adversario);
        i_carta_a5->setObjectName(QStringLiteral("i_carta_a5"));
        i_carta_a5->setFont(font);
        i_carta_a5->setPixmap(QPixmap(QString::fromUtf8(":/baralho/back.jpg")));
        i_carta_a5->setScaledContents(true);

        horizontalLayout_2->addWidget(i_carta_a5);

        b_inicio = new QPushButton(centralWidget);
        b_inicio->setObjectName(QStringLiteral("b_inicio"));
        b_inicio->setGeometry(QRect(300, 10, 99, 27));
        b_inicio->setFont(font);
        l_aposta_maxima = new QLabel(centralWidget);
        l_aposta_maxima->setObjectName(QStringLiteral("l_aposta_maxima"));
        l_aposta_maxima->setGeometry(QRect(730, 240, 41, 21));
        l_aposta_maxima->setFont(font);
        l_aposta_maxima->setStyleSheet(QStringLiteral("background-color:white"));
        textBrowser_6 = new QTextBrowser(centralWidget);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(660, 220, 141, 51));
        textBrowser_6->setFont(font);
        textBrowser_6->setStyleSheet(QStringLiteral("background-color:white"));
        textBrowser_7 = new QTextBrowser(centralWidget);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(800, 540, 161, 31));
        textBrowser_7->setFont(font);
        textBrowser_7->setStyleSheet(QStringLiteral("background-color:white"));
        l_carta_escolhida = new QLabel(centralWidget);
        l_carta_escolhida->setObjectName(QStringLiteral("l_carta_escolhida"));
        l_carta_escolhida->setGeometry(QRect(920, 550, 41, 21));
        l_carta_escolhida->setFont(font);
        l_carta_escolhida->setStyleSheet(QStringLiteral("background-color:white"));
        textBrowser_8 = new QTextBrowser(centralWidget);
        textBrowser_8->setObjectName(QStringLiteral("textBrowser_8"));
        textBrowser_8->setGeometry(QRect(800, 500, 221, 31));
        textBrowser_8->setFont(font);
        textBrowser_8->setStyleSheet(QStringLiteral("background-color:white"));
        l_trunfo_rodada = new QLabel(centralWidget);
        l_trunfo_rodada->setObjectName(QStringLiteral("l_trunfo_rodada"));
        l_trunfo_rodada->setGeometry(QRect(930, 500, 91, 20));
        l_trunfo_rodada->setFont(font);
        l_trunfo_rodada->setStyleSheet(QStringLiteral("background-color:white"));
        i_carta_monte = new ClickableLabel(centralWidget);
        i_carta_monte->setObjectName(QStringLiteral("i_carta_monte"));
        i_carta_monte->setGeometry(QRect(50, 250, 92, 143));
        i_carta_monte->setFont(font);
        i_carta_monte->setPixmap(QPixmap(QString::fromUtf8(":/baralho/backx.jpg")));
        i_carta_monte->setScaledContents(true);
        textBrowser_9 = new QTextBrowser(centralWidget);
        textBrowser_9->setObjectName(QStringLiteral("textBrowser_9"));
        textBrowser_9->setGeometry(QRect(660, 160, 221, 51));
        textBrowser_9->setFont(font);
        textBrowser_9->setStyleSheet(QStringLiteral("background-color:white"));
        l_nome_declarante = new QLabel(centralWidget);
        l_nome_declarante->setObjectName(QStringLiteral("l_nome_declarante"));
        l_nome_declarante->setGeometry(QRect(710, 180, 121, 31));
        l_nome_declarante->setFont(font);
        l_nome_declarante->setStyleSheet(QStringLiteral("background-color:white"));
        l_nome_jogador = new QLabel(centralWidget);
        l_nome_jogador->setObjectName(QStringLiteral("l_nome_jogador"));
        l_nome_jogador->setGeometry(QRect(20, 610, 161, 31));
        l_nome_jogador->setFont(font);
        l_nome_jogador->setAutoFillBackground(false);
        l_nome_jogador->setStyleSheet(QStringLiteral("background-color:white"));
        l_nome_jogador->setFrameShape(QFrame::Box);
        l_nome_jogador->setFrameShadow(QFrame::Plain);
        l_nome_jogador->setLineWidth(2);
        l_informacao_2 = new QLabel(centralWidget);
        l_informacao_2->setObjectName(QStringLiteral("l_informacao_2"));
        l_informacao_2->setGeometry(QRect(890, 290, 101, 31));
        l_informacao_2->setFont(font);
        l_informacao_2->setStyleSheet(QStringLiteral("background-color:white"));
        l_informacao_2->setFrameShape(QFrame::WinPanel);
        l_informacao_2->setLineWidth(2);
        l_informacao_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        l_informacao_2->setWordWrap(false);
        textBrowser_11 = new QTextBrowser(centralWidget);
        textBrowser_11->setObjectName(QStringLiteral("textBrowser_11"));
        textBrowser_11->setGeometry(QRect(660, 280, 221, 51));
        textBrowser_11->setFont(font);
        textBrowser_11->setStyleSheet(QStringLiteral("background-color:white"));
        l_turnos_vencidos = new QLabel(centralWidget);
        l_turnos_vencidos->setObjectName(QStringLiteral("l_turnos_vencidos"));
        l_turnos_vencidos->setGeometry(QRect(750, 300, 121, 31));
        l_turnos_vencidos->setFont(font);
        l_turnos_vencidos->setStyleSheet(QStringLiteral("background-color:white"));
        l_pontuacao_adversario = new QLabel(centralWidget);
        l_pontuacao_adversario->setObjectName(QStringLiteral("l_pontuacao_adversario"));
        l_pontuacao_adversario->setGeometry(QRect(50, 60, 31, 31));
        l_pontuacao_adversario->setFont(font);
        l_pontuacao_adversario->setStyleSheet(QStringLiteral("background-color:white"));
        l_pontuacao_adversario->setFrameShape(QFrame::WinPanel);
        l_pontuacao_adversario->setFrameShadow(QFrame::Plain);
        l_pontuacao_adversario->setLineWidth(5);
        l_pontuacao_adversario->setAlignment(Qt::AlignCenter);
        l_pontuacao_jogador = new QLabel(centralWidget);
        l_pontuacao_jogador->setObjectName(QStringLiteral("l_pontuacao_jogador"));
        l_pontuacao_jogador->setGeometry(QRect(30, 560, 31, 31));
        l_pontuacao_jogador->setFont(font);
        l_pontuacao_jogador->setStyleSheet(QStringLiteral("background-color:white"));
        l_pontuacao_jogador->setFrameShape(QFrame::WinPanel);
        l_pontuacao_jogador->setFrameShadow(QFrame::Plain);
        l_pontuacao_jogador->setLineWidth(5);
        l_pontuacao_jogador->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        textBrowser_6->raise();
        textBrowser_4->raise();
        textBrowser_3->raise();
        layout_turnos->raise();
        layout_naipes->raise();
        l_nome_adversario->raise();
        l_informacao->raise();
        l_rodadas->raise();
        l_rodada_atual->raise();
        layout_jogador->raise();
        layout_adversario->raise();
        b_inicio->raise();
        l_aposta_maxima->raise();
        textBrowser_7->raise();
        l_carta_escolhida->raise();
        textBrowser_8->raise();
        l_trunfo_rodada->raise();
        i_carta_monte->raise();
        textBrowser_9->raise();
        l_nome_declarante->raise();
        l_nome_jogador->raise();
        l_informacao_2->raise();
        textBrowser_11->raise();
        l_turnos_vencidos->raise();
        l_pontuacao_adversario->raise();
        l_pontuacao_jogador->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(b_inicio, SIGNAL(pressed()), actionInicio_jogo, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Napoleao", Q_NULLPTR));
        actionInicio_jogo->setText(QApplication::translate("MainWindow", "inicio_jogo", Q_NULLPTR));
        b_turno_0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        b_turno_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        b_turno_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        b_turno_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        b_turno_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        b_turno_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        b_paus->setText(QApplication::translate("MainWindow", "\342\231\243", Q_NULLPTR));
        b_copas->setText(QApplication::translate("MainWindow", "\342\231\245", Q_NULLPTR));
        b_espadas->setText(QApplication::translate("MainWindow", "\342\231\240", Q_NULLPTR));
        b_ouros->setText(QApplication::translate("MainWindow", "\342\231\246", Q_NULLPTR));
        l_nome_adversario->setText(QString());
        l_informacao->setText(QString());
        l_rodadas->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        l_rodada_atual->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Rodadas:</span></p></body></html>", Q_NULLPTR));
        textBrowser_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Rodada atual:</span></p></body></html>", Q_NULLPTR));
        i_carta_j1->setText(QString());
        i_carta_j2->setText(QString());
        i_carta_j3->setText(QString());
        i_carta_j4->setText(QString());
        i_carta_j5->setText(QString());
        i_carta_a1->setText(QString());
        i_carta_a2->setText(QString());
        i_carta_a3->setText(QString());
        i_carta_a4->setText(QString());
        i_carta_a5->setText(QString());
        b_inicio->setText(QApplication::translate("MainWindow", "Inicio", Q_NULLPTR));
        l_aposta_maxima->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        textBrowser_6->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Aposta </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">maxima:</span></p></body></html>", Q_NULLPTR));
        textBrowser_7->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Carta escolhida:</span></p></body></html>", Q_NULLPTR));
        l_carta_escolhida->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        textBrowser_8->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Trunfo da rodada:</span></p></body></html>", Q_NULLPTR));
        l_trunfo_rodada->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        i_carta_monte->setText(QString());
        textBrowser_9->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Declarante</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">atual:</span></p></body></html>", Q_NULLPTR));
        l_nome_declarante->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        l_nome_jogador->setText(QString());
        l_informacao_2->setText(QApplication::translate("MainWindow", "Informacoes", Q_NULLPTR));
        textBrowser_11->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MathJax_Typewriter'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">Turnos vencidos pelo</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">declarante:</span></p></body></html>", Q_NULLPTR));
        l_turnos_vencidos->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        l_pontuacao_adversario->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        l_pontuacao_jogador->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
