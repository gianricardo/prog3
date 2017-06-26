/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionhit;
    QAction *actiondouble;
    QAction *actionstay;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *line;
    QWidget *acaow;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QPushButton *hit;
    QPushButton *double_2;
    QPushButton *stay;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QFrame *placarw;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *apostaatual;
    QLineEdit *saldo;
    QLabel *label_2;
    QLineEdit *nomedojogador;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(640, 360);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionhit = new QAction(MainWindow);
        actionhit->setObjectName(QStringLiteral("actionhit"));
        actiondouble = new QAction(MainWindow);
        actiondouble->setObjectName(QStringLiteral("actiondouble"));
        actionstay = new QAction(MainWindow);
        actionstay->setObjectName(QStringLiteral("actionstay"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 1, 1, 1);

        acaow = new QWidget(centralwidget);
        acaow->setObjectName(QStringLiteral("acaow"));
        verticalLayout = new QVBoxLayout(acaow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(acaow);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        hit = new QPushButton(acaow);
        hit->setObjectName(QStringLiteral("hit"));

        verticalLayout->addWidget(hit);

        double_2 = new QPushButton(acaow);
        double_2->setObjectName(QStringLiteral("double_2"));

        verticalLayout->addWidget(double_2);

        stay = new QPushButton(acaow);
        stay->setObjectName(QStringLiteral("stay"));

        verticalLayout->addWidget(stay);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(acaow, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral("graphicsView{ background:rgb(0, 128, 0)}"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 3, 1);

        placarw = new QFrame(centralwidget);
        placarw->setObjectName(QStringLiteral("placarw"));
        placarw->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(placarw->sizePolicy().hasHeightForWidth());
        placarw->setSizePolicy(sizePolicy);
        placarw->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(placarw);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(placarw);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        apostaatual = new QLineEdit(placarw);
        apostaatual->setObjectName(QStringLiteral("apostaatual"));
        apostaatual->setReadOnly(true);

        gridLayout->addWidget(apostaatual, 6, 0, 1, 1);

        saldo = new QLineEdit(placarw);
        saldo->setObjectName(QStringLiteral("saldo"));
        saldo->setReadOnly(true);

        gridLayout->addWidget(saldo, 4, 0, 1, 1);

        label_2 = new QLabel(placarw);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        nomedojogador = new QLineEdit(placarw);
        nomedojogador->setObjectName(QStringLiteral("nomedojogador"));
        nomedojogador->setReadOnly(true);

        gridLayout->addWidget(nomedojogador, 0, 0, 1, 1);


        gridLayout_2->addWidget(placarw, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(hit, SIGNAL(clicked()), actionhit, SLOT(trigger()));
        QObject::connect(stay, SIGNAL(clicked()), actionstay, SLOT(trigger()));
        QObject::connect(double_2, SIGNAL(clicked()), actiondouble, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionhit->setText(QApplication::translate("MainWindow", "hit", Q_NULLPTR));
        actiondouble->setText(QApplication::translate("MainWindow", "double", Q_NULLPTR));
        actionstay->setText(QApplication::translate("MainWindow", "stay", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Selecione uma a\303\247\303\243o:", Q_NULLPTR));
        hit->setText(QApplication::translate("MainWindow", "Pedir carta", Q_NULLPTR));
        double_2->setText(QApplication::translate("MainWindow", "Dobrar aposta", Q_NULLPTR));
        stay->setText(QApplication::translate("MainWindow", "Finalijar jogada", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Saldo:", Q_NULLPTR));
        apostaatual->setText(QApplication::translate("MainWindow", "$0,00", Q_NULLPTR));
        saldo->setText(QApplication::translate("MainWindow", "$1000,00", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Aposta atual:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
