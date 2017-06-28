/********************************************************************************
** Form generated from reading UI file 'escreve_rodadas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCREVE_RODADAS_H
#define UI_ESCREVE_RODADAS_H

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

class Ui_escreve_rodadas
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *escreve_rodadas)
    {
        if (escreve_rodadas->objectName().isEmpty())
            escreve_rodadas->setObjectName(QStringLiteral("escreve_rodadas"));
        escreve_rodadas->resize(207, 101);
        gridLayout = new QGridLayout(escreve_rodadas);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(escreve_rodadas);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        lineEdit = new QLineEdit(escreve_rodadas);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setInputMethodHints(Qt::ImhDialableCharactersOnly|Qt::ImhFormattedNumbersOnly);
        lineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label = new QLabel(escreve_rodadas);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(escreve_rodadas);
        QObject::connect(buttonBox, SIGNAL(accepted()), escreve_rodadas, SLOT(accept()));

        QMetaObject::connectSlotsByName(escreve_rodadas);
    } // setupUi

    void retranslateUi(QDialog *escreve_rodadas)
    {
        escreve_rodadas->setWindowTitle(QApplication::translate("escreve_rodadas", "Rodadas", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("escreve_rodadas", "5", Q_NULLPTR));
        label->setText(QApplication::translate("escreve_rodadas", "Insira o numero de rodadas:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class escreve_rodadas: public Ui_escreve_rodadas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCREVE_RODADAS_H
