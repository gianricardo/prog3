/********************************************************************************
** Form generated from reading UI file 'name.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAME_H
#define UI_NAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Name
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Name)
    {
        if (Name->objectName().isEmpty())
            Name->setObjectName(QStringLiteral("Name"));
        Name->resize(400, 300);
        lineEdit = new QLineEdit(Name);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 110, 241, 22));
        lineEdit->setDragEnabled(false);
        pushButton = new QPushButton(Name);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 170, 80, 22));
        pushButton_2 = new QPushButton(Name);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 170, 80, 22));

        retranslateUi(Name);

        QMetaObject::connectSlotsByName(Name);
    } // setupUi

    void retranslateUi(QDialog *Name)
    {
        Name->setWindowTitle(QApplication::translate("Name", "Dialog", 0));
        pushButton->setText(QApplication::translate("Name", "4 jogadores ", 0));
        pushButton_2->setText(QApplication::translate("Name", "2 jogadores", 0));
    } // retranslateUi

};

namespace Ui {
    class Name: public Ui_Name {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAME_H
