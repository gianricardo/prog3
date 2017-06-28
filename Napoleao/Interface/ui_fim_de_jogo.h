/********************************************************************************
** Form generated from reading UI file 'fim_de_jogo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIM_DE_JOGO_H
#define UI_FIM_DE_JOGO_H

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

class Ui_fim_de_jogo
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *l_end_game;

    void setupUi(QDialog *fim_de_jogo)
    {
        if (fim_de_jogo->objectName().isEmpty())
            fim_de_jogo->setObjectName(QStringLiteral("fim_de_jogo"));
        fim_de_jogo->resize(302, 202);
        fim_de_jogo->setStyleSheet(QStringLiteral("background-color:lightblue"));
        gridLayout = new QGridLayout(fim_de_jogo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(fim_de_jogo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        l_end_game = new QLabel(fim_de_jogo);
        l_end_game->setObjectName(QStringLiteral("l_end_game"));
        QFont font;
        font.setFamily(QStringLiteral("MathJax_Typewriter"));
        l_end_game->setFont(font);
        l_end_game->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(l_end_game, 0, 0, 1, 1);


        retranslateUi(fim_de_jogo);
        QObject::connect(buttonBox, SIGNAL(accepted()), fim_de_jogo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fim_de_jogo, SLOT(reject()));

        QMetaObject::connectSlotsByName(fim_de_jogo);
    } // setupUi

    void retranslateUi(QDialog *fim_de_jogo)
    {
        fim_de_jogo->setWindowTitle(QApplication::translate("fim_de_jogo", "Fim de Jogo", Q_NULLPTR));
        l_end_game->setText(QApplication::translate("fim_de_jogo", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fim_de_jogo: public Ui_fim_de_jogo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIM_DE_JOGO_H
