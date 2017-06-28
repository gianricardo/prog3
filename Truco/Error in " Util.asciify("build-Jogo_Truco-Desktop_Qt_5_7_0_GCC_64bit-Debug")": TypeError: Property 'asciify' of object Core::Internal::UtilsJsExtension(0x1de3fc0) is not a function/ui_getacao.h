/********************************************************************************
** Form generated from reading UI file 'getacao.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETACAO_H
#define UI_GETACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GetAcao
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *GetAcao)
    {
        if (GetAcao->objectName().isEmpty())
            GetAcao->setObjectName(QStringLiteral("GetAcao"));
        GetAcao->resize(674, 562);
        gridLayout = new QGridLayout(GetAcao);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(GetAcao);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(GetAcao);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_3 = new QPushButton(GetAcao);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(GetAcao);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(GetAcao);

        QMetaObject::connectSlotsByName(GetAcao);
    } // setupUi

    void retranslateUi(QDialog *GetAcao)
    {
        GetAcao->setWindowTitle(QApplication::translate("GetAcao", "Dialog", 0));
        label->setText(QApplication::translate("GetAcao", "Mao de 11: Aceitar ou Correr ?", 0));
        pushButton_3->setText(QApplication::translate("GetAcao", "Aceitar", 0));
        pushButton_4->setText(QApplication::translate("GetAcao", "Correr", 0));
    } // retranslateUi

};

namespace Ui {
    class GetAcao: public Ui_GetAcao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETACAO_H
