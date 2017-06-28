/********************************************************************************
** Form generated from reading UI file 'rounds.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDS_H
#define UI_ROUNDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rounds
{
public:
    QSlider *horizontalSlider;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Rounds)
    {
        if (Rounds->objectName().isEmpty())
            Rounds->setObjectName(QStringLiteral("Rounds"));
        Rounds->resize(200, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Rounds->sizePolicy().hasHeightForWidth());
        Rounds->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        Rounds->setFont(font);
        horizontalSlider = new QSlider(Rounds);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 50, 160, 16));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(15);
        horizontalSlider->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(Rounds);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 200, 150));
        lineEdit = new QLineEdit(Rounds);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 80, 60, 25));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        lineEdit->setPalette(palette);
        label = new QLabel(Rounds);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 100, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        label->setPalette(palette1);
        label->setFont(font);
        pushButton = new QPushButton(Rounds);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(55, 120, 90, 25));
        pushButton->setFont(font);
        graphicsView->raise();
        horizontalSlider->raise();
        lineEdit->raise();
        label->raise();
        pushButton->raise();

        retranslateUi(Rounds);

        QMetaObject::connectSlotsByName(Rounds);
    } // setupUi

    void retranslateUi(QWidget *Rounds)
    {
        Rounds->setWindowTitle(QApplication::translate("Rounds", "Presidente", 0));
        lineEdit->setText(QApplication::translate("Rounds", "1", 0));
        label->setText(QApplication::translate("Rounds", "Rodadas", 0));
        pushButton->setText(QApplication::translate("Rounds", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Rounds: public Ui_Rounds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDS_H
