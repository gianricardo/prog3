/********************************************************************************
** Form generated from reading UI file 'novo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVO_H
#define UI_NOVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_novo
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *novo)
    {
        if (novo->objectName().isEmpty())
            novo->setObjectName(QStringLiteral("novo"));
        novo->resize(400, 111);
        gridLayout = new QGridLayout(novo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(novo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(novo);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 2, 2);

        buttonBox = new QDialogButtonBox(novo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);


        retranslateUi(novo);
        QObject::connect(buttonBox, SIGNAL(accepted()), novo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), novo, SLOT(reject()));

        QMetaObject::connectSlotsByName(novo);
    } // setupUi

    void retranslateUi(QDialog *novo)
    {
        novo->setWindowTitle(QApplication::translate("novo", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("novo", "Insira seu nome:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("novo", "Player", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class novo: public Ui_novo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVO_H
