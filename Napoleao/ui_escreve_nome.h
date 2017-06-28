/********************************************************************************
** Form generated from reading UI file 'escreve_nome.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCREVE_NOME_H
#define UI_ESCREVE_NOME_H

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

class Ui_escreve_nome
{
public:
    QGridLayout *gridLayout;
    QLineEdit *e_insira_nome;
    QDialogButtonBox *b_insira_nome;
    QLabel *l_insira_nome;

    void setupUi(QDialog *escreve_nome)
    {
        if (escreve_nome->objectName().isEmpty())
            escreve_nome->setObjectName(QStringLiteral("escreve_nome"));
        escreve_nome->resize(189, 101);
        escreve_nome->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(escreve_nome);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        e_insira_nome = new QLineEdit(escreve_nome);
        e_insira_nome->setObjectName(QStringLiteral("e_insira_nome"));
        QFont font;
        font.setFamily(QStringLiteral("MathJax_Typewriter"));
        e_insira_nome->setFont(font);
        e_insira_nome->setReadOnly(false);

        gridLayout->addWidget(e_insira_nome, 1, 0, 1, 1);

        b_insira_nome = new QDialogButtonBox(escreve_nome);
        b_insira_nome->setObjectName(QStringLiteral("b_insira_nome"));
        b_insira_nome->setOrientation(Qt::Horizontal);
        b_insira_nome->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(b_insira_nome, 2, 0, 1, 1);

        l_insira_nome = new QLabel(escreve_nome);
        l_insira_nome->setObjectName(QStringLiteral("l_insira_nome"));
        l_insira_nome->setFont(font);

        gridLayout->addWidget(l_insira_nome, 0, 0, 1, 1);


        retranslateUi(escreve_nome);
        QObject::connect(b_insira_nome, SIGNAL(accepted()), escreve_nome, SLOT(accept()));

        QMetaObject::connectSlotsByName(escreve_nome);
    } // setupUi

    void retranslateUi(QDialog *escreve_nome)
    {
        escreve_nome->setWindowTitle(QApplication::translate("escreve_nome", "Nome", Q_NULLPTR));
        e_insira_nome->setText(QApplication::translate("escreve_nome", "Player", Q_NULLPTR));
        l_insira_nome->setText(QApplication::translate("escreve_nome", "Insira seu nome:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class escreve_nome: public Ui_escreve_nome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCREVE_NOME_H
