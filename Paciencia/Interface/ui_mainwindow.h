/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QSplitter *splitter;
    QPushButton *m_2;
    QPushButton *m_3;
    QPushButton *m_4;
    QPushButton *m_5;
    QSplitter *splitter_2;
    QPushButton *m_6;
    QPushButton *m_7;
    QPushButton *m_8;
    QPushButton *m_9;
    QPushButton *m_10;
    QPushButton *m_11;
    QPushButton *m_12;
    QSplitter *splitter_3;
    QPushButton *m_0;
    QPushButton *m_1;
    QSplitter *splitter_5;
    QSplitter *splitter_4;
    QLabel *nome_jogador;
    QLabel *pontuacao;
    QLabel *jogada;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1275, 652);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 540, 1261, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(580, 20, 671, 211));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(20);
        m_2 = new QPushButton(splitter);
        m_2->setObjectName(QStringLiteral("m_2"));
        splitter->addWidget(m_2);
        m_3 = new QPushButton(splitter);
        m_3->setObjectName(QStringLiteral("m_3"));
        splitter->addWidget(m_3);
        m_4 = new QPushButton(splitter);
        m_4->setObjectName(QStringLiteral("m_4"));
        splitter->addWidget(m_4);
        m_5 = new QPushButton(splitter);
        m_5->setObjectName(QStringLiteral("m_5"));
        splitter->addWidget(m_5);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 310, 1251, 221));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(25);
        m_6 = new QPushButton(splitter_2);
        m_6->setObjectName(QStringLiteral("m_6"));
        splitter_2->addWidget(m_6);
        m_7 = new QPushButton(splitter_2);
        m_7->setObjectName(QStringLiteral("m_7"));
        splitter_2->addWidget(m_7);
        m_8 = new QPushButton(splitter_2);
        m_8->setObjectName(QStringLiteral("m_8"));
        splitter_2->addWidget(m_8);
        m_9 = new QPushButton(splitter_2);
        m_9->setObjectName(QStringLiteral("m_9"));
        splitter_2->addWidget(m_9);
        m_10 = new QPushButton(splitter_2);
        m_10->setObjectName(QStringLiteral("m_10"));
        splitter_2->addWidget(m_10);
        m_11 = new QPushButton(splitter_2);
        m_11->setObjectName(QStringLiteral("m_11"));
        splitter_2->addWidget(m_11);
        m_12 = new QPushButton(splitter_2);
        m_12->setObjectName(QStringLiteral("m_12"));
        splitter_2->addWidget(m_12);
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setEnabled(true);
        splitter_3->setGeometry(QRect(20, 20, 361, 211));
        splitter_3->setAutoFillBackground(true);
        splitter_3->setStyleSheet(QStringLiteral(""));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setHandleWidth(30);
        splitter_3->setChildrenCollapsible(true);
        m_0 = new QPushButton(splitter_3);
        m_0->setObjectName(QStringLiteral("m_0"));
        m_0->setStyleSheet(QStringLiteral("background-image: url(:/baralho/back.jpg);"));
        splitter_3->addWidget(m_0);
        m_1 = new QPushButton(splitter_3);
        m_1->setObjectName(QStringLiteral("m_1"));
        m_1->setEnabled(true);
        m_1->setStyleSheet(QStringLiteral(""));
        splitter_3->addWidget(m_1);
        splitter_5 = new QSplitter(centralWidget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(20, 560, 1241, 20));
        splitter_5->setOrientation(Qt::Horizontal);
        splitter_5->setHandleWidth(500);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setHandleWidth(100);
        nome_jogador = new QLabel(splitter_4);
        nome_jogador->setObjectName(QStringLiteral("nome_jogador"));
        splitter_4->addWidget(nome_jogador);
        pontuacao = new QLabel(splitter_4);
        pontuacao->setObjectName(QStringLiteral("pontuacao"));
        splitter_4->addWidget(pontuacao);
        splitter_5->addWidget(splitter_4);
        jogada = new QLabel(splitter_5);
        jogada->setObjectName(QStringLiteral("jogada"));
        splitter_5->addWidget(jogada);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1275, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        m_2->setText(QString());
        m_3->setText(QString());
        m_4->setText(QString());
        m_5->setText(QString());
        m_6->setText(QString());
        m_7->setText(QString());
        m_8->setText(QString());
        m_9->setText(QString());
        m_10->setText(QString());
        m_11->setText(QString());
        m_12->setText(QString());
        m_0->setText(QString());
        m_1->setText(QString());
        nome_jogador->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pontuacao->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        jogada->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
