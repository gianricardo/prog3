/********************************************************************************
** Form generated from reading UI file 'trunfoui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUNFOUI_H
#define UI_TRUNFOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *bottomButtonsWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *quitButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrunfoUI)
    {
        if (TrunfoUI->objectName().isEmpty())
            TrunfoUI->setObjectName(QStringLiteral("TrunfoUI"));
        TrunfoUI->resize(800, 600);
        TrunfoUI->setMinimumSize(QSize(800, 600));
        TrunfoUI->setMaximumSize(QSize(800, 600));
        TrunfoUI->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(TrunfoUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(-1, -1, 821, 600));
        QBrush brush(QColor(0, 100, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 100, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        titleLayout = new QWidget(centralWidget);
        titleLayout->setObjectName(QStringLiteral("titleLayout"));
        titleLayout->setGeometry(QRect(210, 50, 400, 411));
        welcomeLayout = new QVBoxLayout(titleLayout);
        welcomeLayout->setSpacing(6);
        welcomeLayout->setContentsMargins(11, 11, 11, 11);
        welcomeLayout->setObjectName(QStringLiteral("welcomeLayout"));
        gameTitle = new QLabel(titleLayout);
        gameTitle->setObjectName(QStringLiteral("gameTitle"));
        gameTitle->setEnabled(true);
        QFont font;
        font.setFamily(QStringLiteral("NanumGothic"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        gameTitle->setFont(font);
        gameTitle->setLayoutDirection(Qt::LeftToRight);

        welcomeLayout->addWidget(gameTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        welcomeLayout->addItem(verticalSpacer);

        buttonPlay = new QPushButton(titleLayout);
        buttonPlay->setObjectName(QStringLiteral("buttonPlay"));
        buttonPlay->setMinimumSize(QSize(0, 75));

        welcomeLayout->addWidget(buttonPlay);

        buttonInstructions = new QPushButton(titleLayout);
        buttonInstructions->setObjectName(QStringLiteral("buttonInstructions"));
        buttonInstructions->setMinimumSize(QSize(0, 50));

        welcomeLayout->addWidget(buttonInstructions);

        bottomButtonsWidget = new QWidget(centralWidget);
        bottomButtonsWidget->setObjectName(QStringLiteral("bottomButtonsWidget"));
        bottomButtonsWidget->setGeometry(QRect(0, 500, 184, 74));
        horizontalLayout = new QHBoxLayout(bottomButtonsWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        quitButton = new QPushButton(bottomButtonsWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout->addWidget(quitButton);

        TrunfoUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TrunfoUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrunfoUI->setStatusBar(statusBar);

        retranslateUi(TrunfoUI);

        QMetaObject::connectSlotsByName(TrunfoUI);
    } // setupUi

    void retranslateUi(QMainWindow *TrunfoUI)
    {
        TrunfoUI->setWindowTitle(QApplication::translate("TrunfoUI", "SuperTrunfo", Q_NULLPTR));
        gameTitle->setText(QApplication::translate("TrunfoUI", "Super Trunfo", Q_NULLPTR));
        buttonPlay->setText(QApplication::translate("TrunfoUI", "Jogar", Q_NULLPTR));
        buttonInstructions->setText(QApplication::translate("TrunfoUI", "Instru\303\247\303\265es", Q_NULLPTR));
        quitButton->setText(QApplication::translate("TrunfoUI", "Sair", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrunfoUI: public Ui_TrunfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUNFOUI_H
