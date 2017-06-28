/********************************************************************************
** Form generated from reading UI file 'namesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMESDIALOG_H
#define UI_NAMESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_namesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *player1Label;
    QLineEdit *player1Line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *player2Label;
    QLineEdit *player2Line;
    QPushButton *okButton;

    void setupUi(QDialog *namesDialog)
    {
        if (namesDialog->objectName().isEmpty())
            namesDialog->setObjectName(QStringLiteral("namesDialog"));
        namesDialog->resize(300, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(namesDialog->sizePolicy().hasHeightForWidth());
        namesDialog->setSizePolicy(sizePolicy);
        namesDialog->setContextMenuPolicy(Qt::ActionsContextMenu);
        verticalLayout = new QVBoxLayout(namesDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        player1Label = new QLabel(namesDialog);
        player1Label->setObjectName(QStringLiteral("player1Label"));

        horizontalLayout->addWidget(player1Label);

        player1Line = new QLineEdit(namesDialog);
        player1Line->setObjectName(QStringLiteral("player1Line"));

        horizontalLayout->addWidget(player1Line);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        player2Label = new QLabel(namesDialog);
        player2Label->setObjectName(QStringLiteral("player2Label"));

        horizontalLayout_2->addWidget(player2Label);

        player2Line = new QLineEdit(namesDialog);
        player2Line->setObjectName(QStringLiteral("player2Line"));

        horizontalLayout_2->addWidget(player2Line);


        verticalLayout->addLayout(horizontalLayout_2);

        okButton = new QPushButton(namesDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout->addWidget(okButton);


        retranslateUi(namesDialog);

        QMetaObject::connectSlotsByName(namesDialog);
    } // setupUi

    void retranslateUi(QDialog *namesDialog)
    {
        namesDialog->setWindowTitle(QApplication::translate("namesDialog", "Digite seu nome", Q_NULLPTR));
        player1Label->setText(QApplication::translate("namesDialog", "Jogador 1:", Q_NULLPTR));
        player2Label->setText(QApplication::translate("namesDialog", "Jogador 2:", Q_NULLPTR));
        okButton->setText(QApplication::translate("namesDialog", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class namesDialog: public Ui_namesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMESDIALOG_H
