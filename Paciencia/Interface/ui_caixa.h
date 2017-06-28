/********************************************************************************
** Form generated from reading UI file 'caixa.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAIXA_H
#define UI_CAIXA_H

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

class Ui_Caixa
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Caixa)
    {
        if (Caixa->objectName().isEmpty())
            Caixa->setObjectName(QStringLiteral("Caixa"));
        Caixa->resize(270, 190);
        label = new QLabel(Caixa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 171, 51));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(Caixa);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 90, 191, 32));
        pushButton = new QPushButton(Caixa);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 140, 97, 32));

        retranslateUi(Caixa);

        QMetaObject::connectSlotsByName(Caixa);
    } // setupUi

    void retranslateUi(QDialog *Caixa)
    {
        Caixa->setWindowTitle(QApplication::translate("Caixa", "Dialog", 0));
        label->setText(QApplication::translate("Caixa", "Seu nome Jogador :", 0));
        pushButton->setText(QApplication::translate("Caixa", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Caixa: public Ui_Caixa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAIXA_H
