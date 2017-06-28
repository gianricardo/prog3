/********************************************************************************
** Form generated from reading UI file 'backdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKDIALOG_H
#define UI_BACKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_backDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *backDialog)
    {
        if (backDialog->objectName().isEmpty())
            backDialog->setObjectName(QStringLiteral("backDialog"));
        backDialog->setWindowModality(Qt::NonModal);
        backDialog->resize(300, 100);
        verticalLayout = new QVBoxLayout(backDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(backDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(backDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yesButton = new QPushButton(backDialog);
        yesButton->setObjectName(QStringLiteral("yesButton"));

        horizontalLayout->addWidget(yesButton);

        noButton = new QPushButton(backDialog);
        noButton->setObjectName(QStringLiteral("noButton"));

        horizontalLayout->addWidget(noButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(backDialog);

        QMetaObject::connectSlotsByName(backDialog);
    } // setupUi

    void retranslateUi(QDialog *backDialog)
    {
        backDialog->setWindowTitle(QApplication::translate("backDialog", "Voltar", Q_NULLPTR));
        label->setText(QApplication::translate("backDialog", "Voc\303\252 perder\303\241 seu progresso.", Q_NULLPTR));
        label_2->setText(QApplication::translate("backDialog", "Tem certeza que deseja voltar?", Q_NULLPTR));
        yesButton->setText(QApplication::translate("backDialog", "Sim", Q_NULLPTR));
        noButton->setText(QApplication::translate("backDialog", "N\303\243o", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class backDialog: public Ui_backDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKDIALOG_H
