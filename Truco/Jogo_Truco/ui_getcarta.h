/********************************************************************************
** Form generated from reading UI file 'getcarta.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCARTA_H
#define UI_GETCARTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GetCarta
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *GetCarta)
    {
        if (GetCarta->objectName().isEmpty())
            GetCarta->setObjectName(QStringLiteral("GetCarta"));
        GetCarta->resize(400, 300);
        lineEdit = new QLineEdit(GetCarta);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 50, 113, 22));
        label = new QLabel(GetCarta);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 131, 20));
        pushButton = new QPushButton(GetCarta);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 30, 80, 22));
        pushButton_2 = new QPushButton(GetCarta);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 70, 80, 22));

        retranslateUi(GetCarta);

        QMetaObject::connectSlotsByName(GetCarta);
    } // setupUi

    void retranslateUi(QDialog *GetCarta)
    {
        GetCarta->setWindowTitle(QApplication::translate("GetCarta", "Dialog", 0));
        label->setText(QApplication::translate("GetCarta", "Enter Card Position", 0));
        pushButton->setText(QApplication::translate("GetCarta", "Enter", 0));
        pushButton_2->setText(QApplication::translate("GetCarta", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class GetCarta: public Ui_GetCarta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCARTA_H
