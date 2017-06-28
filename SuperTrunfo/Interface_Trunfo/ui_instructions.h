/********************************************************************************
** Form generated from reading UI file 'instructions.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONS_H
#define UI_INSTRUCTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Instructions
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;

    void setupUi(QDialog *Instructions)
    {
        if (Instructions->objectName().isEmpty())
            Instructions->setObjectName(QStringLiteral("Instructions"));
        Instructions->resize(460, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Instructions->sizePolicy().hasHeightForWidth());
        Instructions->setSizePolicy(sizePolicy);
        Instructions->setMinimumSize(QSize(460, 300));
        verticalLayout = new QVBoxLayout(Instructions);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(Instructions);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitButton = new QPushButton(Instructions);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Instructions);

        QMetaObject::connectSlotsByName(Instructions);
    } // setupUi

    void retranslateUi(QDialog *Instructions)
    {
        Instructions->setWindowTitle(QApplication::translate("Instructions", "Instru\303\247\303\265es", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("Instructions", "- Na sua vez, escolha o atributo que considera mais forte para competir com seu oponente.\n"
"- Ganha a rodada quem tiver o atributo de maior valor.\n"
"- O vencedor da rodada recebe mant\303\251m sua carta e recebe a carta do oponente.\n"
"- As cartas recebidas v\303\243o para a \303\272ltima posi\303\247\303\243o de sua m\303\243o.\n"
"- No caso de empate, ambos jogam novamente com a pr\303\263xima carta de sua m\303\243o. O vencedor recebe as  cartas atuais junto com todas as cartas de empates anteriores. Se um jogador possuir apenas uma carta, ele continuar\303\241 com esta at\303\251 que haja desempate.\n"
"- A carta Super Trunfo perde apenas para cartas \"C\".\n"
"- O jogo acaba quando algum jogador ficar sem cartas na m\303\243o.", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Instructions", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Instructions: public Ui_Instructions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONS_H
