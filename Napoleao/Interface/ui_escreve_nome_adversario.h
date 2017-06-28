/********************************************************************************
** Form generated from reading UI file 'escreve_nome_adversario.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCREVE_NOME_ADVERSARIO_H
#define UI_ESCREVE_NOME_ADVERSARIO_H

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

class Ui_escreve_nome_adversario
{
public:
    QGridLayout *gridLayout;
    QLineEdit *e_escreve_nome_adversario;
    QDialogButtonBox *b_escreve_nome_adversario;
    QLabel *l_escreve_nome_adversario;

    void setupUi(QDialog *escreve_nome_adversario)
    {
        if (escreve_nome_adversario->objectName().isEmpty())
            escreve_nome_adversario->setObjectName(QStringLiteral("escreve_nome_adversario"));
        escreve_nome_adversario->resize(265, 101);
        gridLayout = new QGridLayout(escreve_nome_adversario);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        e_escreve_nome_adversario = new QLineEdit(escreve_nome_adversario);
        e_escreve_nome_adversario->setObjectName(QStringLiteral("e_escreve_nome_adversario"));
        QFont font;
        font.setFamily(QStringLiteral("MathJax_Typewriter"));
        e_escreve_nome_adversario->setFont(font);

        gridLayout->addWidget(e_escreve_nome_adversario, 1, 0, 1, 1);

        b_escreve_nome_adversario = new QDialogButtonBox(escreve_nome_adversario);
        b_escreve_nome_adversario->setObjectName(QStringLiteral("b_escreve_nome_adversario"));
        b_escreve_nome_adversario->setOrientation(Qt::Horizontal);
        b_escreve_nome_adversario->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(b_escreve_nome_adversario, 2, 0, 1, 1);

        l_escreve_nome_adversario = new QLabel(escreve_nome_adversario);
        l_escreve_nome_adversario->setObjectName(QStringLiteral("l_escreve_nome_adversario"));
        l_escreve_nome_adversario->setFont(font);

        gridLayout->addWidget(l_escreve_nome_adversario, 0, 0, 1, 1);


        retranslateUi(escreve_nome_adversario);
        QObject::connect(b_escreve_nome_adversario, SIGNAL(accepted()), escreve_nome_adversario, SLOT(accept()));

        QMetaObject::connectSlotsByName(escreve_nome_adversario);
    } // setupUi

    void retranslateUi(QDialog *escreve_nome_adversario)
    {
        escreve_nome_adversario->setWindowTitle(QApplication::translate("escreve_nome_adversario", "Adversario", Q_NULLPTR));
        e_escreve_nome_adversario->setText(QApplication::translate("escreve_nome_adversario", "Opponent", Q_NULLPTR));
        l_escreve_nome_adversario->setText(QApplication::translate("escreve_nome_adversario", "Insira o nome do seu adversario", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class escreve_nome_adversario: public Ui_escreve_nome_adversario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCREVE_NOME_ADVERSARIO_H
