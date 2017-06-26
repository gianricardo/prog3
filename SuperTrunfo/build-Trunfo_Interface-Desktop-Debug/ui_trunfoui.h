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
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrunfoUI
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrunfoUI)
    {
        if (TrunfoUI->objectName().isEmpty())
            TrunfoUI->setObjectName(QString::fromUtf8("TrunfoUI"));
        TrunfoUI->resize(800, 600);
        TrunfoUI->setMinimumSize(QSize(800, 600));
        TrunfoUI->setMaximumSize(QSize(1920, 1080));
        centralWidget = new QWidget(TrunfoUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QBrush brush(QColor(0, 100, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 100, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(graphicsView);

        TrunfoUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TrunfoUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        TrunfoUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrunfoUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TrunfoUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrunfoUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TrunfoUI->setStatusBar(statusBar);

        retranslateUi(TrunfoUI);

        QMetaObject::connectSlotsByName(TrunfoUI);
    } // setupUi

    void retranslateUi(QMainWindow *TrunfoUI)
    {
        TrunfoUI->setWindowTitle(QApplication::translate("TrunfoUI", "SuperTrunfo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrunfoUI: public Ui_TrunfoUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUNFOUI_H
