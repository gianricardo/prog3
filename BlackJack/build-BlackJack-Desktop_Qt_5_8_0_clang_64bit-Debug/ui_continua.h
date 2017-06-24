/********************************************************************************
** Form generated from reading UI file 'continua.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTINUA_H
#define UI_CONTINUA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_continua
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *continua)
    {
        if (continua->objectName().isEmpty())
            continua->setObjectName(QStringLiteral("continua"));
        continua->resize(214, 80);
        verticalLayout = new QVBoxLayout(continua);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(continua);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(continua);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(continua);
        QObject::connect(buttonBox, SIGNAL(accepted()), continua, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), continua, SLOT(reject()));

        QMetaObject::connectSlotsByName(continua);
    } // setupUi

    void retranslateUi(QDialog *continua)
    {
        continua->setWindowTitle(QApplication::translate("continua", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("continua", "Deseja jogar uma nova partida?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class continua: public Ui_continua {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTINUA_H
