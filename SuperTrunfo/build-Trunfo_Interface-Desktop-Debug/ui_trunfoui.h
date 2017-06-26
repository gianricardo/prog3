/********************************************************************************
** Form generated from reading UI file 'trunfoui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUNFOUI_H
#define UI_TRUNFOUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrunfoUI
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *titleLayout;
    QVBoxLayout *welcomeLayout;
    QLabel *gameTitle;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonPlay;
    QPushButton *buttonInstructions;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrunfoUI)
    {
        if (TrunfoUI->objectName().isEmpty())
            TrunfoUI->setObjectName(QString::fromUtf8("TrunfoUI"));
        TrunfoUI->resize(800, 600);
        TrunfoUI->setMinimumSize(QSize(800, 600));
        TrunfoUI->setMaximumSize(QSize(800, 600));
        TrunfoUI->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(TrunfoUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(-1, -1, 821, 600));
        QBrush brush(QColor(0, 100, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 100, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setAlignment(Qt::AlignCenter);
        titleLayout = new QWidget(centralWidget);
        titleLayout->setObjectName(QString::fromUtf8("titleLayout"));
        titleLayout->setGeometry(QRect(210, 50, 400, 411));
        welcomeLayout = new QVBoxLayout(titleLayout);
        welcomeLayout->setSpacing(6);
        welcomeLayout->setContentsMargins(11, 11, 11, 11);
        welcomeLayout->setObjectName(QString::fromUtf8("welcomeLayout"));
        gameTitle = new QLabel(titleLayout);
        gameTitle->setObjectName(QString::fromUtf8("gameTitle"));
        gameTitle->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("NanumGothic"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        gameTitle->setFont(font);
        gameTitle->setLayoutDirection(Qt::LeftToRight);

        welcomeLayout->addWidget(gameTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        welcomeLayout->addItem(verticalSpacer);

        buttonPlay = new QPushButton(titleLayout);
        buttonPlay->setObjectName(QString::fromUtf8("buttonPlay"));
        buttonPlay->setMinimumSize(QSize(0, 75));

        welcomeLayout->addWidget(buttonPlay);

        buttonInstructions = new QPushButton(titleLayout);
        buttonInstructions->setObjectName(QString::fromUtf8("buttonInstructions"));
        buttonInstructions->setMinimumSize(QSize(0, 50));

        welcomeLayout->addWidget(buttonInstructions);

        TrunfoUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TrunfoUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        TrunfoUI->setMenuBar(menuBar);
        statusBar = new QStatusBar(TrunfoUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TrunfoUI->setStatusBar(statusBar);

        retranslateUi(TrunfoUI);

        QMetaObject::connectSlotsByName(TrunfoUI);
    } // setupUi

    void retranslateUi(QMainWindow *TrunfoUI)
    {
        TrunfoUI->setWindowTitle(QApplication::translate("TrunfoUI", "SuperTrunfo", 0, QApplication::UnicodeUTF8));
        gameTitle->setText(QApplication::translate("TrunfoUI", "Super Trunfo", 0, QApplication::UnicodeUTF8));
        buttonPlay->setText(QApplication::translate("TrunfoUI", "Play", 0, QApplication::UnicodeUTF8));
        buttonInstructions->setText(QApplication::translate("TrunfoUI", "Instructions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrunfoUI: public Ui_TrunfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUNFOUI_H
