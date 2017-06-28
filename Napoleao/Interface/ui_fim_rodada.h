/********************************************************************************
** Form generated from reading UI file 'fim_rodada.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIM_RODADA_H
#define UI_FIM_RODADA_H

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

class Ui_fim_rodada
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *l_fim_rodada;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *fim_rodada)
    {
        if (fim_rodada->objectName().isEmpty())
            fim_rodada->setObjectName(QStringLiteral("fim_rodada"));
        fim_rodada->resize(315, 112);
        fim_rodada->setAutoFillBackground(false);
        fim_rodada->setStyleSheet(QStringLiteral("background-color:lightblue"));
        verticalLayout = new QVBoxLayout(fim_rodada);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        l_fim_rodada = new QLabel(fim_rodada);
        l_fim_rodada->setObjectName(QStringLiteral("l_fim_rodada"));
        QFont font;
        font.setFamily(QStringLiteral("MathJax_Typewriter"));
        l_fim_rodada->setFont(font);
        l_fim_rodada->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(l_fim_rodada);

        buttonBox = new QDialogButtonBox(fim_rodada);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(fim_rodada);
        QObject::connect(buttonBox, SIGNAL(accepted()), fim_rodada, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fim_rodada, SLOT(reject()));

        QMetaObject::connectSlotsByName(fim_rodada);
    } // setupUi

    void retranslateUi(QDialog *fim_rodada)
    {
        fim_rodada->setWindowTitle(QApplication::translate("fim_rodada", "Fim da Rodada", Q_NULLPTR));
        l_fim_rodada->setText(QApplication::translate("fim_rodada", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fim_rodada: public Ui_fim_rodada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIM_RODADA_H
