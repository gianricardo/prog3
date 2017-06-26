/********************************************************************************
** Form generated from reading UI file 'winnerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINNERWINDOW_H
#define UI_WINNERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WinnerWindow
{
public:
    QLabel *winner;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *WinnerWindow)
    {
        if (WinnerWindow->objectName().isEmpty())
            WinnerWindow->setObjectName(QStringLiteral("WinnerWindow"));
        WinnerWindow->resize(300, 200);
        winner = new QLabel(WinnerWindow);
        winner->setObjectName(QStringLiteral("winner"));
        winner->setGeometry(QRect(0, 50, 300, 100));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(15);
        winner->setFont(font);
        winner->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(WinnerWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 175, 100, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        pushButton->setFont(font1);
        graphicsView = new QGraphicsView(WinnerWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 300, 200));
        graphicsView->raise();
        winner->raise();
        pushButton->raise();

        retranslateUi(WinnerWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), WinnerWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(WinnerWindow);
    } // setupUi

    void retranslateUi(QDialog *WinnerWindow)
    {
        WinnerWindow->setWindowTitle(QApplication::translate("WinnerWindow", "Dialog", Q_NULLPTR));
        winner->setText(QString());
        pushButton->setText(QApplication::translate("WinnerWindow", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WinnerWindow: public Ui_WinnerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINNERWINDOW_H
