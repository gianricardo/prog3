/********************************************************************************
** Form generated from reading UI file 'quitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITDIALOG_H
#define UI_QUITDIALOG_H

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

class Ui_quitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *quitDialog)
    {
        if (quitDialog->objectName().isEmpty())
            quitDialog->setObjectName(QStringLiteral("quitDialog"));
        quitDialog->setWindowModality(Qt::NonModal);
        quitDialog->resize(300, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quitDialog->sizePolicy().hasHeightForWidth());
        quitDialog->setSizePolicy(sizePolicy);
        quitDialog->setMinimumSize(QSize(300, 100));
        quitDialog->setMaximumSize(QSize(300, 100));
        verticalLayout = new QVBoxLayout(quitDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(quitDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        yesButton = new QPushButton(quitDialog);
        yesButton->setObjectName(QStringLiteral("yesButton"));

        horizontalLayout->addWidget(yesButton);

        noButton = new QPushButton(quitDialog);
        noButton->setObjectName(QStringLiteral("noButton"));

        horizontalLayout->addWidget(noButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(quitDialog);

        QMetaObject::connectSlotsByName(quitDialog);
    } // setupUi

    void retranslateUi(QDialog *quitDialog)
    {
        quitDialog->setWindowTitle(QApplication::translate("quitDialog", "Sair", Q_NULLPTR));
        label->setText(QApplication::translate("quitDialog", "Tem certeza que deseja sair?", Q_NULLPTR));
        yesButton->setText(QApplication::translate("quitDialog", "Sim", Q_NULLPTR));
        noButton->setText(QApplication::translate("quitDialog", "N\303\243o", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class quitDialog: public Ui_quitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITDIALOG_H
