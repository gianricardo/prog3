/********************************************************************************
** Form generated from reading UI file 'nova_aposta.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVA_APOSTA_H
#define UI_NOVA_APOSTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_nova_aposta
{
public:
    QDialogButtonBox *buttonBox_2;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QFrame *line;
    QLabel *label;

    void setupUi(QDialog *nova_aposta)
    {
        if (nova_aposta->objectName().isEmpty())
            nova_aposta->setObjectName(QStringLiteral("nova_aposta"));
        nova_aposta->resize(325, 115);
        buttonBox_2 = new QDialogButtonBox(nova_aposta);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(240, 80, 81, 32));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Ok);
        dial = new QDial(nova_aposta);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(240, 10, 71, 71));
        dial->setMinimum(5);
        dial->setMaximum(10000);
        lcdNumber = new QLCDNumber(nova_aposta);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(12, 22, 201, 81));
        lcdNumber->setDigitCount(5);
        lcdNumber->setProperty("intValue", QVariant(5));
        line = new QFrame(nova_aposta);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(220, 10, 16, 100));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(nova_aposta);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 121, 16));

        retranslateUi(nova_aposta);
        QObject::connect(buttonBox_2, SIGNAL(accepted()), nova_aposta, SLOT(accept()));
        QObject::connect(dial, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(nova_aposta);
    } // setupUi

    void retranslateUi(QDialog *nova_aposta)
    {
        nova_aposta->setWindowTitle(QApplication::translate("nova_aposta", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("nova_aposta", "Fa\303\247a sua aposta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nova_aposta: public Ui_nova_aposta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVA_APOSTA_H
