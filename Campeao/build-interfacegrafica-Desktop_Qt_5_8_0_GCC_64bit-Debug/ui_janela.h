/********************************************************************************
** Form generated from reading UI file 'janela.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELA_H
#define UI_JANELA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_janela
{
public:
    QGridLayout *gridLayout;
    QLineEdit *linha;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *janela)
    {
        if (janela->objectName().isEmpty())
            janela->setObjectName(QStringLiteral("janela"));
        janela->resize(168, 74);
        gridLayout = new QGridLayout(janela);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        linha = new QLineEdit(janela);
        linha->setObjectName(QStringLiteral("linha"));

        gridLayout->addWidget(linha, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(janela);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(janela);
        QObject::connect(buttonBox, SIGNAL(accepted()), janela, SLOT(accept()));

        QMetaObject::connectSlotsByName(janela);
    } // setupUi

    void retranslateUi(QDialog *janela)
    {
        janela->setWindowTitle(QApplication::translate("janela", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class janela: public Ui_janela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELA_H
