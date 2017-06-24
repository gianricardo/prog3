/********************************************************************************
** Form generated from reading UI file 'n_aposta.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_N_APOSTA_H
#define UI_N_APOSTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_n_aposta
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *n_aposta)
    {
        if (n_aposta->objectName().isEmpty())
            n_aposta->setObjectName(QStringLiteral("n_aposta"));
        n_aposta->resize(315, 94);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(n_aposta->sizePolicy().hasHeightForWidth());
        n_aposta->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(n_aposta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(n_aposta);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(n_aposta);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(n_aposta);
        QObject::connect(buttonBox, SIGNAL(accepted()), n_aposta, SLOT(accept()));

        QMetaObject::connectSlotsByName(n_aposta);
    } // setupUi

    void retranslateUi(QDialog *n_aposta)
    {
        n_aposta->setWindowTitle(QApplication::translate("n_aposta", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("n_aposta", "Voc\303\252 n\303\243o tem mais saldo para apostar.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class n_aposta: public Ui_n_aposta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_N_APOSTA_H
